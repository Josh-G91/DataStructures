#include <fstream>
#include <iostream>
#include "MergeSort.h"
using namespace std;
Merge::Merge()
{
    course = new courseDataMerge[10];
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

void Merge::MergeSort()
{
    
    MergeSortHelper(0, 10-1);
    
}
void Merge::MergeSortHelper(int bottom, int top)
{
    int middle;
    if(bottom < top)
    {
        middle = (bottom+top) / 2;
        MergeSortHelper(bottom, middle);
        MergeSortHelper(middle+1,top);
        MergeArray(bottom, top, middle);
    }
    
}
void Merge::MergeArray(int bottom, int top, int middle)
{
    
    courseDataMerge *tempCourses = new courseDataMerge[20];
    int i = bottom;
    int j = middle + 1;
    int k = bottom;
    
    while(i <= middle && j <= top)
    {
        if(course[i].sectionNum < course[j].sectionNum)
        {   tempCourses[k].sectionNum = course[i].sectionNum;
            k++;
            i++;
        }
        else
        {
            
            tempCourses[k].sectionNum = course[j].sectionNum;
            k++;
            j++;
            
        }
        
    }
    while(i <= middle)
    {
        tempCourses[k].sectionNum = course[i].sectionNum;
        k++;
        i++;
    }
    while(j <= top)
    {
        tempCourses[k].sectionNum = course[j].sectionNum;
        k++;
        j++;
    }
    for(i = bottom; i < k; i++)
        course[i].sectionNum = tempCourses[i].sectionNum;
    
    delete[] tempCourses;
    
    
}
void Merge::print()
{
    
    for(int i = 0; i < 10; i++)
        cout << course[i].sectionNum << " " << course[i].courseNum << endl;
    
    delete [] course;    
}
