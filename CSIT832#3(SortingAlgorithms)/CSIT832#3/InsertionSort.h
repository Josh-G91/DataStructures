
#ifndef InsertionSort_h
#define InsertionSort_h
struct courseDataIns
{
    
    int courseNum;
    int sectionNum;
    
};
class Insertion
{
private:
    courseDataIns* course;
public:
    Insertion();
    void InsertionSort();
    void printSortedCourses();
    
};
#endif /* InsertionSort_h */
