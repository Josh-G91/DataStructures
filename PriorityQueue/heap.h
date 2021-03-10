
#ifndef heap_h
#define heap_h
#include <string>
using namespace std;

const int MAX = 10;

struct HeapItem
{
    string schoolType;
    int numJob = 0;
    int prikey;
    HeapItem();
    HeapItem(string sType, int nJob, int hkey);
    
};
#endif /* heap_h */
