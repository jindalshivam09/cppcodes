#include<iostream>
#include<cmath>
using namespace std;

#define MOD 1000000007

int main() {

	int t;
	cin >> t;
	while(t--) {

		long long l,r;
		cin >> l >> r;
		long long ans = 0;
		
		int templ = l;
		int tempr = r;
		int countl = 0 , countr = 0;
		while(templ) {

			templ /= 10;
			countl++;
		}
		
		while(tempr) {

			tempr /= 10;
			countr++;
		}
		
		if(l == r) {


			cout << (l * countl)%MOD << endl;
			continue;
		}
		
		if(countl == countr) {

			if((r+l)%2)
			ans += ((((r-l+1)/2)%MOD)*((r+l)%MOD))%MOD;
			else
			ans += ((((r-l+1))%MOD)*(((r+l)/2)%MOD))%MOD;
			ans %= MOD;
			ans = (ans*countl)%MOD;

		cout << ans << endl;
		}
		else {

			long long ten = 1;
			while(countl != countr) {
				ten = 1;

				long long ans3 = 0;
				for(int i=0;i<countr-1;i++)
				    ten *= 10;
				
//				cout << r << " " << ten << endl;
				if(r%2)
				ans3 += ((((r-ten+1)/2)%MOD)*((r+ten)%MOD))%MOD;
				else
				ans3 += ((((r-ten+1))%MOD)*(((r+ten)/2)%MOD))%MOD;
				ans3 %= MOD;
				ans3 = (ans3*countr)%MOD;
				r = ten-1;
				countr--;

				ans = (ans +  ans3)%MOD;
//				cout << ans3 << " ";
				ans %= MOD;
//				cout << ans << " ";

			}
			
//			cout << r << endl;
			long long ans2 = 0;
 			if(!((r+l)%2))
			ans2 += (((r-l+1)%MOD)*(((r+l)/2)%MOD))%MOD;
			else
			ans2 += ((((r-l+1)/2)%MOD)*(((r+l)%MOD)))%MOD;
			ans2 %= MOD;
			//countl--;
			ans2 = (ans2*countl)%MOD;
//			cout << ans2 <<" ";
			cout << (ans + ans2)%MOD << endl;
		}
		
	}
}
