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
	int n,k;
	cin >> n >> k;
	vi arr(n+1);
	repi(i,1,n+1)
		cin >> arr[i] ;
	int temp = arr[1];
	bool flag = false;
	repi(i,1,n+1) {
		if (temp != arr[i]) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << 0 << endl;
		return 0;
	}
	flag = false;
	temp = arr[n];
	int i ;
	for(i=n-1;i>0;i--) {
		if (temp != arr[i]) {
			flag = true;
			break;
		}
	}
//	cout << i << endl;
	i ++;
//	cout << i << "  " << k<< endl;
	if (flag && i > k)
		cout << -1 << endl;
	else
		cout << min(k-1,i-1) << endl;
}


