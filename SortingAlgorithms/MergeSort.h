
#ifndef MergeSort_h
#define MergeSort_h
struct courseDataMerge
{
    
    int courseNum;
    int sectionNum;
    
};
class Merge
{
    
private:
    courseDataMerge* course;
    
public:
    Merge();
    void MergeSort();
    void MergeSortHelper(int, int);
    void MergeArray(int, int, int);
    void print();
    
};
#endif /* MergeSort_h */
