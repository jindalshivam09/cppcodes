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

	int t;
	cin >> t;
	while(t--) {
		
		int n,k;
		cin >> n >> k;
		vi A(n) , B(n);
		rep(i,n)
			cin >> A[i];
		rep(i,n)
			cin >> B[i];
			
		sort(all(A));
		sort(all(B));
		
		vi::iterator itr ;
		bool flag = true;
		
		rep(i,n) {
		
			int key = k-A[i];
			itr = lower_bound(all(B),key);
			if(itr == B.end()) {
				
				flag = false;
				break;
			}		
			else
				B.erase(itr); 	
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}


