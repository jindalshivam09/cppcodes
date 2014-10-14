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
		if(there[digit])
			ans ++;
		else
			return INT_MAX;
	}
	return ans ;
}

vector<long long> memo(MAX) ;

long long func(int x) {
//	cout << x << " " ;
	if(memo[x] != 0)
		return memo[x] ;
	
	long long ret = traverse(x);
	for(int i=2;i*i<=x;i++) {
		if((i*(x/i)) == x)	
			ret = min(ret , 1+ func(i)+func(x/i)) ;
	}
	return memo[x] = ret ;
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
		long long ans = func(x) ;
		cout << "Case #" << test << ": " ;
		if(ans >= INT_MAX) cout << "Impossible" ;
		else 	cout << ans+1 ;
		cout << endl;
		for(int i=0;i<=x;i++)
			memo[i] =  0;
	}
}
