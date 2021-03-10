
#ifndef stack_h
#define stack_h
class Stack
{
public:
    Stack();
    bool IsEmpty();
    bool IsFull();
    void Push(int);
    void Pop();
    int Top();
private:
    int top;
    int data[21];
};
#endif /* stack_h */
