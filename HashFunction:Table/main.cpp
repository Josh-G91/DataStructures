/*
 Joshua Gonzalez
 CSIT #832
 */


#include <iostream>
#include <string>
#include <fstream>
#include "hashtable.h"
using namespace std;

int showMenu(void);
void SearchFor(HashTable&);
int main()
{
    HashTable HashMap;
    int x;
    string stuID, stuName;
    ifstream iFile;
    iFile.open("Classes.txt", ifstream::in);
    
    if(!iFile.is_open())
        cout << "Unable to open file Classes.txt" << endl;
    
    while (!iFile.eof())
    {
        getline(iFile, stuID, '\t');
        getline(iFile, stuName);
        HashMap.Insert(stuID, stuName);
        
    }
    
    do {
        x = showMenu();
        switch (x)
        {
            case 1: SearchFor(HashMap);
                break;
                
        }
    } while (x != 2);
    
    iFile.close();
    
}
int showMenu(void)
{
    int select;
    
    cout << "Menu\n";
    cout << "========\n";
    cout << "1. Find Student by ID\n";
    cout << "2. Exit\n";
    cout << "Enter choice: ";
    cin >> select;
    return select;
}

void SearchFor(HashTable& HashMap)
{
    
    Student* retrieved;
    string searchID;
    
    cout << "Enter Student ID Number" << endl;
    cin >> searchID;
    
    retrieved = HashMap.Retrieve(searchID);
    
    if(retrieved != NULL)
        cout << "Student " << retrieved->stuName << " is in HashTable" << endl;
    else
        cout << "Student not in HashTable" << endl;
    
}
