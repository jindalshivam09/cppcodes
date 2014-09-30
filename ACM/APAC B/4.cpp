#include<bits/stdc++.h>
using namespace std;

#define MAX 401
vector<int> level(MAX*MAX) ;

void init() {
	int cnt = 1;
	for(int i=1;i<MAX;cnt++) {
		for(int j=0;j<cnt;j++,i++)
			level[i] = cnt ; 
	}
}

vector<vector<double> > memo(MAX,vector<double>(MAX*MAX)), values(MAX,vector<double>(MAX*MAX)) ;

double backTrack ( int b, int l, int n ) {
	if( l == 1 ) {
		values[l][n] = 250.00 ;
		return (b*750-250)/3.00 ;
	}
	if( l < level[n] )
		return 0.0 ;
	if( memo[l][n] != -1 )
		return memo[l][n] ;
	double ret = 0.0 ;
	ret += backTrack(b,l-1,n-level[n]) ;
	ret += backTrack(b,l-1,n-level[n]+1) ;
	ret += backTrack(b,l-1,n) ;
	
	if ( ret >= 250.0 ) {
		ret -= 250.0 ;
		values[l][n] = 250.00 ;
	}
	else {
		values[l][n] = ret ;
		ret = 0.0 ;
	}
	return memo[l][n] = ret/3.00 ; 
}

int main() {
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	init() ;
	int t;
	cin >> t;
//	t=150;
	for(int test=1;test<=t;test++) {
		int b,l,n ;
		cin >> b >> l >> n ;
//		b = 50000, l = 400 , n = 160000;
		for(int i=0;i<MAX;i++) 
			for(int j=0;j<i*i;j++)
				memo[i][j] = -1 ;

		cout << "Case #" << test << ": " ;
		cout.setf(ios::fixed)  ;
		cout.precision(7) ;
		if(n==1) {
			double ans = b*750.00 ;
			if(l==1)
				cout << 250.00 << endl;
			else {
				while(l > 1)
					ans = (ans-250.0)/3.00 , l--;
				cout << max(ans,0.0) << endl;
			}
				
		}
		else {
			backTrack(b,l,n) ;
			cout << max(values[l][n],0.00) << endl;
		}
	}
}
