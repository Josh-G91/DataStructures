
#ifndef pqtype_h
#define pqtype_h

#include "heap.h"

class PQueue
{
private:
    int length;
    int elems;
    HeapItem *heap;
    
public:
    PQueue();
    ~PQueue();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void ReheapDown(int, int);
    void ReheapUp(int, int);
    void Enqueue(int);
    void Dequeue();
    void showPrintJobs();
    void PrintJob(HeapItem*);
    void HeapSort(HeapItem*);
    void Heapify(HeapItem* ,int, int);
    
    
};


#endif /* pqtype_h */
