//---------------------------------------------------------------------------


#pragma hdrstop

#include "Expression.h"

//---------------------------------------------------------------------------
//creates stacks of operands and operators
//initializes expression with a postfix representation of initial one
Expression::Expression(AnsiString infix)
{
	operators = new Stack(0);
	operands = new Stack(0);
	expression = ParseExpression(infix);
}
Expression::~Expression()
{
	delete operators;
	delete operands;
}
//returns postfix form of expression
AnsiString Expression::GetExpression()
{
	return expression;
}
//calculates postfix expression using stack
double Expression::Calculate(TStringGrid *grid)
{
	double first, second;
	for (int i = 1; i <= expression.Length() ; i++) {
		if (expression[i] <= 'z' && expression[i] >= 'a') {
			operands->Push(StrToFloat(grid->Cells[1][expression[i] - 'a' + 1]));
		}
		else
		{
			second = operands->Pop();
			first = operands->Pop();
			if (expression[i] == '+') {
				operands->Push(first + second);
			}
			if (expression[i] == '-') {
				operands->Push(first - second);
			}
			if (expression[i] == '*') {
				operands->Push(first * second);
			}
			if (expression[i] == '/') {
				operands->Push(first / second);
			}
			if (expression[i] == '^') {
				operands->Push(pow(first, second));
			}
		}
	}
	return operands->Pop();
}
//translates from infix to postfix
AnsiString Expression::ParseExpression(AnsiString Infix)
{
	AnsiString Postfix;
	for (int i = 1; i <= Infix.Length(); i++) {
		if (Infix[i] <= 'z' && Infix[i] >= 'a') {     //if variable - skip
			Postfix += Infix[i];
		}
		//if operator - do what I could not find a proper name to
		else Postfix = DoSomething(Infix[i], Postfix);
	}
	return Postfix;
}
//a function that I could not find a proper name to
//it does what is written here
//https://habrahabr.ru/post/100869/
//for one exception
//they mistakenly defined the priority of exponentiation
//I changed it
//but it's a hardly seen correction
AnsiString Expression::DoSomething(char operation, AnsiString string)
{
	double ch;
	ch = operators->Pop();
	operators->Push(ch);
	if (operation == '~') {
		if (ch == '~') {
			return string;
		}
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
			string += (char)operators->Pop();
			string = DoSomething(operation, string);
		}
		operators->Push(operation);
	}
	if (operation == '+' || operation == '-') {
		if (ch == '~' || ch == '(') {
			operators->Push(operation);
		}
		if (ch == '+' || ch == '-' || ch == '^' || ch == '*' || ch == '/') {
			string += (char)operators->Pop();
			string = DoSomething(operation, string);
		}
	}
	if (operation == '*' || operation == '/') {
		if (ch == '+' || ch == '-' || ch == '~' || ch == '(') {
			operators->Push(operation);
		}
		if (ch == '*' || ch == '/' || ch == '^') {
			string += (char)operators->Pop();
			string = DoSomething(operation, string);
		}
	}
	if (operation == '(') {
		operators->Push(operation);
	}
	if (operation == '^') {
		operators->Push(operation);
	}
	if (operation == ')') {
		if (ch == '+' || ch == '-' || ch == '^' || ch == '*' || ch == '/') {
			string += (char)operators->Pop();
			string = DoSomething(operation, string);
		}
		if (ch == '(') {
			operators->Pop();
		}
	}
	return string;
}
#pragma package(smart_init)
