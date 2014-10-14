#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long  ll;
vector<vector<ll> > base(2,vector<ll>(2)), temp(2,vector<ll>(2)) ;
void init() {
	base[0][0] = base[0][1] = 2 ;
	base[1][0] = 1 ;
	base[1][1] = 0 ;
}

vector<vector<ll> > matrixMul(vector<vector<ll> > &a, vector<vector<ll> > &b) {
	temp[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%MOD ;
	temp[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%MOD ;
	temp[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%MOD ;
	temp[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%MOD ;
	return temp ;
}

vector<vector<ll> > f(ll n) {
	if(n == 1)
		return base ;
	vector<vector<ll> > matrix(2,vector<ll>(2));
	matrix = f(n/2) ;
	matrix = matrixMul(matrix,matrix) ;
	if(n%2)
		matrix = matrixMul(matrix,base) ;
	return matrix ; 
}

int main() {
	init() ;
	int t ;
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		if(n==1)
			cout << 1 << endl;
		else if(n==2)
			cout << 3 << endl;
		else {
			vector<vector<ll> > matrix(2,vector<ll>(2)) ;
			matrix = f(n-2) ;
			cout << (3*matrix[0][0] + 1*matrix[0][1])%MOD << endl ;
		}
	}
}
