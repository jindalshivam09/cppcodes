#include<iostream>
using namespace std;
main()
{
	int q;
	while(1)
    {
		int temp=0;
		 cin>>q;
		 for(int i=2;i<=q/2;i++)
		 if(!(q%i))
		 temp+=i;
		 temp+=1+q;
		 cout<<q<<"="<<temp<<endl;
	}
}
