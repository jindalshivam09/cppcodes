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

int main() {
	ll n,x;
	cin >> n >> x;
	vll arr(n);
	rep(i,n)
		cin >> arr[i];
	
	sort(all(arr));
	ll success = 0 , fail = 0;
	ll i;
	for(i=0;i<n;i++) {
		ll temp = arr[i];
		if(temp&1) 
			temp = temp/2+1;
		else 
			temp /= 2;
		arr[i] -= temp;
		if(x >= temp) {
			x -= temp;
		}
		else 
			break;
	}
//	cout << x << endl;
	fail = n-i;
	rep(i,n) {
		ll temp = arr[i];
		if(temp <= x)  {
			x -= temp;
			success ++;
		}
		else
			break;	
	}
	cout << fail << " " << success << endl;
}


