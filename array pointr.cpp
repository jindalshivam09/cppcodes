#include<iostream>
#include<conio.h>
#define MAX 10
using namespace std;
class array
{
	private:
		 static const int a=1;
	    //int &c;
		int length;
		static int q;
		int *f;
		int arr[MAX];
		int fhalf,shalf;
	public:
        const static int p=9;
        array()
        {

        }
    ~array()
	{
		delete[] f;
				 //c(b)        {
			 }
			//cout<<a;
		//cout<<c;
		//a++;
		//cout<<" "<<&a<<" "<<&b;			}
	  int* alloc()
	  {
			f=new int[10];
			f[0]=4;
			return f;	  }
		void initialise()
		{
					cout<<"Enter elements of the array and press '-9' to end \n";
					int i=0,temp;
					int *start=arr;
					while(1)
					{
						cin>>temp;
						
					if(temp==-9)
						break;
						*start++=temp;
						i++;
					}
					//arr=start;
					length=i;
		}
		int firstHalf()
		{
			int *ptr=arr;
			int temp=0,n=length/2,i=0;
			while(i++<n)
			{
				temp+=*ptr++;
			}
			return fhalf=temp;
		}
		int secondHalf()
		{
			int temp=0,n=length/2,i=n;
			int *ptr=arr;
			ptr+=n;
			while(i++<length)
			{
				temp+=*ptr++;
			}
			return shalf=temp;
		}
		int diff()
		{
			return (fhalf-shalf);
		}
		void dispDiff(int dif)
		{
			cout<<"\nDiff is "<<dif;
		}
};
int array::q=9;
const int array::p;         //compulsory as ststic const are nevr stored
const int *r=&array::p;
int* loc()
{
	array q;
	int *f=q.alloc();
	return f;
	
}
main()
{
	 int a=1;
	 int e=3;
	  int *r=&e;
	 cout<<" "<<&e<<" "<<r;
	 array pointrAccess,poin;
	 poin=pointrAccess;
 	 pointrAccess.initialise();
	 int temp=pointrAccess.firstHalf();
	 cout<<temp<<endl;
	 temp=pointrAccess.secondHalf();
	 cout<<temp;
	 int dif=pointrAccess.diff();
	 pointrAccess.dispDiff(dif);
	 int *f=loc();
	 cout<<"shivam f "<<f[0];
	 
	 getch();
}
