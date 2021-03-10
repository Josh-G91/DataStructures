//cstack.cpp
#include "cstack.h"


bool CStack::IsEmpty()
{
	return (top == -1);
}

bool CStack::IsFull()
{
	return (top == 20);
}

int CStack::Top()
{
	return data[top];
}

void CStack::Pop()
{
	top--;
}

void CStack::Push(string strExp, unsigned count)
{
		top++;
		data[top]=strExp[count];
}