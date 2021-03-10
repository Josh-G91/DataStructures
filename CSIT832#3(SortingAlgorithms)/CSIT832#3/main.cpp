/*
 Joshua Gonzalez
 CSIT 832
 Assignment#3 Sorting
 */

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include <iostream>
using namespace std;

char showMenu(void);
int main()
{
    
    Insertion inSort;
    Selection selSort;
    Bubble bubbleSort;
    Heap heapSort;
    Quick quickSort;
    Merge mergeSort;
    
    char x;
    do{
        x = showMenu();
        switch (x)
        {
            case 'A': selSort.SelectionSort();
                break;
            case 'B': bubbleSort.BubbleSort();
                break;
            case 'C': inSort.InsertionSort();
                break;
            case 'D': heapSort.HeapSort();
                break;
            case 'E': quickSort.startQSort();
                quickSort.print();
                break;
            case 'F': mergeSort.MergeSort();
                mergeSort.print();
                break;
                
        }
    } while (x != 'G');
    
    return 0;
    
}
char showMenu(void)
{
    char select;
    
    cout << "Menu\n";
    cout << "========\n";
    cout << "A. Selection\n";
    cout << "B. Bubble\n";
    cout << "C. Insertion\n";
    cout << "D. Heap\n";
    cout << "E. Quick\n";
    cout << "F. Merge\n";
    cout << "G. Exit\n";
    cout << "Enter choice: ";
    cin >> select;
    return select;
}





