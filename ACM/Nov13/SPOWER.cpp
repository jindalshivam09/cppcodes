#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<unsigned long long> power(25,1);

#define MOD 1000000007
#define MAX 100000000000000000000

void preprocess() {
	
	power[0] = 1;
	power[1] = 2;o
	power[2] = 1024;
	int j=3;
	
	for(unsigned long long i=3;i<=MAX;i*=10) {
		
		for(int k=0;k<10;k++)  {
			
			power[j] = (power[j]*power[j-1])%MOD;
		}
//		cout << power[j] << " ";
		j++;
	}
}

int main() {
	
	preprocess();
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		vector<bool> bits(20);
		int i=1;
		
		while(n) {
			
			if(n&1) bits[i] = true;	
			i++;
			n = n >> 1;
		}
		long long ans = 1;
		for(int i=20;i>0;i--) {
			
			if(bits[i]&1) {
				
				ans = (ans * power[i]) % MOD;
			}
		}
		
		cout << (ans*ans)%MOD << endl;
 	}
}
