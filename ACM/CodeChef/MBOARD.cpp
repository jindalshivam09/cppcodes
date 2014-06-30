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
#define MAX 1000009
vi row0ts(MAX) , col0ts(MAX) , row1ts(MAX) , col1ts(MAX) ;
class BIT {
	ll n;
	vll tree;
	public :
		BIT (ll n=0) {
			this->n = n ;
			tree.resize(n+1,0) ;
			rep(i,n)
				tree[i] = 0 ;
		}
		BIT (int n , const vi &arr ) {
			tree.resize(n+1,0) ;
			rep(i,n) 
				tree[i] = arr[i] ;
		}
		void resize(ll n) {
			this->n = n ;
			tree.resize(n+1,0) ;
			rep(i,n)
				tree[i] = 0 ;
		}
		void update ( int index , int val ) { 		// update the BIT with value 'val' from the index 'index'
			while ( index <= n ) {
				tree[index] += val;
				index += (index&-index) ;
			}
		}
		ll query ( ll index ) {			// return the summation of all the value till index 'index'
			ll ans = 0;
			while ( index > 0 ) {
				ans += tree[index] ;
				index -= (index&-index) ;
			}
			return ans ;
		}
		ll find_index ( ll val ) {			// find the index where the summation of values is 'val'
			ll bitmask = pow ( 2 , sqrt(n) ) ;	// kind of binary search
			ll index = 0 , temp = 0 ;
			while ( bitmask && temp <= n ) {
				index = temp + bitmask ;
				if ( tree[index] == val )
					return index ;
				if ( val > tree[index] ) {
					val -= tree[index] ;
					temp = index ;
				}
				bitmask >>= 1 ;
			}
			if ( !val )		return index ;
			else			return -1 ;
		}
} row0q(MAX) , col0q(MAX) , row1q(MAX) , col1q(MAX); 
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	char str[20] ;
	int a,b;
	repi(i,1,q+1) {
		scanf("%s%d",str,&a);
		if ( str[0] == 'R' ){
			if ( str[3] == 'S' ) {
				scanf("%d",&b) ;
				if (b)	{
					if( row1ts[a] < row0ts[a] && row0ts[a] )
						row0q.update ( row0ts[a] , -1  ) ;
					else if (row1ts[a])
						row1q.update ( row1ts[a] , -1 ) ;
					row1q.update ( i , 1 ) ;
					row1ts[a] = i;
				}
				else {
					if( row1ts[a] > row0ts[a] && row1ts[a] )
						row1q.update ( row1ts[a] , -1  ) ;
					else if (row0ts[a])
						row0q.update ( row0ts[a] , -1 ) ;
					row0q.update ( i , 1 ) ; 
					row0ts[a] = i;					
				}	
			}
			else {
				if ( row1ts[a] > row0ts[a] ) {
					int t = row1ts[a] ;
					int temp = col0q.query(i+1) - col0q.query(t);
					printf("%d\n",temp);
				}
				else {
					int t = row0ts[a] ;
					int temp = col1q.query(i+1) - col1q.query(t);
					printf("%d\n",n-temp);
				} 
			}
		}
		else {
			if ( str[3] == 'S' ) {
				scanf("%d",&b) ;
				if (b)	{
					if( col1ts[a] < col0ts[a] && col0ts[a] )
						col0q.update ( col0ts[a] , -1  ) ;
					else if (col1ts[a])
						col1q.update ( col1ts[a] , -1 ) ;
					col1q.update ( i , 1 ) ;
					col1ts[a] = i;
				}
				else {
					if( col1ts[a] > col0ts[a] && col1ts[a])
						col1q.update ( col1ts[a] , -1  ) ;
					else if ( col0ts[a])
						col0q.update ( col0ts[a] , -1 ) ;
					col0q.update ( i , 1 ) ;
					col0ts[a] = i;					
				}	
			}
			else {
				if ( col1ts[a] > col0ts[a] ) {
					int t = col1ts[a] ;
					int temp = row0q.query(i+1) - row0q.query(t);
					printf("%d\n",temp);
				}
				else {
					int t = col0ts[a] ;
					int temp = row1q.query(i+1) - row1q.query(t);
					printf("%d\n",n-temp); 					
				} 
			}
		}
		
	}
}


