//      O(log n) algo to calculate power


#include<iostream>
using namespace std;
#define MAX 2
#define MOD 1000000009
long long int calPow(int q,int n)
{
	 long long int ans;
	 if(n==1)	return q;
	 else{
		ans=calPow(q,n/2)%MOD;
 		ans*=ans;
		ans%=MOD;
		if(n%2)	{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}

main()
{
	int b,e;
	cin>>b >> e;
	cout << calPow(b,e);
}
