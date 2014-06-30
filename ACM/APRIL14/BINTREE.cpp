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
	int n;
	cin >> n ;
	while(n--) {
		int i,j;
		cin >> i >> j ;
		if (i==j) {
			cout << 0 << endl;
			continue ;
		}
		int count = 1  ;
		map <int,int> val; 
		while ( i > 0) {
			val[i] = count;
//			cout << i << " " << count << endl;
			count ++ ;
			i /= 2 ;
//		4	cout << i << endl;
		}
		count = 0 ;
		while( j > 0 ) {
			if ( val[j] ) {
				cout << val[j] + count - 1 << endl;
				break ;
			}
//			cout << j << " " << count <<  endl;
			j /= 2 ;
			count ++ ;
		}
//		cout << count << endl;
	}
}


