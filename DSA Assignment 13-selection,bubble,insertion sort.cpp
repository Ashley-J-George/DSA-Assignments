//============================================================================
// Name        : Sort.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class sort
{
	int n;
	float a[40];
public:
	void bubble_sort();
	void display();
	void accept();
	void insertion_sort();
	void selection_sort();

};

void sort::bubble_sort()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			swap(a[j],a[j+1]);

		}
	}
}

void sort::display()
{
	cout<<"\n The elements are = ";
	for(int i=0;i<n;i++)
		{
			cout<<" "<<a[i];
		}
}

void sort::accept()
{	cout<<"\nEnter the no. of elements=";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"Enter element "<<i+1<<" =";
	cin>>a[i];
	}
}

void sort::insertion_sort()
{
	int i,j;
	float small;
	for(i=1;i<n;i++)
	{
		small=a[i];
		for(j=i-1;j>=0 && small<a[j];j--)
		{
			if(small<a[j])
			a[j+1]=a[j];
		}
		a[j+1]=small;
	}
}

void sort::selection_sort()
{
	int i,j;
	int min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		swap(a[min],a[i]);
	}
}

void swap(float &a,float &b)
{
	float t;
	t=a;
	a=b;
	b=t;
}

int main()
{
	sort o1,o2,o3;
	int v;
	cout<<"       SORTING";
	do
	{
		cout<<"\n\nMenu\n";
		cout<<"\n1 : Bubble sort";
		cout<<"\n2 : Insertion sort";
		cout<<"\n3 : Selection sort";
		cout<<"\n4 : Exit\n";
		cin>>v;

		switch(v)
		{
		case 1:o1.accept();
			   o1.display();
			   o1.bubble_sort();
			   cout<<"\n After sorting using bubble sort";
			   o1.display();
			   break;

		case 2:o2.accept();
			   o2.display();
			   o2.insertion_sort();
			   cout<<"\n After sorting using insertion sort";
			   o2.display();
			   break;

		case 3:o3.accept();
		       o3.display();
		       o3.selection_sort();
		       cout<<"\n After sorting using selection sort";
		       o3.display();
		       break;

		case 4:cout<<"\nExitted!";
			   break;

		default:cout<<"\nInvalid option";

		}

	}while(v!=4);

	return 0;
}


