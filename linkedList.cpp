#include <iostream>
#include <cstddef>
using namespace std;


struct Node
{
	int data;
	Node* link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int data);
//Function to add a node at the head of the linked list

void program_start();
//Function to show program options at startup

NodePtr search(NodePtr head, int target);
//Function to search for a node in a linked list

void insert(NodePtr after_me, int the_number);
//Function to insert a new node after an existing node

void choose_option(char option, NodePtr& head);
//Function to choose an option of function to run



int main()
{
	NodePtr head = new Node;
	char option, new_option;
	option = '1';
	while (option == '1' || option == '2' || option == '3')
	{
		program_start();
		cin >> new_option;
		option = new_option;

		choose_option(option, head);
	}
	system("pause");
	return 0;
}

void program_start()
{
	cout << "Hello user!" << endl;
	cout << "Welcome to the program. ";
	cout << "Please choose one of the following functions: " << endl;
	cout << "1 for creating new node" << endl;
	cout << "2 for searching the list" << endl;
	cout << "3 for inserting a new node after an existing node" << endl;
	cout << "Any other key to exit the program" << endl;
}

void head_insert(NodePtr& head, int data)
{
	NodePtr temp_ptr;
	temp_ptr = new Node;

	temp_ptr->data = data;

	temp_ptr->link = head;
	head = temp_ptr;
}

NodePtr search(NodePtr head, int target)
{
	NodePtr here = head;

	if (here == NULL)
	{
		return NULL;
	}
	else
	{
		while (here->data != target && here->link != NULL)
		{
			here = here->link;
		}
		if (here->data == target)

		{
			cout << "Success" << endl;
			return here;
		}
		else
		{
			cout << "Node not found" << endl;
			return NULL;
		}
	}
}

void insert(NodePtr after_me, int new_number)
{
	NodePtr temp_ptr;
	temp_ptr = new Node;

	temp_ptr->data = new_number;

	temp_ptr->link = after_me->link;
	after_me->link = temp_ptr;
}

void choose_option(char option, NodePtr& head)
{
	NodePtr  after_me;
	int the_number, target, new_number;


	if (option == '1')
	{
		cout << "Insert data for your node" << endl;
		cin >> the_number;
		head_insert(head, the_number);
	}

	else if (option == '2')
	{
		cout << "Insert the value you would like to search" << endl;
		cin >> target;
		search(head, target);
	}

	else if (option == '3')
	{
		cout << "Choose a node to insert a new node after it:" << endl;
		cin >> target;
		cout << "Enter the value for new node" << endl;
		cin >> new_number;
		after_me = search(head, target);
		insert(after_me, new_number);
	}

	else
	{
		cout << "You chose the wrong option" << endl;;
	}
}

