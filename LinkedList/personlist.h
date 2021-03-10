#ifndef PERSON_H
#define PERSON_H

struct PersonRec;

class PersonList {

public:
PersonList();
~PersonList();
void ViewList();
void AddToList ();

private:
PersonRec* head;
bool IsEmpty();
void PersonList::InsertBefore(PersonRec *currPtr, PersonRec *newRec);
bool EndOfList(PersonRec *currptr);

/*
insert here other private member functions as you
see the need for them. However, you cannot add
any additional member variables or public
member functions than the four listed above
*/
};
#endif