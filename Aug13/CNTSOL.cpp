#include<iostream>
#include<vector>
#define MAX 41
#define MOD 1000000007
using namespace std;

vector<int> power(MAX);

long long cal_pow(int q,int n,int m)
{
	long long ans;
	if(q==0 && n == 0)	return 1;
	if(q == 0 )	return 0;
	if(n==0)	return 1;
	if(n==1)	return q%m ;
	else
	{
		ans=cal_pow(q,n/2,m)%m;
		ans*=ans;
		ans%=m;
		if(n%2)
		{
				  ans*=q;
				  ans%=m;
		}
	}
	return ans;
}


void init (int m , int d , int N) {

	for(int i = 0 ; i < N ; i ++ ) {
	
		power[i] = cal_pow( i , d ,  N);
	}
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
	
		long long upper,d,m,N;
		cin >> upper >> d >> m >> N;
		
		init(m,d,N);
		
		long long sum;
		long long count = 0;
		long long ans = 0;
		for (int x1 = 0 ; x1 < N && x1 <= upper; x1++) {
							
			for(int x2 = 0 ; x2 < N && x2 <= upper;x2 ++) {
						
				for (int x3 = 0 ; x3 < N && x3 <= upper ; x3++) {
					
					sum = (power[x3]+power[x2]+power[x1])%N ; 
					
					if( sum == m ) {
				
						count = ((upper - x1)/N + 1)%MOD;
						count *= ((upper - x2)/N + 1)%MOD;		
						count %= MOD;
						count *= ((upper - x3)/N + 1)% MOD ;
						count %= MOD;
						ans += count;
						ans %= MOD;
				
//						cout << power[x1] << " " << power[x2] << " " << power[x3] << " " << sum << " " << N << endl;
						
//						cout << x1 << " " << x2 << " " << x3 << " " << count << endl;	
					}
				}
			}	
		}
		
		cout << ans << endl;
	}
}
