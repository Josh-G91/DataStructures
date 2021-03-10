#ifndef hashtable_h
#define hashtable_h
#include <string>
using namespace std;
const int SIZE = 100;
struct Student
{
    string stuID;
    string stuName;
    
};
class HashTable
{
private:
    Student *table[SIZE];
    
public:
    HashTable();
    unsigned int HashFunction(int);
    void Insert(string, string);
    Student* Retrieve(string);
    
};
#endif /* hashtable_h */
