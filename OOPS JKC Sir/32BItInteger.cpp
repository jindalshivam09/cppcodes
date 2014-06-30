#include<iostream>
#define MAX 10
using namespace std;
class integer
{
	int INT[MAX];
	int n;
	public:
		integer()
		{
			for(int i=0;i<MAX;i++)
			INT[i]=0;
		}
		integer(char *arr)
		{
			int i=-1;
				while(arr[++i]!='\0')
				INT[i]=arr[i]-48;
				n=i;
				cout<<n<<endl;
		}
		integer operator *(integer mul)
		{
				int j=mul.n,temp,carry,i,k;
				integer ans;
				
				while(j--)
				{
					cout<<"j"<<j<<endl;
					i=n,k=mul.n-j-1;
					carry=0;
					//cout<<"hi"<<mul.n<<" ";
					while(i--)
					{
                      //  cout<<"hi";
                      
							temp=ans.INT[k]+carry+(INT[i])*(mul.INT[j]);
							ans.INT[k]=temp%10;
							carry=temp/10;
							//cout<<ans.INT[k]<<" ";
							k++;
					//		cout<<temp<<" ";//<<" "<<ans.INT[k]<<" ";
					}
					if(carry)
					ans.INT[k]=carry;
					else k--;
					for(int i=k;i>=0;i--)
					cout<<ans.INT[i];
					cout<<endl;

				}
				return ans;
		}
		void display()
		{
			int i;
			while(INT[i++]!='\0')
			cout<<INT[i];
		}
		
};
main()
{
	cout<<"enter numbers:";
	char str[MAX],str2[MAX];
	cin.get(str,MAX,'\n');
	cin.get();
	cin.get(str2,MAX,'\n');
	cin.get();
	integer number=str;
	integer number2=str2;

	integer ans=number*number2;
//	ans.display();
	cin.get();
}

