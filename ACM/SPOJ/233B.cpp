#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
ll digit_sum(ll n) {
	ll sum = 0;
	while(n) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}
int main() {
	ll n;
	cin >> n;
	ll temp;
	ll ans = -1 , cal;
	ll s = 1;
	for(int i=1;i<101;i++) {
		temp = (-i + sqrt(i*i + 4*n) ) / 2;
		s = digit_sum(temp);
//		cout << s << " " << temp << endl;
		if(i==s && temp*temp + s*temp == n){
			ans = temp ;
			break;
		}
	}
	cout << ans << endl;
}


