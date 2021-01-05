#include<iostream>
#include"Singly_Linked_List.h"
using namespace std;

Singly_linked_list*Create_linked_list(int n)
{
	int number = 0;
	Singly_linked_list*firstPtr=NULL,*tempPtr,*lastPtr=NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the number: " << endl;
		cin >> number;
		tempPtr = new Singly_linked_list;
		tempPtr->SetNum(number);
		if (i == 0)
		{
			firstPtr = tempPtr;
			lastPtr = tempPtr;
		}
		else
		{
			lastPtr->SetNext(tempPtr);
			lastPtr = tempPtr;
		}
	}
	return firstPtr;
}

void Print_Singly_Linked_List(Singly_linked_list*ptr)
{
	while (ptr != NULL && ptr->GetNum()!=NULL)
	{
		cout << "[" << ptr->GetNum() <<" "<<ptr<<" "<< "]->";
		ptr = ptr->GetNext();
	}
	cout << "Null" << endl;
	cout << endl;
}

void Compare(Singly_linked_list*firstPtr)
{
	int temp = 0;
	Singly_linked_list *headPtr = NULL, *tempPtr = NULL;
	headPtr = firstPtr;

	for (;firstPtr != NULL; firstPtr = firstPtr->GetNext() )
	{
		for (tempPtr = firstPtr->GetNext();tempPtr != NULL; tempPtr = tempPtr->GetNext())
		{
			if (firstPtr->GetNum() > tempPtr->GetNum())
			{
				temp = firstPtr->GetNum();
				firstPtr->SetNum(tempPtr->GetNum());
				tempPtr->SetNum(temp);
			}			
		}		
	}
	Print_Singly_Linked_List(headPtr);
}  

int main()
{
	int number = 0;
	Singly_linked_list*firstPtr = NULL;
	Singly_linked_list*currPtr = NULL;
	cout << "Enter the number of elements: " << endl;
	cin >> number;
	firstPtr = Create_linked_list(number);
	cout << "Address: " << firstPtr << endl;
	Print_Singly_Linked_List(firstPtr);
	cout << "Address: " <<firstPtr<< endl;
    Compare(firstPtr);
}