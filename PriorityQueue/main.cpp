/*
 Joshua Gonzalez
 CSIT 832
 Assignment #1
 Priority Queue/Heap
 */



#include <iostream>
#include "pqtype.h"
#include "heap.h"

int showMenu(void);
int main()
{
    int jobCounter = 0;
    PQueue *priqueue = new PQueue[MAX];
    int x;
    
    do {
        x = showMenu();
        switch (x)
        {
            case 1:
                if(x == 1)jobCounter++;
                priqueue->Enqueue(jobCounter);
                break;
            case 2: priqueue->Dequeue();
                break;
            case 3: priqueue->showPrintJobs();
                break;
        }
    } while (x != 4);
    return 0;
    
    
    
}

int showMenu()
{
    int select;
    
    cout << "Menu\n";
    cout << "========\n";
    cout << "1. Add Job\n";
    cout << "2. Print Job\n";
    cout << "3. View Job\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> select;
    return select;
}


