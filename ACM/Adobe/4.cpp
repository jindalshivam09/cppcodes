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
	int n,m;
	cin >> n >> m ;
	vector<vi> arr(n,vi(m));
	rep(i,n)	rep(j,m)
		cin >> arr[i][j] ;
	int q;
	cin >> q;
	while(q--) {
		int key ;
		cin >> key ;
		bool flag = false ;
		rep(i,n) {
			int index = lower_bound(all(arr[i]),key) - arr[i].begin() ;
			if (index<m && arr[i][index]==key) {
				cout << i << " " << index << endl;
				flag = true;
				break;
			}
		}
		if(flag==false) 
			cout << "-1 -1" << endl;
	}
}


