//       incomplete question
#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int t;
	int q=4;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int gp=(n-3)/3;
		int gpPos=n-(3*gp+3);
		int power=(pow(3,gp-1));
		int part=gpPos%power;
		int p=gpPos/(pow(3,gp-1));
	    int i=1;
		while(power>0)
		{
			cout<<(q+p);
			power=(pow(3,gp-1-i));
			p=gpPos/power;
			i++;
		}
	}
	int o;
	cin>>o;
}
