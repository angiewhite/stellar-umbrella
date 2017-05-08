//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form.h"
#include "Expression.h"
#include "Stack.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPostfixExpressions *PostfixExpressions;
Expression *expression;
Stack *stack = new Stack(0);
//checks if the entry was correct
//still, it's not almighty
//that's why I have an exception handler down there
bool IsCorrect(AnsiString expression)
{
	for (int i = 1; i < expression.Length(); i++) {
		if (expression[i] <= '9' && expression[i] >= '0') {
			continue;
		}
		switch(expression[i])
		{
			case '+':
			case '-':
			case '*':
			case '^':
			case '/':
			case '(':
			case ')': continue;
			default: return false;
        }
	}
	return true;
}
//---------------------------------------------------------------------------
__fastcall TPostfixExpressions::TPostfixExpressions(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//parses an infix expression and passes it to class Expression translator
//"parses" means it replaces numbers with letters of english alphabet
//as it modifies expression into formula with variables
//it can take float values
//if you want you value to be negative - stress this using (-value) syntax
void __fastcall TPostfixExpressions::TranslateClick(TObject *Sender)
{
    if (Infix->Text == "") {
		ShowMessage("You haven't made an entry.");
		return;
	}
	AnsiString text = Infix->Text;
	int operands = 0;
	if (!IsCorrect(text)) {
		 ShowMessage("Wrong entry.");
		 Infix->Text = "";
		 return;
	}
	//erases spaces
	for (int i = 1; i <= text.Length(); i++) {
		if (text[i] == ' ') {
			text = text.Delete(i,1);
			i--;
		}
	}
	//calculates operands by counting operators
	for (int i = 1; i <= text.Length(); i++) {
		if (text[i] == '+' || text[i] == '-' || text[i] == '*' ||
			text[i] == '/' || text[i] == '^') {
			operands++;
			if (text[i] == '-' && text[i - 1] == '(') {
				operands -= 1;
			}
		}
	}
	operands++;
	if (operands > 26) {
		ShowMessage("This expression has to many operands. Split it in smaller ones");
		return;
	}
	Operands->RowCount = operands + 1;
	char variable = 'a';
	int previous = 1, row = 1;
	AnsiString number;
	for (int i = 0; i < operands; i++) {
		Operands->Cells[0][i + 1] = variable;
		variable++;
	}
	//writes values of operands to stringgrid
	//"parses"
	for (int i = 1; i <= text.Length(); i++) {
		if (text[i] == '-' && text[i - 1] == '(') {
			continue;
		}
		if (text[i] == '(') {
			previous = i + 1;
		}
		if (text[i] == ')') {
			Operands->Cells[1][row] = text.SubString(previous, i - previous);
			previous = i + 1;
			row++;
			continue;
		}
		if (text[i] == '+' || text[i] == '-' || text[i] == '*' ||
			text[i] == '/' || text[i] == '^') {
			if (text[i - 1] == ')') {
				previous = i + 1;
			}
			else {
				Operands->Cells[1][row] =
					text.SubString(previous, i - previous);
				previous = i + 1;
				row++;
			}
		}
		if (i == text.Length()) {
			Operands->Cells[1][row] = text.SubString(previous, i - previous + 1);
		}
	}
	int position;
	for (int i = 1; i < Operands->RowCount; i++) {
		position = text.Pos(Operands->Cells[1][i]);
		text.Insert(Operands->Cells[0][i], position);
		text = text.Delete(position + 1, Operands->Cells[1][i].Length());
	}
	//denotes the start and the end of an expression
	text.Insert('~', 1);
	text += '~';
	expression = new Expression(text);
	Postfix->Text = expression->GetExpression();
}
//---------------------------------------------------------------------------
void __fastcall TPostfixExpressions::CalculateClick(TObject *Sender)
{
	if (Postfix->Text == "") {
		ShowMessage("You haven't made an entry.");
		return;
	}
	try
	{
		Result->Caption = expression->Calculate(Operands);
	}
	catch(...)
	{
		ShowMessage("Perhaps, you entry had incorrect form.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TPostfixExpressions::FormCreate(TObject *Sender)
{
	Operands->Cells[0][0] = "Operand";
	Operands->Cells[1][0] = "Value";
}
//---------------------------------------------------------------------------
void __fastcall TPostfixExpressions::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete expression;
}
//---------------------------------------------------------------------------



