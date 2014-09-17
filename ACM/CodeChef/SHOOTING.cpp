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

int n,m;
vector<vector<char> >  matrix ;
vector<int> vertical ;
bool possible ;

void check_possiblity (int num) {
	if ( num == -1 ) {
		possible = true ;
		return ;
	}
	bool enemy = false ;
	rep(i,m) {
		if( vertical[i] == false && matrix[num][i] == 'E') {
			enemy = true ;
			break;
		}
	}
	
	if ( enemy == false ) {
		rep(i,m) {
			if ( matrix[num][i] == 'L') {
				vertical[i] ++ ;
			}
		}
		
		check_possiblity ( num - 1 )  ;
		
		rep(i,m) {
			if ( matrix[num][i] == 'L') {
				vertical[i] -- ;
			}
		}
		return ;
	}
	
	int lasers = 0;
	rep(i,m) if (matrix[num][i] == 'L')
		vertical[i] ++ , lasers ++ ;
	
	if (lasers == 0)  
		return ;
		
	int left = m+1, right = -1 ;
	rep(i,m) {
		if ( vertical[i] == false && matrix[num][i] == 'E' ) {
			left = min ( left, i) ;
			right = max ( right, i) ;
		}
	}
	
	rep(i,left) {
		if ( matrix[num][i] == 'L' ) {
			vertical[i] -- ;
			
			check_possiblity ( num - 1) ;
			if(possible)
				return ;
			vertical[i] ++ ;
		}
	}
	
	repi(i,right+1,m) {
		if ( matrix[num][i] == 'L' ) {
			vertical[i] -- ;
			
			check_possiblity ( num - 1) ;
			if(possible)
				return ;
			vertical[i] ++ ;
		}		
	}
	
	if(lasers >= 2) {
		rep(i,m) {
			repi(j,i+1,m) {
				if( matrix[num][i] == 'L' && matrix[num][j] == 'L') {
					vertical[i] -- , vertical[j] -- ;
					
					check_possiblity (num-1) ;
				
					vertical[i] ++ , vertical[j] ++ ;		
					if( possible )
						return ;
				}
			}
		}
	}
	
	rep(i,m)
		if(matrix[num][i] == 'L')
			vertical[i] -- ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n >> m ;
		matrix.resize(n,vector<char>(m)) ;
		vertical.resize(m) ;		
		possible = false ;
		rep(i,n)
			rep(j,m)
				cin >> matrix[i][j] ;
		check_possiblity (n-1) ;
		if ( possible )	
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl; 		
	}
}


