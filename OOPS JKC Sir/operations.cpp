#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstring>
#define MAX 100
#define STR 10
using namespace std;
int operationDiv(int *arr,int a,int b)
{
		int count=0;
		for(int i=a;i<=b;i++)
	    if(!(arr[i]%3))
	    count++;
	    return count;
}
void displayArr(int *arr,int n)
{
	cout<<"Array: ";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
void operationOp(int *arr,int a,int b)
{
	   for(int i=a;i<=b;i++)
	   arr[i]++;
}

main()
{
	int n;
	cout<<"Enter total numbers of elements: ";
	cin>>n;
	int arr[MAX]={0};

	cout<<"OPERATIONS: "<<endl;
	cout<<"'A op B' -> increase the numbers between indices A and B by 1"<<endl;
	cout<<"'A div B'-> answer how many numbers between indices A and B are divisible by 3"<<endl<<endl;

	char operation[STR],op[5];
	int A,B;
	char choice;
	do
	{
        cout<<"Enter operation you want to perform: ";
		cin.get();
		cin.get(operation,10,'\n');
		cin.get();
		sscanf(operation,"%d %s %d",&A,op,&B);

		if(A<0||A>n-1||B<0||B>n-1)
		{
			cerr<<"Invalid indices";
    	}
   		else
		{
       	 //------perform operation---------------

			if(!strcmp(op,"div"))
			{
				cout<<endl<<"Numbers divisible by 3 between A n B are "<<operationDiv(arr,A,B)<<endl;
				displayArr(arr,n);
			}
			else if(!strcmp(op,"op"))
			{
				operationOp(arr,A,B);
				displayArr(arr,n);
			}
			else
			cerr<<"Invalid Operation";
		}
		cout<<"\nPress y to continue or n to exit: ";
	    cin>>choice;
	    
	}while(choice=='y'||choice=='Y');
	getchar();
}
