 
#include "cqueue.h"
#include <iostream>
using namespace std;
CQueue::CQueue()
{
	rear = MAX - 1;
	front = MAX - 1;
}

bool CQueue::IsEmpty(void)
{
	return (rear==front);
}

bool CQueue::IsFull(void)
{
	return (((rear+1)%MAX) == front);
}

void CQueue::Enqueue(Passenger QP)
{
		rear = (rear + 1) % MAX;
		passengers[rear] = QP;	
}

void CQueue::Dequeue(void)
{
		front = (front + 1) % MAX;
	
}