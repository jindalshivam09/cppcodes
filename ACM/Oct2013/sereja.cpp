#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

long long pow(int n,int q) {

    if(q==1) return n;

    if(q==0) return 1;

    long long ans = pow(n,q/2);

    if(q%2) return ((ans*ans)%MOD*n)%MOD;
        return (ans*ans)%MOD;

}

int main() {

    int t;
    cin >> t;
    while(t--) {

        long long n,m,q,k;
        cin >> n >> m >> q >> k;


		if(n==1)
				cout << 0 << endl;
				
		else if( q > m )
			cout << 0 << endl;
        
		else  {
        
        
        	long long temp1 = pow(q+1,n);
        	long long temp2 = (2*pow(q,n))%MOD;
        	long long temp3 = pow(q-1,n);
        	cout <<  ((m - q)*((MOD+temp1 + temp3 - temp2)%MOD))%MOD  << endl;
		}

    }
}

