#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<ll,ll> > vpll;
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
int n,k;
vll tree(MAX),pos(MAX);

ll cal_cum_freq(int idx) {
	ll sum = 0;
	while(idx>0) {	
		sum += tree[idx];
		idx -= (idx&-idx);
	}
	return sum;
} 

void change_freq(int idx,int freq) {
	while(idx <= n) {
		tree[idx] += freq;
		idx += (idx&-idx);
	}
}

bool cmp(const pii &a,const pii &b) {
	return a.first < b.first;
}

int main() {
	cin >> n >> k;
	vi A(n);
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	vi B(n);
	for(int i=0;i<n;i++)
		B[i] = A[i]-k;
	n++;
	vpll prefixsum(n);
	prefixsum[0].first = B[0]; 	prefixsum[0].second = 1;
	for(int i=1;i<n-1;i++) {
		prefixsum[i].first = prefixsum[i-1].first + B[i];
		prefixsum[i].second = i+1;
	}
	prefixsum[n-1].first = 0;
	prefixsum[n-1].second = 0;
	sort(all(prefixsum),cmp);
	int index = 1;
	pos[prefixsum[0].second] = index;
	for(int i=1;i<n;i++) {
		if(prefixsum[i].first > prefixsum[i-1].first)
			index++;
		pos[prefixsum[i].second] = index;
	}
	ll ans = 0;
	change_freq(pos[0],1);
	for(int i=1;i<n;i++) {
		ans += cal_cum_freq(pos[i]);			
		change_freq(pos[i],1);
//		cout <<  ans << " ";		
	}
//	rep(i,n)
//		if(prefixsum[i].first >= 0)
//			ans++;
	cout << ans << endl;
}


