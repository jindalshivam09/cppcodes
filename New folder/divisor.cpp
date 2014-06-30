#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	int n=101;
	while(n--)
	{
		
		int sum=1;
		int k=n/2;
		for(int i=2;i<k;i++)
		{
			if(!(n%i))
			{
				sum+=i+(n/i);
				k=n/i;
			}
		}
		cout<<n<<" "<<sum<<endl;
	}
	getch();
	return 0;
}
