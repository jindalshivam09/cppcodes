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

int s,k ;
vi shobhit , kriti ;
vb resultS(MAX) , resultK(MAX) ;
void init () {
	resultS[0] = resultK[0] = false;
	int temp  , index = 0;
	for(int i=1;i<MAX;i++) {
		bool flag = false;
		for(int j=0;j<k;j++) {
			temp = kriti[j] ;
			if (temp>i) {
				resultK[i] = false;
				break;
			}
			if (resultS[i-temp] == false) {
				flag = true ;
				break;
			}
		}
		resultK[i] = flag ;
		flag = false; 
		for(int j=0;j<s;j++) {
			temp = shobhit[j] ;
			if (temp>i) {
				resultS[i] = false;
				break;
			}
			if (resultK[i-temp] == false) {
				flag = true ;
				break;
			}		
		}
		resultS[i] = flag ;
	}		
}

int main() {
	cin >> k >> s ;
	kriti.resize(k) ;
	shobhit.resize(s) ;
	rep(i,k)
		cin >> kriti[i] ;
	rep(i,s)
		cin >> shobhit[i] ;
	sort(all(kriti)) ;
	sort(all(shobhit)) ;
	init() ;
	int q;
	cin >> q ;
	while(q--) {
		int turn ;
		char player ;
		cin >> turn >> player ;
		if (player == 'K') {
			if (resultK[turn]==false)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else{
			if (resultS[turn]==true)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
	
		}
	}	
}


