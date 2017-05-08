//---------------------------------------------------------------------------

#ifndef ExpressionH
#define ExpressionH
#include <vcl.h>
#include "Stack.h"
#include <Grids.hpp>
//---------------------------------------------------------------------------

//class to work with (transform and calculate) expressions
class Expression
{
	private:
	Stack *operators, *operands;
	AnsiString expression;
	AnsiString ParseExpression(AnsiString Infix);
	public:
	Expression(AnsiString infix);
	AnsiString GetExpression();
	AnsiString DoSomething(char operation, AnsiString string);
	double Calculate(TStringGrid *grid);
	~Expression();
};
#endif
