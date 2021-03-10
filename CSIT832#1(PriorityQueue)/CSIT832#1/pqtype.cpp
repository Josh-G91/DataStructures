


#include "pqtype.h"
#include "heap.h"
#include <iostream>


PQueue::PQueue()
{
    
    heap = new HeapItem[MAX];
    length = MAX;
    elems = 0;
    
}

PQueue::~PQueue()
{
    
    delete[] heap;
    
    
}
bool PQueue::IsEmpty()
{
    return (elems == 0);
}
bool PQueue::IsFull()
{
    return elems == MAX;
}
void PQueue::MakeEmpty()
{
    elems = 0;

}
void PQueue::ReheapUp(int root, int bottom)
{
    int parent;
    HeapItem temp;
    
    if(bottom > root)
    {
        parent = (bottom - 1) / 2;
        if(heap[parent].prikey < heap[bottom].prikey)
        {
            
            temp = heap[parent];
            heap[parent] = heap[bottom];
            heap[bottom] = temp;
            ReheapUp(root, parent);
        }
        
    }
}
void PQueue::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;
    HeapItem temp;
    
    leftChild = root*2+1;
    rightChild = root*2+2;
    if  (leftChild <= bottom)
    {
        if(leftChild == bottom)
        {
            maxChild = leftChild;
            
        }
        else
        {
            if(heap[leftChild].prikey <= heap[rightChild].prikey)
                maxChild = rightChild;
            else
                maxChild = leftChild;
            
            
        }
        if(heap[root].prikey < heap[maxChild].prikey)
        {
            temp = heap[root];
            heap[root] = heap[maxChild];
            heap[maxChild] = temp;
            ReheapDown(maxChild, bottom);
        }
    }
}


void PQueue::PrintJob(HeapItem* deqitem)
{
    
    if(IsEmpty())
        cout << "No print jobs in queue" << endl;
    else
    {
        if (deqitem->schoolType == "I" || deqitem->schoolType == "i")
            cout << "Now printing job #" << deqitem->numJob << ":" << " Instructor" << endl;
        
        else if (deqitem->schoolType == "S" || deqitem->schoolType == "s")
            cout << "Now printing job #" << deqitem->numJob << ":" << " Student" << endl;
        
        else
            cout << "Now printing job #" << deqitem->numJob << ":" << " TA" << endl;
    }
    
    
}
void PQueue::HeapSort(HeapItem* heap)
{
    HeapItem temp;
    for (int top = elems/2; top >= 0; top--)
    {
        Heapify(heap,elems,top);
    }
    for (int top = elems-1; top > 0; top--)
    {
        temp = heap[top];
        heap[top] = heap[0];
        heap[0] = temp;
        Heapify(heap,top,0);
    }
    
}
void PQueue::Heapify(HeapItem* heap, int size, int top)
{
    while (true)
    {
        int lchild = 2*top+1;
        int rchild = 2*top+2;
        
        if (lchild >= size)
            break;
        int largestChild;
        if (rchild >= size || heap[lchild].prikey < heap[rchild].prikey)
            largestChild = lchild;
        else
            largestChild = rchild;
        
        if (heap[largestChild].prikey > heap[top].prikey)
            break;
        
        HeapItem temp = heap[top];
        heap[top] = heap[largestChild];
        heap[largestChild] = temp;
        top = largestChild;
    }
}
void PQueue::showPrintJobs()
{
    
    
    if (!IsEmpty())
    {
        HeapSort(heap);
        
        for(int i=0; i<elems; i++)
        {
            if (heap[i].schoolType == "I" || heap[i].schoolType == "i")
                cout << "job " << "#" << heap[i].numJob << ": " << "Instructor " << endl;
            
            else if (heap[i].schoolType == "T" || heap[i].schoolType == "t")
                cout << "job " << "#" << heap[i].numJob << ": " << "TA" << endl;
            
            else
                cout << "job " << "#" << heap[i].numJob << ": " << "Student " << endl;
        }
        
    }
    else
        cout << "No print jobs in queue" << endl;
    
}

void PQueue::Enqueue(int count)
{
    if(!IsFull())
    {
        cout << "Instructor (I or i), TA (T or t), or Student (S or s)?" << endl;
        cin >> heap[elems].schoolType;
        
        if(heap[elems].schoolType == "I" || heap[elems].schoolType == "i")
            heap[elems].prikey = 3;
        
        else if (heap[elems].schoolType == "T" || heap[elems].schoolType == "t")
            heap[elems].prikey = 2;
        
        else if (heap[elems].schoolType == "S" || heap[elems].schoolType == "s")
            heap[elems].prikey = 1;
        
        heap[elems].numJob = count;
        
        ReheapUp(0, elems);
        elems++;
        
    }
    else
        cout << "No more room for print jobs" << endl;
}



void PQueue::Dequeue()
{
    if (!IsEmpty())
    {
        HeapItem *tempheap = new HeapItem(heap[0].schoolType, heap[0].numJob, heap[0].prikey);
        PrintJob(tempheap);
        elems--;
        heap[0] = heap[elems];
        ReheapDown(0, elems - 1);
    }
    else
        cout << "No print jobs in queue" << endl;
    
}
