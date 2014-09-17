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

int main() {
	int n ;
	cin >> n ;
	string str ;
	cin >> str ;
	int cnt = 0 ;
	int one = 1 ;
	rep(i,str.size()) {
		int temp =  str[i] - '0' ;
		if(temp == 1 && one == 1)
			cnt ++ ;
		else if(temp == 0 && one == 1)
			cnt ++,one = 0;
		else
			break;
	}
	cout << cnt ;
}


