#include<iostream>
#include<cmath>
#define MAX 1000
#define MOD 1000000007
using namespace std;
static bool isPrime[MAX]={0};
typedef long long ll;
ll calPow(int q,int n)
{
	 //c\out<<"n="<<n<<" ";
	 ll ans;
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

void sieve(int n) {
	int s=sqrt(n);
//	cout<<s;
   int a;
	for(int i=2;i<=s;i++)
	{
		 a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
     	{
			   isPrime[j]=1;
            //	cout<<j<<" ";
	    }
	}
	//cout<<"2 ";
	/*for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
	cout<<i<<" ";
    */
}

int calPrime(int n) {
	int count=1;
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
	count++;
	return count;
}

ll fact[MAX];
void factorial(int n) {
	fact[0] = 1;
	for(int i=1;i<=n;i++)
	fact[i] = (fact[i-1] * i)%MOD;
//	for(int i=0;i<=n ;i++)

}
int main() {
	sieve(MAX);
	factorial(MAX);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int count=1;
		if(n<4)
		cout << 0 << endl;
		else {
			for(int i=0;i<n/3;i++) {
			//	cout << count << endl;
			//	cout << fact[i] << " " << fact[n-3*i] << " " << fact[n-4*i] << endl;
				count = (count+((((fact[n-3*i]*calPow(fact[i],MOD-2))%MOD)*calPow(fact[n-4*i],MOD-2))%MOD)%MOD)%MOD;
		}
			//cout << count << endl;
			cout << calPrime(count) << endl;
		}
	}
	return 0;
}
