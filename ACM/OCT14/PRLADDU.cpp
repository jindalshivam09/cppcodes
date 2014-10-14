#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; 
	cin >> t ;
	while(t--) {
		int n;
		cin >> n ;
		vector<pair<ll,ll> > villagers, dinosaurs ;
		int a ;
		for(int i=0;i<n;i++) {
			cin >> a ;
			if(a>=0)
				villagers.push_back(make_pair(a,i)) ;
			else
				dinosaurs.push_back(make_pair(-a,i)) ;
		}
		int j = 0;
		long long ans = 0;
		for(int i=0;i<villagers.size();i++) {
			ll val = villagers[i].first ;
			ll index = villagers[i].second ;
			while(val) {
				ll din = dinosaurs[j].first ;
				ll idx = dinosaurs[j].second ;
				if(val >= din) {
					ans += (din*abs(index-idx)) ;
					j++;
					val -= din ; 
				}
				else {
					dinosaurs[j].first -= val ;
					ans += (val*abs(index-idx)) ;
					val = 0;
				}
			}
		}
		cout << ans << endl;
	}
}
