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
#define MAX 55
int r,c,m ;
vector<vector<char> > matrix(MAX,vector<char>(MAX)) ;

int dx[] = {-1,-1,-1,0,0,1,1,1} ;
int dy[] = {-1,0,1,-1,1,-1,0,1} ;

bool check(int i,int j) {
	return (i>=0 && i<r && j>=0 && j<c) ;
}

bool possible () {
	int open = 0;
	vector<vector<char> > temp(MAX,vector<char>(MAX,'c')) ;
	rep(i,r) {
		bool flag ;
		rep(j,c) {	
			flag = false;
			int count = 0 ;
			int adj = 0;
			if (matrix[i][j]=='.' || matrix[i][j] == 'c') {
				rep(k,8) {
					if(check(i+dx[k],j+dy[k]) ){
						adj++;
						if ( matrix[i+dx[k]][j+dy[k]] != '*') 
						count ++ ;
					}
				}
				if (count == adj) {
					rep(k,8) {
						if(check(i+dx[k],j+dy[k]) && temp[i+dx[k]][j+dy[k]] != 'o')
							open ++ , temp[i+dx[k]][j+dy[k]] = 'o'; 
					}
				}
/*				else if ( temp[i][j] != 'o' ){
					cout << i << " " << j << endl;
					flag = true;
					break;
				
				}
*/				if (temp[i][j] != 'o') 
					open++ , temp[i][j] = 'o';
			}
		}
		if (flag)
			break;
	}
//	cout << open << " ";
	if (open == r*c-m)
		return true;
	else
		return false ;
}

void minesweeper() {
	int square = sqrt(r*c-m) ;
	square = min (square , min(r,c)) ;
	int count = 0 ;
	rep(i,square)	rep(j,square) 
		matrix[i][j] = '.', count ++;
	int j = min(r,c) ;
	if ( j == r ) {
		for(int k=square;k<c;k++) {
			for(int i=0;i<r;i++)
				if (count < r*c-m && i < square) 
					matrix[i][k] = '.' , count ++ ;
				else {
					matrix[i][k] = '*' ;
				}
		}
		for(int i=square ; i < r; i ++)
			for(int j=0;j<square;j++)
				if (count < r*c-m ) 
					matrix[i][j] = '.' , count ++ ;
				else {
					matrix[i][j] = '*' ;
				}
	}
	else {
		for(int k=square;k<r;k++) {
			for(int i=0;i<c;i++)
				if (count < r*c-m && i < square) 
					matrix[k][i] = '.' , count ++ ;
				else {
					matrix[k][i] = '*' ;
				}
		}
		for(int i=square ; i < c; i ++)
			for(int j=0;j<square;j++)
				if (count < r*c-m ) 
					matrix[j][i] = '.' , count ++ ;
				else {
					matrix[j][i] = '*' ;
				}
	
	}
	if(possible()) {
		rep(i,r) {
			rep(j,c)
				if(!i && !j)	cout << 'c' << " " ;
				else			cout << matrix[i][j] << " ";
			cout << endl;
		}
	}
	else
		cout << "Impossible" << endl;
}
 
int main() {
	int t;
	cin >> t;
	for(int test=1;test<=t;test++){
		cin >> r >> c >> m ;
		cout << "Case #" << test << ": " << endl;
		minesweeper() ;
		cin.get() ;
	}
}


