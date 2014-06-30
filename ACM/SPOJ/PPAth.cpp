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
vi prime ;
	vb isPrime(10009,true) ;
void sieve() {
	isPrime[0] = isPrime[1] = false ;
	for (int i=2;i<109;i++) {
		if(isPrime[i]) {
			for(int j=2*i;j<10000;j+=i) 
				isPrime[j] = false;
		} 
	}
/*	for(int i=1000;i<10000;i++)
		if (isPrime[i]) {
			prime.pb(i);
			cout << i << " ";
	}
*/	
}
int bfs (int a,int b) {
	queue<pii> q;
	q.push(mp(a,0));
	int count = 0;
	vb visited(10009);
	while(!q.empty()) {
		pii node = q.front();
		int v = node.first;
		count = node.second;
		q.pop();
		if(v==b)
			return count ;
		visited[v] = true;
		count++;
		int temp = v ;
		int tens = 1;
		int digit ;
		while(temp) {
			int last = temp%10;
			temp /= 10 ;
			for(int i=1;i<10;i++) {
				last = (last+i)%10;
				digit = temp * pow(10,tens) + last*pow(10,tens-1) + (v%int(pow(10,tens-1))) ;
				if (isPrime[digit] && !visited[digit] ) {
					visited[digit] = true;
					q.push(mp(digit,count)); 
				}
			}
			tens ++ ;
		}
	}
	return -1;
}
int main() {
	sieve();	
	int t;
	cin >> t;
	while(t--) {
		int a,b;
		cin >> a >> b;
		cout << bfs(a,b) << endl; 
	}
}


