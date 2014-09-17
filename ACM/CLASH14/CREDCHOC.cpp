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

vi arr ;
int sum ;

bool possible () {
	vb obt(sum+1) ;
	int temp;
	rep(i,arr.size()) {
		if(arr[i] > sum)
			break ;
		obt[arr[i]] = true ;
	}
	cout << "df";
	for(int i=1;i<10000;i++) {
		if(obt[i] == false) {
			for(int j=1;j<i;j++) {
				if(obt[j] && obt[i-j]) {
					obt[i] = true;
//					break;
				}
				if(obt[j] && i%j == 0) {
					obt[i] = true ;
//					break;
				}
			}
		}
	}
	cout << "SHIvam" ;
	return obt[sum] ;
}

int main() {
	int n ;
	cin >> n ;
	int x,y ;
	cin >> x >> y ;
	set<int> distinct ;
	int a ;
	rep(i,n) {
		cin >> a ;
		a-- ;
		distinct.insert(a);
	}
	for(set<int>::iterator i = distinct.begin() ; i != distinct.end() ; i ++)
		arr.pb(*i) ;
	sum = (y-x) ;
//	cout << "d";
	if(sum == 0 || arr[0] == 1) {
		cout << "POSSIBLE" << endl;
		return 0;
	}
	if(possible()) 
		cout << "POSSIBLE" << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}


