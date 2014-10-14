#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
string str ;
vector<ll> number ;

ll ways(int m,int l) {
	int n = str.size() ;
	vector<vector<int> > memo(2,vector<int>(m,0)) ;
	
	int row ;
	ll ans = 0;
	for(int i=0;i<n;i++) {
		if(i%2)		row = 1 ;
		else		row = 0 ;
		memo[row][number[i]%m] = 1 ;
		for(int j=0;j<m;j++) {
			ll val = memo[1-row][j] ;
			ll temp = (j*10 + number[i]) % m ;
			memo[row][temp] += val ;
		}
		for(int j=0;j<m;j++)
			memo[1-row][j] = 0 ;
		ans += memo[row][l] ;
	} 
	return ans ;
}

int main() {
	cin >> str ;
	number.resize(str.size()) ;
	for(int i=0;i<str.size();i++) 
		number[i] = str[i]-'0' ;
	
	int q ; 
	cin >> q ;
	while(q--) {
		int l,m ;
		cin >> m >> l;
		cout << ways(m,l) << endl; ;
	}
}
