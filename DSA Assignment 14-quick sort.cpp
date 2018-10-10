//============================================================================
// Name        : Quick_Sort.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

const int MAX=20;

class Student
{
	float perc[MAX];
	int n;
public:
	void accept();
	void display();
	void displayTop5();
	void quickSort(int start,int end);
	int getn()
	{
		return n;
	}
};

void Student::accept()
{
	cout<<"\nEnter Number of Students: ";
	cin>>n;
	cout<<"\nENter percentages of "<<n<<" students: ";
	for(int i=0;i<n;i++)
	{
		cin>>perc[i];
	}
}
void Student::display()
{
	cout<<"\nStudent List:\n";
	for(int i=0;i<n;i++)
	{
		cout<<perc[i]<<" ";
	}
}
void Student::displayTop5()
{
	int c;
	for(int i=n-1,c=0;i>=0 && c<5; i--,c++)
	{
		cout<<c+1<<" )"<<perc[i]<<"\n";
	}
}
void Student::quickSort(int start,int end)
{
	int pivot,i,j;
	float temp;
	if(start<end)
	{
		pivot=start;
		i=start+1;
		j=end;

		while(i<j)
		{

			while(perc[i]<=perc[pivot] && i<j)
				i++;
			while(perc[j]>=perc[pivot] && i<=j)
				j--;
			if(i<=j)
			{
				temp=perc[i];
				perc[i]=perc[j];
				perc[j]=temp;
			}
		}
		temp=perc[pivot];
		perc[pivot]=perc[j];
		perc[j]=temp;

		quickSort(start,j-1);
		quickSort(j+1,end);
	}
}
int main()
{
	Student s;
	int choice,num;
	s.accept();
	cout<<"\nBefore Sorting: ";
	s.display();
	cout<<"\nAfter Sorting: ";
	num=s.getn();
	s.quickSort(0,num-1);
	s.display();
	return 0;
}

