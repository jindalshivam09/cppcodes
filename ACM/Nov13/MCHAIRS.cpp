#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MOD 1000000007
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


int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		cout << calPow(2,n) - 1 << endl;
	}
}
