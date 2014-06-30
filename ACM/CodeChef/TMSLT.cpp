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
#define MAX 1000000

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n ;
		ll a,b,c,d;
		cin >> a >> b >> c >> d ;
		vll values(MAX);
		ll temp = d ;
		values[temp] ++ ;
		repi(i,1,n) {
			temp = ( (a*temp*temp) + (b*temp) + c ) %MAX ;
			values[temp] ++ ;
		}
		ll one = 0 , two = 0;
		int turn = 1 ;
		for (int i=MAX-1;i>=0;i--) {
			if (values[i]%2) {
				if(turn==1)
					one += i , turn = 2;
				else
					two += i , turn = 1;
				
			}
		}
		cout << abs(one-two) << endl;
	}
}


