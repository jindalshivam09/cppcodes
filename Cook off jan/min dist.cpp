#include<iostream>
using namespace std;
main()
{
	int t;
	int a,b,c;

	cin>>t;
	while(t--)
	{
       cin>>a>>b>>c;
	   if(a>b)
	   a^=b^=a^=b;
	   if(b>c)
       c^=b^=c^=b;
       cout<<(c>(a+b)?(c-a-b):0)<<endl;
	}
	 return 0;
}
