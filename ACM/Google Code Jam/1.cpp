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
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	int t;
	cin >> t ;
	for(int test=1;test<=t;test++) {
		vector<vi> mat1(4,vi(4)) , mat2(4,vi(4)) ;
		int y1,y2;
		cin >> y1 ;
		rep(i,4)	rep(j,4)
			cin >> mat1[i][j] ;
		cin >> y2 ;
		rep(i,4)	rep(j,4)
			cin >> mat2[i][j] ;
		int ans = -1 , count = 0 ;
		vi freq(17) ;
		rep(i,4)
			freq[mat1[y1-1][i]] ++ ;
		rep(i,4) {
			int temp = mat2[y2-1][i] ; 
			if (freq[temp]) {
				ans = temp ;
				count ++ ;
			}
			freq[temp] ++ ;
		}
		cout << "Case #" << test << ": " ;
		if (count == 1)	
			cout << ans << endl;
		else if (count > 1) 
			 cout << "Bad magician!" << endl;
		else
			cout << "Volunteer cheated!" << endl;
	}
}


