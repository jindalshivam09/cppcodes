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
#define MAX 100
#define A 1000000000
int main() {
	
	ofstream cout("test.txt") ;
	int n = 100000 , m = 100 ;
	cout << n << " " << m << endl;
	rep(i,n) {
		cout << rand()%A << " ";
	}
	cout << endl;
	rep(i,m) {
		int a = rand()%(n/2) + 1 ;
		int b = rand()%n +1 ;
		while(b<=a) {
			b = rand()%n+1;
		}
		cout << a << " " << b << endl;
	}
}


