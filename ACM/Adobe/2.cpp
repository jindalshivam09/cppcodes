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

bool isPrime[MAX];
vector<int> prime(MAX);
int p ;
void sieve(int n) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
			   isPrime[j]=1;
	}
	p = 2 ;
	prime[0] = 1;
	prime[1] = 2;
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
		prime[p++] = i;
//	cout << p << endl;
}

int x,y;

int func() {
	int count = 0 ;
	vb special(MAX,true);
	for(int i=1;i<p;i++) {
		int temp = prime[i] ;
		temp = temp*temp;
		if(temp>y)
			break;
		int rem = x%temp ;
//		cout << x << " " << temp <<  " " << rem << " ";
		int start = x + (x%temp == 0 ? 0 : (temp-rem));
//		cout << start << endl; 
		for(int j=start;j<=y;j+=temp) {
//			cout << j <<  " ";
			special[j-x] = false;
		}
//		cout << endl;
	}
	for(int j=x;j<=y;j++)
		if (special[j-x])
			count ++;
	return count ;
}

int main() {
	sieve(MAX);
	int t;
	cin >> t;
	while(t--) {
		cin >> x >> y ;
		cout << func() << endl;
	}
}


