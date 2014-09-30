#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 30
typedef long long ll;
ll n,m ;
vector<vector<ll> > even(MAX,vector<ll>(MAX)), odd(MAX,vector<ll>(MAX)), T(MAX,vector<ll>(MAX)) ;

vector<vector<ll> > A(MAX,vector<ll>(MAX)) ;

vector<vector<ll> > mat_mul( vector<vector<ll> > &B, vector<vector<ll> > &C) {
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			A[i][j] = 0 ;
			for(int k=0;k<m;k++) {
				A[i][j] = ( A[i][j] + ( B[i][k]*C[k][j] ) % MOD ) % MOD ;		
			}
		}
	}
	return A ;
}

void init() {	
//	cout << "init" << endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			even[i][j] = odd[i][j] = T[i][j] = 0;
	
	int index = 0;
	for(int i=1;i<m-1;i++) {
		int j=0;
		for(j=index;j<m && j<index+3;j++)
			even[i][j] = 1 ;
		index ++ ;
	}
	even[0][0] = 1 ;
	if( m > 1 ) 
		even[0][1] = 1 ;
	if ( m-2 >= 0 )
		even[m-1][m-2] = 1;
	even[m-1][m-1] = 1 ;
//	cout << "fd" ;	
	
	index = 0;
	for(int i=1;i<m-1;i++) {
		odd[i][index] = 1;
		if( index+2 < m )
			odd[i][index+2] = 1 ;
		index ++ ;
	}
	if(m>1)
		odd[0][1] = 1;
	if( m-2 >= 0 )
		odd[m-1][m-2] = 1 ;
/*	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++)
			cout << even[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++)
			cout << odd[i][j] << " ";
		cout << endl;
	}
*/
//	cout << "shivam" ;
	T = mat_mul(even,odd) ;

/*	cout << endl;
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++)
			cout << T[i][j] << " ";
		cout << endl;
	}
*/
}

vector<vector<ll> > mat_exp ( int p ) {
	if( p == 1 )
		return T ;
	vector<vector<ll> > matrix(m,vector<ll>(m)) ;
	matrix = mat_exp(p/2) ;
	matrix = mat_mul(matrix,matrix) ;
	if( p % 2 )
		matrix = mat_mul(matrix,T) ;
	return matrix ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n >> m ;
		init() ;
//		cout << "Fd";
		
		vector<vector<ll> > matrix(m,vector<ll>(m)) ;
		if( n == 1 ) {
			cout << m << endl;
			continue ;
		}		
		else if( n == 2 ) {
			matrix = odd ;
		}		
		else {
			matrix = mat_exp((n-1)/2) ;
			if((n-1)%2) 
				matrix = mat_mul ( matrix, odd ) ;
		}
		
		ll ans = 0 ;
		for(int i=0;i<m;i++) {
			for(int j=0;j<m;j++) {
//				cout << matrix[i][j] << " " ;
				ans = ( ans + matrix[i][j] ) % MOD ;
			}
//			cout << endl;
		}
		cout << ans << endl; 
	}
}
