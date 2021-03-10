
#include "heap.h"

HeapItem::HeapItem()
{
    prikey = 0;
    numJob = 0;
    schoolType = " ";
    
}

HeapItem::HeapItem(string sType, int nJob, int hkey)
{
    prikey = hkey;
    numJob = nJob;
    schoolType = sType;
}
