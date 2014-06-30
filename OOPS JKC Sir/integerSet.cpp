#include<iostream>
#include<conio.h>
using namespace std;
class integerSet
{
	 bool array[100];
	 public:
			integerSet()
			{
				  for(int i=0;i<100;i++)
				  array[i]=0;
			}
			integerSet(int *arr,int n)
			{
                  for(int i=0;i<100;i++)
				  array[i]=0;
				  for(int i=0;i<n;i++)
				  array[arr[i]-1]=1;
				  
			}
			integerSet unionOfSet(integerSet q )
			{
				   integerSet uni;
					for(int i=0;i<100;i++)
					{
							if(array[i]||q.array[i])
							uni.array[i]=1;
							else
							uni.array[i]=0;

					}
					return uni;

			}
			integerSet intersectionOfSet(integerSet q )
			{
				   integerSet uni;
					for(int i=0;i<100;i++)
					{
							if(array[i]&&q.array[i])
							uni.array[i]=1;
							else
							uni.array[i]=0;

					}
					return uni;

			}
			void insertElement(int n)
			{
					array[n-1]=1;
			}
			void printSet()
			{
				cout<<endl<<"Sets"<<endl;
				bool flag=0;
				for(int i=0;i<100;i++)
				if(array[i])
				{
					cout<<i+1<<" ";
					flag=1;
				}
				if(!flag)
				cout<<"---";
				
			}
			bool isEqualTo(integerSet q)
			{
					bool flag=0;
					for(int i=0;i<100;i++)
					{
						if(array[i]!=q.array[i])
						{
							  flag=1;
							  break;
						}
					}
					if(flag)
					return false;
					return true;
			}

};
main()
{
		int arr[100];
		int n;
		cout<<"enter total number of elements: ";
		cin>>n;
		cout<<"enter elements: ";
		for(int i=0;i<n;i++)
		cin>>arr[i];
		integerSet q(arr,n);
        cout<<"enter total number of elements: ";
		cin>>n;
		cout<<"enter elements: ";
		for(int i=0;i<n;i++)
		cin>>arr[i];
        integerSet a(arr,n);

		integerSet w=q.unionOfSet(a);
		cout<<"\nsets after union:";
		w.printSet();
		w=q.intersectionOfSet(a);
		cout<<"\nsets after intersection:";
		w.printSet();
		int m;
		cout<<"\nenter element to insert: ";
		cin>>m;
		w.insertElement(m);
		cout<<"\nsets after insertion:";
		w.printSet();
		bool equal=q.isEqualTo(a);
		cout<<"\nenter sets are ";
		if(equal)
		cout<<"equal";
		else
		cout<<"not equal";
		getch();
}
