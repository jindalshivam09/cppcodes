#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

//--------------user defined data type---------------------------------------

class STRING
{
		char str[MAX];
		public:
			STRING()
			{}
			STRING(char *arr)
			{
				strcpy(str,arr);
			}
			void init(char *arr)
			{
				strcpy(str,arr);
			}
			bool operator <(STRING ob)
			{
				cout<<"user defined class overloaded < ";
				return true;
			}
			friend ostream& operator <<(ostream &cout,STRING &s);
};
ostream& operator <<(ostream &cout,STRING &s)
{
		cout<<s.str;
}

//------------struct for linked list------------------------------------------
template <class type>
struct list
{
		type data;
		list *link;
};

///////////////////////////////////////////////////////////////////////////////
//------------------------template LINKEDLIST---------------------------------

template <class type>
class linkedList
{
		list<type> *head;
		public:
			linkedList()
			{
					head=NULL;
			}
			void enterData(type d)
			{
					list<type> *newLink=new list<type>;
					newLink->data=d;
					newLink->link=NULL;
					if(!head)
					head=newLink;
					else
					{
						list<type> *temp=head;
						while(temp->link)
						temp=temp->link;
						temp->link=newLink;
					}
			}
			void check(linkedList ob)
			{
				list<type> *temp=ob.head;
				list<type> *temp2=head;
				if(temp->data<temp2->data)
				cout<<"less..";
				else
				cout<<"more..";
			}
			void display()
			{
                		list<type> *temp=head;
						while(temp)
						{
							cout<<temp->data<<" ";
							temp=temp->link;
						}

			}
};

///////////////////////////////////////////////////////////////////////////////

main()
{
		linkedList<int> INT;
		for(int i=0;i<5;i++)
		INT.enterData(i+1);
		INT.display();
		cout<<endl;
		
	//----------template for user defined types--------------------
	
	    char a[MAX]="shivam";
	    STRING s=a;
	    STRING str[5];
		char arr[MAX];
		for(int i=0;i<5;i++)
		{
			cin>>arr;
			str[i].init(arr);
		}
		linkedList<STRING> S;
		linkedList<STRING> STR;
		for(int i=0;i<5;i++)
		{
			STR.enterData(str[i]);
		}
		S.enterData(s);
		STR.display();
		STR.check(S);


		while(1);
}
