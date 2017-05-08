//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
#include <iostream>
using namespace std;
struct element
{
	double value;
	element *next;
};
class Stack
{
	private:
	element *top;
	public:
	Stack(double value);
	void Push(double value);
	double Pop();
	~Stack();
};
//---------------------------------------------------------------------------
#endif
