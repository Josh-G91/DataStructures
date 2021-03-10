#include <iostream>
#include <string>
#include "cstack.h"
using namespace std;

bool isValidExpression(CStack&, string);
int main(){
	string expression;
cout <<"Enter an expression: ";
cin >>expression;

CStack stack1;

if(isValidExpression(stack1, expression))

	cout <<endl <<"It's a valid expression" <<endl;
else
	cout <<endl <<"It's NOT a valid expression" <<endl;

return 0;
}

bool isValidExpression(CStack& stackA, string strExp)
{
	if (strExp[0]=='}' || strExp[0]==')' || strExp[0]==']')
			return false;

	for(unsigned count = 0; count < strExp.size(); count++)
	{
		switch(strExp[count])
		{
		case '{':
			stackA.Push(strExp, count);
			break;
		case '(':
			stackA.Push(strExp, count);
			break;
		case '[':
			stackA.Push(strExp, count);
			break;
		case ']':
			if (stackA.Top()=='[')
				stackA.Pop();
			break;
		case ')':
			if (stackA.Top()=='(')
				stackA.Pop();
			break;
		case '}':
			if (stackA.Top()=='{')
				stackA.Pop();
			break;
		}
	}
		if (stackA.IsEmpty())
		return true;
		else 
			return false;
}