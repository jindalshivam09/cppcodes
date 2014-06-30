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
	ll n;
	cin >> n;
	vi arr(n);
	rep(i,n)
		cin >> arr[i];
	sort(all(arr));
	map<ll,ll> d;
	bool flag = false;
	for(ll i=1;i<n;i++) {
		d[arr[i]-arr[i-1]]++;
		if(arr[i]!=arr[i-1])
			flag = true;
	}
	if(d.size()==0 )
		cout << -1 << endl;
	else if (!flag)
		cout << 1 << endl << arr[0] << endl;
	else if (d.size()==1) {
		if(n==2) {
			if((arr[0]+arr[1])%2==0 && arr[0]!=arr[1])
				cout << 3 << endl , cout << arr[0]-(arr[1]-arr[0]) << " " << (arr[0]+arr[1])/2 << " " << arr[1] + (arr[1]-arr[0]) << endl  ;
			else
				cout << 2 << endl , cout << arr[0]-(arr[1]-arr[0]) << " "  << arr[1] + (arr[1]-arr[0]) << endl  ;
		}
		else
			cout << 2 << endl , cout << arr[0]-(arr[1]-arr[0]) << " " << arr[n-1] + (arr[1]-arr[0]) << endl  ;
	}
	else if (d.size()==2) {
		map <ll,ll>::iterator  itr = d.begin();
		ll dif1 = itr->first;
		ll freq = itr->second;
		itr++;
		ll dif2 = itr->first;
			
		if(freq==n-2) {
			ll i;
			for( i=1;i<n;i++) {
				if(dif2 == arr[i]-arr[i-1])
					break;
			}
			if(dif1==dif2/2 && dif2%2==0)
				cout << 1 << endl , cout << (arr[i]+arr[i-1])/2 << endl ;
			else
				cout << 0 << endl;
		}
		else  {
				ll i;
			for( i=1;i<n;i++) {
				if(dif1 == arr[i]-arr[i-1])
					break;
			}
			if(dif2==dif1/2 && dif1%2==0)
				cout << 1 << endl , cout << (arr[i]+arr[i-1])/2 << endl ;
			else
				cout << 0 << endl;		
		}
	}
	else
		cout << 0 << endl;
}


