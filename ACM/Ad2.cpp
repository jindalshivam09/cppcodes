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

map<char,int> match ;
int val[][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}} ;
string str1 , str2 ;

void init () {
	
	match['A'] = 0 ;
	match['C'] = 1 ;
	match['G'] = 2 ;
	match['T'] = 3;
	match['-'] = 4;
}
int memo[1009][1009] ;
int dp(string str1 , string str2 ,int i,int j ) {
	if ( i==str1.size()-1 && j == str2.size()-1 ) {
		return val[match[str1[i]]][match[str2[j]]] ;
	}
	if (memo[i][j])
		return memo[i][j] ;
	int ans = -300009;
	if ( i < str1.size()-1)
	ans = max(ans , val[4][match[str2[j]]] + dp(str1,str2,i+1,j) );
	if ( j < str2.size()-1)
	ans = max (ans ,val[match[str1[j]]][4]+ dp(str1,str2,i,j+1)) ;
	if ( i < str1.size() && j < str2.size())
	ans = max(ans,val[match[str1[i]]][match[str2[j]]] + dp(str1,str2,i+1,j+1));
	return memo[i][j] = ans ;
}

int DNAAlignment (string str1,string str2) {
	for(int i=0;i<1009;i++)
		for(int j=0;j<1009;j++)
			memo[i][j] = -300009;
	return dp(str1,str2,0,0) ;
}

int main() {
	
	init() ;
	cin >> str1 >> str2 ;
	
	cout << dp (str1,str2,0,0) << endl;
}


