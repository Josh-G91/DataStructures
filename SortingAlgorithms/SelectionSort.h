#ifndef SelectionSort_h
#define SelectionSort_h
struct courseDataSel
{
    
    int courseNum;
    int sectionNum;
    
};
class Selection
{
private:
    courseDataSel* course;
    
public:
    Selection();
    void SelectionSort();
    void printSortedCourses();
    
};
#endif /* SelectionSort_h */
