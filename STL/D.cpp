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
map<int,int> freq[MAX]; 
int n,t;
vi arr(MAX),power(MAX);

void init() {
	int p = sqrt(n);
	int index = 0;
	for(int i=0;i<n;i+=p) {
		int j = i;
		while( j<n && j<i+p ){
			freq[i][arr[j]]++;
			j++;
		}
//				for(map<int,int>::iterator itr = freq[i].begin(); itr != freq[i].end() ; itr ++) 
//					cout << itr->first << " " << itr->second <<" " << i <<  endl;
	}
}

int query (int l,int r) {
	map<int,int> tempfreq;
	int p = sqrt(n),i=l-1;
	while(i%p && i<r) {
//		cout << i << "l ";
		tempfreq[arr[i]]++;
		i++;
	}	
	for(;i<r-p;i+=p){
		for(map<int,int>::iterator itr = freq[i].begin(); itr != freq[i].end() ; itr ++) {
			tempfreq[itr->first] += freq[i][itr->first];
		}
//		cout << i << "j ";
	}
	while(i<r) {
//		cout << i <<  "k ";
		tempfreq[arr[i]] ++;
		i++;
	}
	ll ans = 0;
	for(map<int,int>::iterator itr = tempfreq.begin(); itr != tempfreq.end() ; itr ++) {
		int key = itr->first;
		int value = itr->second;
		ans += key*value*value;
//		cout << key << " " << value << endl;
	}
	return ans;
}

int main() {
	cin >> n >> t;
	rep(i,n)
		cin >> arr[i];		
	init();
	while(t--) {
		int l,r;
		cin >> l >> r;
		cout << query(l,r) << endl;
	}
}


