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
//	ifstream cin("input.txt");
//  ofstream cout("output.txt");
	int t;
	cin >> t ;
	while(t--) {
		int n;
		cin >> n ;
		string str;
		cin >> str ;
		ll pre = 2 , num = 9 , temp;
		int turn = 0 ;
		while( 1 ) {
			turn ++ ;
			cout << pre << " " << num << endl;
			if ( pre <= n && num >= n ) {
				break;
			}
			temp = pre ;
			pre = num+1;
			num = (temp)*9 ;
		}
		if ( turn%2 )	
			cout << str << endl;
		else {
			if (str[0] == 'D')
				cout << "Rachit" << endl;
			else
				cout << "Deepak" << endl;
		}
	}
}
