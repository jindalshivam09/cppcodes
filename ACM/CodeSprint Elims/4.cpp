#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int b, q, mincap ;
vector<int> arr ;
vector<ll> values ;

void preprocess() {
	values.resize(mincap) ;
	fill(values.begin(),values.end(),INT_MAX) ;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > > q ;
	q.push(make_pair(0,0)) ;
	values[0] = 0 ;
	while(q.empty() == false) {
		pair<ll,ll> u = q.top() ;
		q.pop() ;
		if(values[u.second] != u.first)
			continue;
		for(ll i=0;i<arr.size();i++) {
			ll val = arr[i] ;
			ll temp = (u.first + val) ;
			ll temp2 = (u.second+val)%mincap;
			if(values[temp2] > temp) {
				values[temp2] = temp ;
				q.push(make_pair(temp,temp2)) ;
			}
		}
	}
}

int main() {
	cin >> b >> q ;
	arr.resize(b) ;
	mincap = INT_MAX ;
	for(int i=0;i<b;i++) {
		cin >> arr[i] ;
		mincap = min(mincap, arr[i]) ;
	}
	
	preprocess() ;
	ll val ;
	while(q--) {
		cin >> val ;
		if(values[val%mincap] > val)
			cout << "no" ;
		else
			cout << "yes" ;
		cout << endl;
	}
}
