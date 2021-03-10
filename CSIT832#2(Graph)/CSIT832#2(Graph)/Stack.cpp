#include "stack.h"
#include <stdio.h>

Stack::Stack()
{
    top = -1;
}

bool Stack::IsEmpty()
{
    if (top == -1)
        return true;
    
    else
        return false;
}
bool Stack::IsFull()
{
    if (top == 20)
        return true;
    else
        return false;
}
void Stack::Push(int node)
{
    data[++top] = node;
    
}
void Stack::Pop()
{
    
    top--;
    
}
int Stack::Top()
{
    
    return data[top];
    
    
}
