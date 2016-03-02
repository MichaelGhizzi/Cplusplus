#include "NodeType.h"
#include <iostream>
using namespace std;

void menu()
{
	cout << "Enter a choice!" << endl;
	cout << "A. Insert" << endl
		<< "B. Delete" << endl
		<< "C. Find" << endl
		<< "D. Print" << endl
		<< "E. Find and delete " << endl
		<< "F. Exit" << endl
		<< "G. Print backwards" << endl
		<< "H. Insert at end" << endl
		<< "I. Delete at end" << endl
		<< "J. Length of list" << endl; 
}

void insert(NodeType *&head, int value)
{
	NodeType * currentPtr;
	currentPtr = new NodeType;
	currentPtr->info = value;
	currentPtr->nextPtr = head;
	head = currentPtr;
}


void find(NodeType *head, int value)
{
	if (head != NULL)
	{
		if (head->info != value)
		{
			find(head->nextPtr, value);
		}
		else if (head->info == value)
		{
			cout << "Found: " << head->info;
		}
	}

	if (head == NULL)
	{
		cout << "Not found" << endl; 
	}
}

void remove(NodeType *&head, int value)
{
	NodeType * currentPtr;
	currentPtr = head;
	head = head->nextPtr;
	delete currentPtr;
}

void printList(NodeType *head)
{
	if (head == NULL)
	{
		return;
	}
	cout << head->info << " ";
	printList(head->nextPtr);
}

void printBackwards(NodeType *head)
{
	if (head == NULL)
	{
		return;
	}
	printBackwards(head->nextPtr);
	cout << head->info << " ";
}

void insertEnd(NodeType *& head, int value)
{
	if (head != NULL)
	{
		insertEnd(head->nextPtr, value);
	}
	else
	{
		head = new NodeType;
		head->info = value;
		head->nextPtr = NULL; 
	}
}

void deleteEnd(NodeType *& head)
{
	if (head->nextPtr != NULL)
	{
		deleteEnd(head->nextPtr);
	}
	else
	{
		delete head; 
		head = NULL; 
	}
}

void findDelete(NodeType *&head, int value)
{
	NodeType * currentPtr = NULL;

	if (head != NULL)
	{
		if (head->info == value)
		{
			currentPtr = head;
			head = currentPtr->nextPtr;
			delete currentPtr;
			currentPtr = NULL;
			return; 
		}
		else if (head->info != value)
		{
			findDelete(head->nextPtr, value);
		}
	}

	else
	{
		cout << "Not found";
	}
}

void length(NodeType * head, int &count)
{
	if (head == NULL)
	{
		cout << "Length of List: " << count;
		return;
	}
	else
	{
		count++;
		length(head->nextPtr, count);
	}
}

int main()
{
	char choice;
	NodeType * head;
	head = NULL;
	int value;
	int count = 0; 

	do {
		menu();
		cout << "Enter a choice: ";
		cin >> choice;
		switch (toupper(choice)){
		case 'A':
			cout << "Enter the value: ";
			cin >> value;
			cout << endl;
			insert(head, value);
			break;
		case 'B':
			if (head != NULL)
			{
				remove(head, value);
			}
			else
				cout << "List is Empty" << endl;
			break;
		case 'C':
			cout << "Enter the value: ";
			cin >> value;
			cout << endl;
			find(head, value);
			break;
		case 'D':
			if (head != NULL)
			{
				cout << "PRINTING:\n";
				printList(head);
			}
			else
				cout << "List is Empty" << endl;
			break;
		case 'E':
			if (head != NULL)
			{
				cout << "Enter the value: ";
				cin >> value;
				cout << endl;
				findDelete(head, value);
			}
			else
				cout << "List is Empty" << endl; 
			break;
		case 'F':
			return 0;
			break;
		case 'G':
			if (head != NULL)
			{
				cout << "PRINTING BACKWARDS:\n";
				printBackwards(head);
				cout << endl;
			}
			else
				cout << "List is Empty" << endl;
			break;
		case 'H':
			cout << "Enter the value: ";
			cin >> value;
			cout << endl;
			insertEnd(head, value);
			break;
		case 'I':
			if (head != NULL)
			{
				deleteEnd(head);
			}
			else
				cout << "List is Empty" << endl;
			break;
		case 'J':
			length(head, count);
			cout << endl; 
			break;
		}
		cout << endl;
	} while (choice = (toupper('f')));
}
