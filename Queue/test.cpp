
#include <iostream>
#include <string>
#include "cqueue.h"
using namespace std;

enum choice { BOOKED, WAITING };
const int LINES = 2;
int showMenu(void);
void addPassenger(CQueue* obj);
void deletePassenger(CQueue* obj);
void showPassengers(CQueue* obj);

int main (void)
{
CQueue qPassengers[LINES];
int x;
do{
x = showMenu();
switch (x)
{
case 1: addPassenger(qPassengers);
break;
case 2: deletePassenger(qPassengers);
break;
case 3: showPassengers(qPassengers);
break;
}
} while (x != 4);
return 0;
}

int showMenu(void)
{
int select;

cout << "Menu\n";
cout << "========\n";
cout << "1. Add Passenger\n";
cout << "2. Delete Passenger\n";
cout << "3. Show Passengers\n";
cout << "4. Exit\n";
cout << "Enter choice: ";
cin >> select;
return select;
}
// To do: implement addPassenger, deletePassenger and showPassengers

void addPassenger(CQueue* obj)
{
	Passenger QP;
	if(!obj[BOOKED].IsFull())
	{
		cout <<"Enter Name: ";
		cin>> QP.name;
		obj[BOOKED].Enqueue(QP);
		cout <<"Booking " <<QP.name <<" on flight" <<endl;
	}
	else
		{
		if(!obj[WAITING].IsFull())
		{
		cout <<"Enter Name: ";
		cin>> QP.name;
		obj[WAITING].Enqueue(QP);
		cout <<"Sorry. Plane fully booked. Adding " <<QP.name <<" to waiting list" <<endl;
		}
		else
			cout <<"Sorry. Plane and the waiting list are fully booked. Try later" <<endl;
	
	}
}
void deletePassenger(CQueue* obj)
{

	if(obj[BOOKED].IsEmpty())
	cout <<"No passengers to delete " <<endl;

	if(!obj[BOOKED].IsEmpty())
	{
		cout <<"Removing "	<<obj[BOOKED].Front().name <<" from booked passengers" <<endl;
		obj[BOOKED].Dequeue();

			if (!obj[WAITING].IsEmpty())
			{
				cout <<"Adding " <<obj[WAITING].Front().name;
				cout <<" from waiting list" <<endl;
				obj[BOOKED].Enqueue(obj[WAITING].Front());
				obj[WAITING].Dequeue();
			}
	}

	
}
void showPassengers(CQueue* obj)
{
	CQueue q1, q2;
	q1 = obj[BOOKED];
	q2 = obj[WAITING];
	if (obj[BOOKED].IsEmpty())
		cout <<"No passengers" <<endl;
	if(!q1.IsEmpty())
	{
		cout <<"Booked Passengers" <<endl <<"=================" <<endl;
		while(!q1.IsEmpty())
		{
			cout <<q1.Front().name <<endl;
			q1.Dequeue();
		}
		if(!q2.IsEmpty())
		{
			cout <<"Waiting list " <<endl << "=================" <<endl;
			while (!q2.IsEmpty())
			{
				cout <<q2.Front().name <<endl;
				q2.Dequeue();
			}
		}
		else
			cout <<"No passengers on waiting list" <<endl;
	}
}