#include <iostream>
#include <fstream>
#include "HeapSort.h"
using namespace std;

Heap::Heap()
{
    course = new courseDataHeap[10];
    ifstream inFile;
    int coursenum;
    int section;
    int i = 0;
    
    inFile.open("Classes.txt", ifstream::in);
    
    if(!inFile.is_open())
        cout << "Unable to open file GraphData.txt" << endl;
    
    else
    {
        while(!inFile.eof())
        {
            
            inFile >> coursenum;
            
            course[i].courseNum = coursenum;
            inFile >> section;
            course[i].sectionNum = section;
            i++;
        }
        
    }
    inFile.close();
}

void Heap::HeapSort()
{
    for(int top = 10/2; top >= 0; top--)
        Heapify(10, top);
    for(int top = 10 - 1; top > 0; top--)
    {
        int temp = course[top].sectionNum;
        course[top].sectionNum = course[0].sectionNum;
        course[0].sectionNum = temp;
        Heapify(top, 0);
    }
    printSortedHeap();
    
}
void Heap::Heapify(int newSize, int top)
{
    
    while(true)
    {
        
        int leftChild = 2*top+1;
        int rightChild = 2*top+2;
        int biggestChild;
        
        if(leftChild >= newSize)
            break;
        
        if(rightChild >= newSize || course[leftChild].sectionNum >= course[rightChild].sectionNum)
            biggestChild = leftChild;
        
        else
            biggestChild = rightChild;
        
        if(course[biggestChild].sectionNum <= course[top].sectionNum)
            break;
        
        int temp = course[top].sectionNum;
        course[top].sectionNum = course[biggestChild].sectionNum;
        course[biggestChild].sectionNum = temp;
        top = biggestChild;
        
    }
    
}
void Heap::printSortedHeap()
{
    
    for(int i = 0; i < 10; i++)
        cout << course[i].sectionNum << " " << course[i].courseNum << endl;
    
        delete [] course;    
}
