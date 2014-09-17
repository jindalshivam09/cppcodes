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

bool cmp (const pii &a, const pii &b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		int n,x ;
		cin >> n >> x ;
		vpii time(n) ;
		rep(i,n)
			cin >> time[i].first >> time[i].second ;
		sort(all(time),cmp) ;
		vb interrogated(n) ;
		int ans = 0 ;
		rep(i,n) {
			int cnt = 0;
			int tm = time[i].second ;
			int j=i ;
			for(;j<n;j++){
				if(tm >= time[j].first && interrogated[j] == false)
					cnt ++ ;
				else if(tm < time[j].first)
					break;
			}
	//		cout << j << endl;
	//		cout << cnt << endl;
			if(cnt >= x) {
				int temp = 0 ;
				for(int k=j-1;k>=0&&temp < (cnt-x+1);k--) {
	//				cout << k << " " << temp << endl;
					if(interrogated[k] ==false) {
						interrogated[k] = true ;
						temp ++ ;
						ans ++ ;
					}
				}
//				cout << endl;
			}
		}
		cout << ans << endl;
	}
}


