#include<iostream>
#define MAX 100
using namespace std;
void swap(int *arr,int i,int j)
{
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
}
void arrange(int *arr,int n)
{
		int i=0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]<0)
			{
				swap(arr,i,j);
				i++;
			}
		}
		int pos=i;
		int neg=1;
		while(neg<pos&&arr[neg]<0&&pos<n)
		{
			swap(arr,neg,pos);
			neg+=2;
			pos++;
		}
}
main()
{
	int arr[MAX];
	int n;
	cout<<"enter the total elements to be entered: ";
	cin>>n;
	cout<<"enter elements: ";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	arrange(arr,n);
	cout<<"elements at alternate positions for negative and positive: ";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	
	while(1);
}
