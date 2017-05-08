//---------------------------------------------------------------------------


#pragma hdrstop

#include "Stack.h"
Stack::Stack(double value)
{
	top = new element;
	top->value = value;
	top->next = NULL;
}
void Stack::Push(double value)
{
	element *newElement = new element;
	newElement->value = value;
	newElement->next = top;
	top = newElement;
}
double Stack::Pop()
{
	element *outElement = top;
	top = top->next;
	double value = outElement->value;
	delete outElement;
	return value;
}
Stack::~Stack()
{
	element *help;
	while(top != NULL)
	{
		help = top;
		top = top->next;
		delete help;
    }
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
