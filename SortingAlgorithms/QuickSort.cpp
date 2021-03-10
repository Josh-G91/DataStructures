#include <iostream>
#include <fstream>
#include "QuickSort.h"
using namespace std;


Quick::Quick()
{
    course = new courseDataQuick[10];
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
    
    startQSort();
}

void Quick::startQSort()
{
    int l = 0;
    int r = 9;
    QuickSort(l, r);
    
}
int Quick::Partition(int left, int right)
{
    int i = left;
    int j = right;
    int temp;
    int pivot = course[(left + right)/2].sectionNum;
    
    while(i <= j)
    {
        while(course[i].sectionNum < pivot)
            i++;
        while(course[j].sectionNum > pivot)
            j--;
        if(i <= j)
        {
            
            temp = course[i].sectionNum;
            course[i].sectionNum = course[j].sectionNum;
            course[j].sectionNum = temp;
            i++;
            j--;
            
        }
    };
    
    return i;
    
}
void Quick::QuickSort(int left, int right)
{
    
    int index = Partition(left, right);
    
    if(left < index - 1)
        QuickSort(left, index-1);
    
    if(index < right)
        QuickSort(index, right);
    
}
void Quick::print()
{
    
    for(int i = 0; i < 10; i++)
        cout << course[i].sectionNum << " " << course[i].courseNum << endl;
    
     delete [] course;    
}
