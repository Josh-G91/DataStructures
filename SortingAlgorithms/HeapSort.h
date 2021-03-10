#ifndef HeapSort_h
#define HeapSort_h
struct courseDataHeap
{
    
    int courseNum;
    int sectionNum;
    
};
class Heap
{
    
private:
    courseDataHeap* course;
    
public:
    Heap();
    void HeapSort();
    void Heapify(int,int);
    void printSortedHeap();
    
};
#endif /* HeapSort_h */
