
#ifndef QuickSort_h
#define QuickSort_h
struct courseDataQuick
{
    
    int courseNum;
    int sectionNum;
    
};
class Quick
{
    
private:
    courseDataQuick* course;
    
public:
    Quick();
    void startQSort();
    void QuickSort(int, int);
    int Partition(int, int);
    void print();
    
};
#endif /* QuickSort_h */
