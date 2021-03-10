#include <iostream>
#include <fstream>
#include "SelectionSort.h"
using namespace std;

Selection::Selection()
{
    course = new courseDataSel[10];
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

void Selection::SelectionSort()
{
    for(int top = 10 - 1; top > 0; top--)
    {
        int currentMax = 0;
        for(int i = 1; i <= top; i++)
        {
            if(course[i].sectionNum > course[currentMax].sectionNum)
                currentMax = i;
        }
        int temp = course[top].sectionNum;
        course[top].sectionNum = course[currentMax].sectionNum;
        course[currentMax].sectionNum = temp;
        
    }
    printSortedCourses();
    
}
void Selection::printSortedCourses()
{
    
    for(int i = 0; i < 10; i++)
        cout << course[i].sectionNum << " " << course[i].courseNum << endl;
    
    delete [] course;    
}
