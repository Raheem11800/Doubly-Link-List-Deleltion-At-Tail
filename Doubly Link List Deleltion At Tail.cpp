#include<iostream>
using namespace std;

class node
{
public:

	int data;
	node* next;
	node* prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}

	void insertathead(node*& head, int d)
	{
		node* temp = new node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void deleteattail(node*& tail)
	{
		node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
	}

	void display(node*& head)
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
	}
};

int main() {
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(3);

	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;

	node* head = node1;
	node* tail = node3;

	head->insertathead(head, 0);
	head->display(head);
	cout << endl;

	tail->deleteattail(tail);
	head->display(head);

	return 0;
}