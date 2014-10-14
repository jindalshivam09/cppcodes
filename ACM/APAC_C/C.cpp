#include<bits/stdc++.h>
using namespace std;

#define MAX 1000009
vector<vector<int> > primes(MAX);
vector<int> there(10) ;
int x;
int divisors[4] = {2,3,5,7} ;
void init() {
	vector<bool> visited(MAX) ;
	for(int i=2;i*i<MAX;i++) {
		if(visited[i]==false) {
			visited[i] = true ;
			for(int j=i;j<MAX;j+=i) {
				primes[j].push_back(i) ;
				visited[j] = true ;
			}
		}
	}
}

int traverse(int x) {
	int ans = 0 ;
	while(x) {
		int digit = x%10 ;
		x /= 10 ;
		if(there[x])
			ans ++;
		else
			return INT_MAX;
	}
	return ans + 1 ;
}

int operations(int x) {
	
	int ans = 0;
		
	vector<int> temp(10,0) ; 	
	for(int i=0;i<4;i++) {
		int val = divisors[i] ;
		while(x%val == 0) {
			temp[val] ++ ;
			x /= val ;	
		}
	}
	
	for(int i=9;i>=2;i--) {
		if(there[i]) {
			if(i == 9)	ans += temp[3]/2 , temp[3] %= 2 ;
			if(i == 8)	ans += temp[2]/3 , temp[2] %= 3 ;
			
		}
	}
}

int func() {
	int ans = traverse(x) ;	
	
	for(int i=2;i*i<=x;i++) {
		if( i*(x/i) == x) { 
			int a = traverse(i), b = traverse(x/i) ;
			int c = operations(i), d = operations(x/i) ;
			ans = min(ans,a+b+2) ;
			ans = min(ans,a+d+2) ;
			ans = min(ans,c+d+2) ;
			ans = min(ans,b+c+2) ;
		}
	}
	return ans ;
}

int main() {
	
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	
//	init() ;
	int t ;
	cin >> t ;
	for(int test = 1 ; test <= t; test++) {
		for(int i=0;i<10;i++)
			cin >> there[i];
		cin >> x ;
		int ans = func() ;
		cout << "Case #" << test << ": " 
		if(ans == INT_MAX) cout << "Impossible" ;
		else 	cout << ans ;
		cout << endl;
	}
}
