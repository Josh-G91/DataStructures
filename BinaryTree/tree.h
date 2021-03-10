 
#ifndef TREE_H
#define TREE_H

#include <iostream>

struct PersonRec;

class CTree
{

public:
	  CTree();
	  ~CTree();
	  void Add();
	  bool IsEmpty();
	  void View();

private:
	PersonRec *root;
	void AddItem (PersonRec *&PRec, char *name, int bribe);
	void DisplayTree(PersonRec *PRec);
};
#endif