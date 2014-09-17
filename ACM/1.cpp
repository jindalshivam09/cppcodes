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
map<int,int> fib ;
vector<int> arr(MAX) ;
void init() {
	arr[0] = 0 , arr[1] = 1 ;
	fib[0] = 1 , fib[1] = 1 ;
	int i=2;
	for(;;i++) {
		arr[i] = arr[i-1] + arr[i-2] ;
		if(arr[i] >= 1000000000)
			break;
		fib[arr[i]] = 1;
	}
}

int main() {
	init() ;
	int t ;
	cin >> t ;
	for(int test = 1 ; test <= t ; test++) {
		int n,m;
		cin >> n >> m ;
		ll sum = 0 ;
		for(int i=2;i*i<=n;i++) {
			if( n % i == 0) {
				if(i != n/i)
				sum = (sum+i)%m , sum = (sum + n/i)%m;
				else
				sum = (sum+i)%m ;
//				cout << i << " " << n/i << endl;
			}
		}
		sum ++ ;
		sum %= m;
//		cout << sum << endl;
		int cnt = 0 ;
		for(int i=2;i*i<=sum;i++) {
			if( sum % i == 0 && i*i != sum)
				cnt += 2 ;
			if ( sum % i == 0 && i*i == sum )
				cnt ++ ;
		}
		cnt ++ ;
//		cout << cnt << endl;
		cout << "Case #" << test << " : " ;
		if (fib[cnt])
			cout << "YES." << endl;
		else
			cout << "NO." << endl;
	}
}


