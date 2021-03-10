
#include <fstream>
#include <iostream>
#include "InsertionSort.h"
using namespace std;

Insertion::Insertion()
{
    course = new courseDataIns[10];
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
void Insertion::InsertionSort()
{
    
    for(int next = 1; next < 10; next++)
    {
        
        int val = course[next].sectionNum;
        int position = next;
        while(position > 0 && course[position-1].sectionNum > val)
        {
            course[position].sectionNum = course[position-1].sectionNum;
            position--;
        }
        course[position].sectionNum = val;
        
    }
    printSortedCourses();
    
}
void Insertion::printSortedCourses()
{
    
    for(int i = 0; i < 10; i++)
        cout << course[i].sectionNum << " " << course[i].courseNum << endl;
    
        delete [] course;    
}
