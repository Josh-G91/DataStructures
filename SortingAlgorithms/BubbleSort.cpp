#include <iostream>
#include <fstream>
#include "BubbleSort.h"
using namespace std;

Bubble::Bubble()
{
    course = new courseDataBub[10];
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
void Bubble::BubbleSort()
{
    bool swapped = true;
    int j = 0;
    
    
    while(swapped)
    {
        swapped = false;
        j++;
        for(int index = 0; index < 10-j; index++)
        {
            if(course[index].sectionNum > course[index + 1].sectionNum)
            {
                int temp = course[index].sectionNum;
                course[index].sectionNum = course[index+1].sectionNum;
                course[index+1].sectionNum = temp;
                swapped = true;
                
            }
        }
    }
    
    printSortedList();
    
}

void Bubble::printSortedList()
{
    
    for(int i = 0; i < 10; i++)
        cout << course[i].sectionNum << " " << course[i].courseNum << endl;
    
     delete [] course;
}
