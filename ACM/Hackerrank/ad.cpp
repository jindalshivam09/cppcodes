#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
    unsigned long long a[40];
	int cases;
	unsigned long long ans,sum;
	cout<<fixed;
    cout<<setprecision(1);
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		ans = (sum)*(2+ (n-1)*(n-2));
		cout << (ans/(double((1<<n)))) << endl;
	return 0;  
}
