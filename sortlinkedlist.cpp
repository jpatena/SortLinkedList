// Jaron Patena
// Singly linked list w/ bubble sort algorithm
// Compile: c++ -o sort sortlinkedlist.cpp
// Execute: ./sort
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class LinkedList
{
	public:
		void BubbleSort(struct node** head_ref, int select);
		void printList(struct node *node);
		void push(struct node** head_ref, double new_data, double new_data2);
};

struct node
{
	double data;
	double data2;
	struct node* next;
};

void LinkedList::BubbleSort(struct node** head_ref, int select)
{
	struct node* head = *head_ref; // pointing to head
	int count;

	// count elements
	while(head!=NULL)
	{
		count++;
		head = head->next;
	}

	struct node* left = *head_ref;
	struct node* right = left->next;

	while(count != -1)
	{
		// if node pointer reach null, start over
		if(right==NULL || left == NULL)
		{
			left = *head_ref;
			right = left->next;
		}
		// sort by first value
		if(select == 1 && (left->data > right->data))
		{	// if left > right value, swap values
			double tempvalue = left->data;
			double tempvalue2 = left->data2;
			left->data = right->data;
			left->data2 = right->data2;
			right->data = tempvalue;
			right->data2 = tempvalue2;
		}
		// sort by second value
		if(select >= 2 && (left->data2 > right->data2))
		{	// if left > right value, swap values
			double tempvalue = left->data;
			double tempvalue2 = left->data2;
			left->data = right->data;
			left->data2 = right->data2;
			right->data = tempvalue;
			right->data2 = tempvalue2;
		}
		// increment
		left = left->next;
		right = left->next;
		count--;
	}	
}

void LinkedList::printList(struct node *node)
{
	cout << "x:\ty:" << endl;
	while(node!=NULL)
	{
		cout << node->data << "\t" << node->data2 << endl;		
		node = node->next;
	}
}

void LinkedList::push(struct node** head_ref, double new_data, double new_data2)
{
	// allocate node
	struct node* new_node =	(struct node*) malloc(sizeof(struct node));

	// put in the data
	new_node->data = new_data;
	new_node->data2 = new_data2;

	// link the old list off the new node
	new_node->next = (*head_ref); 

	// move the head to point to the new node
	(*head_ref) = new_node;
} 

int main()
{
	LinkedList xy;
	struct node* a = NULL;

	xy.push(&a, 1601.0, 138.2);
	xy.push(&a, 788.0, 38.8);
	xy.push(&a, 1890.0, 198.7);
	xy.push(&a, 199.0, 19.4);
	xy.push(&a, 331.0, 65.9);
	xy.push(&a, 291.0, 28.4);
	xy.push(&a, 272.0, 22.4);
	xy.push(&a, 132.0, 6.5);
	xy.push(&a, 699.0, 69.9);
	xy.push(&a, 186.0, 15.0);

	cout << "unSorted: \n";
	xy.printList(a);

	 // sort by first value
	xy.BubbleSort(&a, 1);
	cout << "\nSorted (x): \n";
	xy.printList(a);

	 // sort by second value
	xy.BubbleSort(&a, 2);
	cout << "\nSorted (y): \n";
	xy.printList(a);

	return 0;
}

