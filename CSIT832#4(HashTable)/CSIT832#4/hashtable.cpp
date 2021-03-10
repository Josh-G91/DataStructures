#include "hashtable.h"
using namespace std;

HashTable::HashTable()
{
    
    for (int index = 0; index < SIZE; index++)
        table[index] = NULL;
    
    
}
unsigned int HashTable::HashFunction(int idNumber)
{
    
    return (idNumber % SIZE);
    
    
}
void HashTable::Insert(string stuID, string stuName)
{
    Student *student = new Student;
    student->stuID = stuID;
    student->stuName = stuName;
    
    int studentID = stoi(stuID);
    int hashValue = HashFunction(studentID);
    
    while (table[hashValue] != NULL && table[hashValue]->stuID != stuID)
        hashValue = (hashValue + 1) % SIZE;
    
    
    table[hashValue] = student;
    
}
Student* HashTable::Retrieve(string tempID)
{
    int searchID = stoi(tempID);
    int hash = HashFunction(searchID);
    
    
    while (table[hash] != NULL && stoi(table[hash]->stuID) != stoi(tempID))
        hash = (hash + 1) % SIZE;
    
    if (table[hash] == NULL)
        return NULL;
    else
        return table[hash];
    
}