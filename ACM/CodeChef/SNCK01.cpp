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
	int t ;
	cin  >> t ;
	while(t--) {
		int n,m;
		cin >> n >> m ;
		vector<vi> arr(n,vi(m));
		rep(i,n) rep(j,m)
			cin >> arr[i][j] ;
		int wins = 0 ;
		rep(i,n) {
			int one = 0 , nonone = 0;
			int j=0;
			while ( j<m && arr[i][j] == 1)
				one ++ , j ++;
			for(;j<m;j++)
				if (arr[i][j])
					nonone ++;
			if (one%2 && !nonone)	
				wins ++ ;
			if ( !(one%2) && nonone )
				wins ++ ;
		}
		if (wins%2)
			cout << "FIRST" << endl;
		else
			cout << "SECOND" << endl;
	}
}


