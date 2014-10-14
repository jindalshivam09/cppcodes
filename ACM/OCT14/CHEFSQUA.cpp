#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n ;
set<pair<ll,ll> > cords;

bool sameSide(ll x1, ll y1, ll x2, ll y2, const pair<ll,ll> &first,const pair<ll,ll> &second) {
	ll a = first.first, b = first.second;
	ll c = second.first, d = second.second ;
	ll val1 = (y1-b)*(c-a) - (d-b)*(x1-a) ;
	ll val2 = (y2-b)*(c-a) - (d-b)*(x2-a) ;
	return (val1*val2) > 0 ;
}

int search(ll x1,ll y1,ll x2,ll y2) {
	int cnt = 0;
	if(cords.find(make_pair(x1,y1)) != cords.end())
		cnt ++ ;
	if(cords.find(make_pair(x2,y2)) != cords.end())
		cnt ++ ;
	return cnt ;
}

int main() {
	cin >> n ;
	ll a,b ;
	for(int i=0;i<n;i++) {
		cin >> a >> b ;
		cords.insert(make_pair(a,b)) ;
	}
	
	if(n == 0)	cout << 4 << endl;
	else if(n == 1)	cout << 3 << endl;
	else if(n == 2) cout << 2 << endl;
	else {
		int ans = 4 ;
		for(set<pair<ll,ll> >::iterator itr = cords.begin() ; itr != cords.end(); itr ++) {
			set<pair<ll,ll> >::iterator itr2 = itr ;
			ll x1 = itr->first ;
			ll y1 = itr->second ; 
			itr2 ++ ;
			for(; itr2 != cords.end() ; itr2 ++ ){
				int cnt = 0;
				ll x2 = itr2->first ;
				ll y2 = itr2->second  ;
				ll xa1 = y1-y2+x1 ;
				ll ya1 = y1-x1+x2 ;
				ll xa2 = y2-y1+x1 ;
				ll ya2 = x1-x2+y1 ;
				ll xb1 = y2-y1+x2 ;
				ll yb1 = y2-x2+x1 ;
				ll xb2 = y1-y2+x2 ;
				ll yb2 = x2-x1+y2 ;
				if(sameSide(xa1,ya1,xb1,yb1,*itr,*itr2)) {
					int cnt1 = search(xa1,ya1,xb1,yb1) ;
					int cnt2 = search(xa2,ya2,xb2,yb2) ;
					cnt = max(cnt1,cnt2) ;	
				}
				else {
					int cnt1 = search(xa1,ya1,xb2,yb2) ;
					int cnt2 = search(xa2,ya2,xb1,yb1) ;
					cnt = max(cnt1,cnt2) ;
				}
				cnt += 2 ;
				ans = min(ans,4-cnt) ;
			}
		}
		cout << ans << endl;
	}
}
