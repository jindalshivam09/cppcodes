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

	int n,m;
	cin >> n >> m;
	
	vi arr(n);
	
	rep(i,n)
		cin >> arr[i];
		
	vi freq(n);
	vb is(100009);
	is[arr[n-1]] = true;
	freq[n-1] = 1;
	for(int i=n-2;i>=0;i--) {
		
		if(!is[arr[i]]) {
			
			freq[i] = freq[i+1]+1;
			is[arr[i]] = true;
		}
		else
			freq[i] = freq[i+1];
	}
	
	int a;
	rep(i,m) {
		
		cin >> a;
		cout << freq[a-1] << endl;
	}
}


