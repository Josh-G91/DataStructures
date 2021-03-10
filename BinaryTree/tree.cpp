 
#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

struct PersonRec
{
	char name[20]; 
	int bribe;
	PersonRec* lChild; //Pointer to next leaf to the left (or to NULL if no leaf to the left)
	PersonRec* rChild; //Pointer to next leaf to the right (or to NULL if no leaf to the right)
	PersonRec (char* aname, int abribe, PersonRec *lChild, PersonRec* rChild);
};

PersonRec::PersonRec(char* aname, int abribe, PersonRec *leftC, PersonRec *rightC)
{

	for (unsigned i = 0; i <40; i++)
		name[i] = aname[i]; 
	bribe = abribe;
	lChild = leftC;
	rChild = rightC;
}
CTree::CTree()
{
	root = NULL;
}

CTree::~CTree()
{
	delete root;
}

//struct CTree::PersonRec(char *name, int bribe, PersonRec *lChild, PersonRec *rChild)

bool CTree::IsEmpty()
{
	return root == NULL;
}

void CTree::Add()
{
char aName[40];
int aBribe;
cout << "\nEnter the person's name: ";
cin >> aName; // assumes no embedded spaces in name
cout<< "\nEnter the person's contribution: ";
cin >> aBribe;

AddItem(root, aName, aBribe);
}

void CTree::AddItem(PersonRec *&PRec, char* name, int bribe)
{
	if(PRec == NULL)
		PRec = new PersonRec(name, bribe, NULL, NULL);

	else if(bribe > PRec->bribe)
		AddItem(PRec->rChild, name, bribe);

	else if (bribe < PRec->bribe)
		AddItem(PRec->lChild, name, bribe);

	else
		cout <<endl <<"Sorry, this bribe amount has already been paid. First come first serve!" <<endl;
}

void CTree::DisplayTree(PersonRec *PRec)
{
	
	

	if(PRec == NULL)
		return;

	DisplayTree(PRec->rChild); //goes all the way to the right until it hits NULL
	static int count = 1; //You said it was ok if we didn't include the counter, but I left it in anyway even though it doesn't reset to 1 everytime you select to view the waiting list
	cout <<count <<" " <<PRec->name <<" " <<"$" <<PRec->bribe <<endl;
	count++;
	DisplayTree(PRec->lChild); // prints from the right to the left

	
}

void CTree::View()
{
	if(IsEmpty())
		cout <<endl <<"List is empty" <<endl;

	else
	{
		cout <<endl <<"New Contribution " <<endl <<"======================" <<endl <<endl;
		DisplayTree(root);
	}

}