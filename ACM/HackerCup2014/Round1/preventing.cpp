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

#define MAX 100
void sieve(vb &gcd,int k,int n) {

	for(int i=k;i<=n;i+=k)
		gcd[i]=true;	
	for(int i=2*k;i<=n;i++) {
		for(int j=2*i;j<=n;j+=i) {
				gcd[j]=false;
		}
	}
}
int main() {

	int t;
	cin >> t;
	for(int test=1;test<=t;test++) {
		int n,k;
		vb gcd(n+10);
		cin >> n >> k;
		vi arr(n);
//		for(int i=0;i<n;i++)
//			cin >> arr[i];
		sort(all(arr));	
		sieve(gcd,k,n);
		for(int i=0;i<=n;i++)
			if(gcd[i])
				cout << i << " ";
	}
}


