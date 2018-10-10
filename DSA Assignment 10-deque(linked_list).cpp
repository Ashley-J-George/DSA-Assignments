//============================================================================
// Name        : D-Queue_pizza.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct node
{
	int data;
	node *prev;
	node *next;

};

class deque
{
	node *nn,*cn,*front,*rear;
public:
	deque()
	{
		front=rear=NULL;
	}
	void insert_front()
	{
		nn=new node;
		cout<<"\nEnter data = ";
		cin>>nn->data;
		nn->next=nn->prev=NULL;
		if(front==NULL)
		{
			front=nn;
			rear=nn;
		}
		else
		{
			front->prev=nn;
			nn->next=front;
			front=nn;
		}
		cout<<"\nInserted!\n";
	}
	void insert_last()
	{
		nn=new node;
		cout<<"\nEnter data = ";
		cin>>nn->data;
		nn->next=nn->prev=NULL;
		if(rear==NULL)
		{
			front=nn;
			rear=nn;
		}
		else
		{
			rear->next=nn;
			nn->prev=rear;
			rear=nn;
		}
		cout<<"\nInserted!\n";
	}
	void delete_first()
	{
		front=front->next;
		delete front->prev;
		front->prev=NULL;
		cout<<"\nDeleted!\n";
	}
	void delete_last()
	{
		rear=rear->prev;
		delete rear->next;
		rear->next=NULL;
		cout<<"\nDeleted!\n";
	}
	void display_front()
	{
		cout<<"\nThe front element = "<<front->data<<endl;
	}
	void display_rear()
	{
		cout<<"\nThe rear element = "<<rear->data<<endl;
	}
	void display()
	{
		cn=front;
		cout<<"\nThe deque = ";
		while(cn!=NULL)
		{
			cout<<cn->data<<" ";
			cn=cn->next;
		}
	}
	void reverse_display()
	{
		cn=rear;
		cout<<"\nThe deque in reverse order = ";
		while(cn!=NULL)
		{
			cout<<cn->data<<" ";
			cn=cn->prev;
		}
	}
};
int main() {
	int v;
	deque d;
	do
	{
		cout<<"\nMenu\n";
		cout<<"\n1 : Insert at first";
		cout<<"\n2 : Insert at last";
		cout<<"\n3 : Delete first element";
		cout<<"\n4 : Delete last element";
		cout<<"\n5 : Display front element";
		cout<<"\n6 : Display rear element";
		cout<<"\n7 : Display deque";
		cout<<"\n8 : Display deque in reverse order";
		cout<<"\n9 : Exit\n";
		cin>>v;
		switch(v)
		{
			case 1 :d.insert_front();
					break;
			case 2 :d.insert_last();
					break;
			case 3 :d.delete_first();
					break;
			case 4 :d.delete_last();
					break;
			case 5 :d.display_front();
					break;
			case 6 :d.display_rear();
					break;
			case 7 :d.display();
					break;
			case 8 :d.reverse_display();
					break;
			case 9 :cout<<"\nExitted\n";
					break;
			default:cout<<"\nInvalid option";
		}
	}while(v!=9);
	return 0;
}

