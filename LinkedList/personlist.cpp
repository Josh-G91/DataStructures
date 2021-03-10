#include "personlist.h"
#include <iostream>
#include <string>
using namespace std;

struct PersonRec
{
	char name[20];
	int bribe;
	PersonRec* link;
};

PersonList::PersonList()
{
	head = NULL;
}

PersonList::~PersonList()
{
	PersonRec *temp, *now;
	now = head;
	temp = head;
	while(now!=NULL)
	{
		now = now->link;
		delete temp;
		temp = now;
	}
}

void PersonList::ViewList()
{
	PersonRec *PRec = new PersonRec;
	unsigned i = 1;
	if (IsEmpty())
		cout <<endl <<"List is empty" <<endl;
	else
	{
		PRec = head;
		cout <<" # Name Contribution " <<endl <<"=======================================" <<endl;
		
		while(PRec!=NULL)
		{
			cout <<i <<" " <<PRec->name <<" $" <<PRec->bribe <<endl;
			i++;
			PRec = PRec->link;
		}
	}
}

void PersonList::AddToList()
{
	char aname[20];
	int abribe;
	cout <<"Enter the person's name: ";
	cin.getline(aname, 20);
	cout <<"Enter the person's contribution: ";
	cin >>abribe;
	
	PersonRec *PRec = new PersonRec;
	for(unsigned i = 0; i < 20; i++)
		PRec->name[i]=aname[i];
	PRec->bribe=abribe;
	PRec->link = NULL;	
	
	PersonRec *current;
	PersonRec *prev;
	
	current = head;
	prev = NULL;
	if(IsEmpty())
		head = PRec;
	else if (current->bribe < PRec->bribe)
		InsertBefore(current, PRec);
	 else if ((current->bribe > PRec->bribe && current->link==NULL))
	{
		PersonRec *p;
		p = head;
		while(p->link!=NULL)
			p=p->link;
		p->link = PRec;
	}

	else //if (current->bribe > PRec->bribe && current->link!=NULL) 
	{
	while(current->link!=NULL && current->bribe >= PRec->bribe)
	{
		prev = current;
		current = current->link;
	
		if(current->bribe < PRec->bribe)
		{
			PRec->link = current;
			prev->link = PRec;
			break;
			
		}
		
	}
	PersonRec *p;
		p = head;
		while(p->link!=NULL)
			p=p->link;
		p->link = PRec;
	 }
	



}


bool PersonList::EndOfList(PersonRec *currptr)
{
	
	return (currptr->link == NULL);
}

bool PersonList::IsEmpty()
{
	return (head==NULL);
}


void PersonList::InsertBefore(PersonRec *currPtr, PersonRec *newRec)
{

	PersonRec *current;

		current = head;
		while (current->link != currPtr && current->bribe > newRec->bribe)
			current = current->link;
		
		head = newRec;	//newRec is the head
		newRec->link = currPtr; //newRec->link (also probably head->link) is equal to the previous head														
		
							//head->link = current->link;	//newRec's link is now equal to current->link (not sure if this is even necessary... just tested. It's not)
		
	
}//have AddToList call InsertBefore and pass to InsertBefore two parameters, the PersonRec node to be inserted in the list, 
//and a PersonRec* pointing to where in the list the new node will be inserted before or after (as the case may be). 


