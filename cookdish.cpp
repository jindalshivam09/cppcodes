#include<iostream>
using namespace std;
#define MOD 1000000007

long long int calPow(int q,int n)
{
	 //c\out<<"n="<<n<<" ";
	 long long int ans;
	 if(n==1)
	 {
          //   a*=q;
		//	cout<<n<<" "<<ans<<" "<<q<<" ";
			return q;
     }
	else
	{
		ans=calPow(q,n/2)%MOD;
	//	cout<<"ret ans= "<<ans<<" ";
		ans*=ans;
		ans%=MOD;
		if(n%2)
		{
				  ans*=q;
				  ans%=MOD;
		}
//		cout<<n<<" "<<ans<<" "<<q<<" ";
	}
	return ans;
}


main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		if(n==1)
		cout << k*(k-1) << endl;
		else {
			long long ans = (k*(k-1))%MOD;
			long long ans2 = calPow(k*k - 3*k +3,n-1);
			cout << (ans*ans2)%MOD << endl;
		}
		
	}
}
