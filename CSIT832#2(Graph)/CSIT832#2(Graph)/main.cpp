//Joshua Gonzalez
//CSIT 832
//Assignment #2

#include <iostream>
#include "Graph.h"
using namespace std;

int displayMenu (void);
bool ReturnToMenu ();
int main()
{
    Graph graph;
    graph.createGraph();
    
    bool toContinue = false;
    
    
    int num;
    do{
        num = displayMenu();
        if (num == 1)
        {   graph.SelectDepCity();
            toContinue = ReturnToMenu();
        }
        else if (num == 2)
        {
            toContinue = false;
            return 0;
        }
    }while(toContinue);
    
    
}
int displayMenu (void)
{
    int choice;
    cout << "\nMenu\n";
    cout << "==============================\n\n";
    cout << "1. Choose Departure City\n";
    cout << "2. Exit program\n\n";
    cout << "Please enter choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}
bool ReturnToMenu()
{
    
    bool allGood = true;
    char userInput;
    cout << "Press any key to return to menu.\n";
    cin >> userInput;
    cin.get();
    return allGood;
    
}