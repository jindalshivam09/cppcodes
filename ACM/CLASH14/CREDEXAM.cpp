#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
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

int main() {
	int m,n ;
	cin >> m >> n ;
	vi arr(m) ;
	rep(i,m)
		cin >> arr[i] ;
	sort(all(arr)) ;
	int sum = 0 ;
	rep(i,m-1)
		sum += arr[i] ;
	if(sum+1 < arr[m-1])
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}


