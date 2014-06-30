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
	#define MOD 23102009
	string p,q;
	vector<vi> arr(MAX,vi(MAX)) ;
	vector<vi> ways(MAX,vi(MAX));
	int n,m;
	void lcs () {
		n = q.length()+1 , m = p.length()+1 ;
		rep(i,n)
			ways[i][0] = 1;
		rep(i,m)
			ways[0][i] = 1;
			
		for (int i=1;i<=q.length();i++) {
			for(int j=1;j<=p.length();j++) {
				if(q[i-1]==p[j-1]) {
					arr[i][j]=arr[i-1][j-1]+1;
					ways[i][j] = ways[i-1][j-1];
				}
				else {
					arr[i][j] = arr[i-1][j];
					ways[i][j] = ways[i-1][j] ;
					if ( arr[i][j] < arr[i][j-1] ) {
						arr[i][j] = arr[i][j-1];
						ways[i][j] = ways[i][j-1] ;		
					}
					else if (arr[i][j] == arr[i][j-1] ) {
						ways[i][j] = (ways[i-1][j] + ways[i][j-1]) % MOD ;
					
					if ( arr[i-1][j-1] == arr[i][j] ) {
						ways[i][j] = (ways[i][j] - ways[i-1][j-1] + MOD ) % MOD ;
					}
				}
				}						
			}
		}
	}
	
	int main() {
		int t;
		cin >> t;
		while(t--) {
			cin >> p >> q ;
			lcs();
			cout << arr[n-1][m-1] << " " << ways[n-1][m-1] << endl;
			rep(i,MAX)
				rep(j,MAX)
					arr[i][j] = ways[i][j] = 0 ;
		}
	}
	

