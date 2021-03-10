//cstack.h
#include <iostream>
using namespace std;
class CStack
{
private:
	int top;
	char data[21];
	bool IsFull();

public:
	CStack()
	{
		top = -1;
	}
	void Pop();
	void Push(string strExp, unsigned count);
	int Top();
	bool IsEmpty();
	
};