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
#define MAX 1009
vi sum(MAX);
void init() {
	int temp = 0;
	for(int i=1;i<MAX;i++) {
		int n = i;
		while(n) {
			temp += (n&1);
			n=n/2;
		}
		sum[i] = temp;
	}
}
int main() {
	init() ;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << sum[n] << endl;
	}
}


