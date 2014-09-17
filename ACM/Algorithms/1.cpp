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

vector<vector<char> > matrix;
int n ;
bool check (int i,int j) {
	return i>=0 && j>=0 && i < n && j < n ;
}

bool even (int i, int j) {
	int cnt = 0 ;
	if (check(i-1,j) && matrix[i-1][j] == 'o')	cnt ++;
	if (check(i,j+1) && matrix[i][j+1] == 'o')	cnt ++;
	if (check(i+1,j) && matrix[i+1][j] == 'o')	cnt ++;
	if (check(i,j-1) && matrix[i][j-1] == 'o')	cnt ++;
	if ( cnt % 2 == 0)
		return true;
	return false ;
}

int main() {
	cin >> n ;
	matrix.resize(n,vector<char>(n) ) ;
	rep(i,n)
		rep(j,n)
			cin >> matrix[i][j] ;
		
	bool flag = true ;
	rep(i,n)	rep(j,n)
		if(even(i,j) == false) {
			cout << "NO";
			return 0;
		}
	cout << "YES" ;
}


