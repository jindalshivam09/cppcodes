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


int cal_cum_freq(const vector<int> &tree ,int idx) {

	int sum = 0;
	while(idx>0) {
	
		sum += tree[idx];
		idx -= (idx&-idx);
	}
	return sum;
} 

void change_freq(vector<int> &tree,int idx,int freq) {

	while(idx < tree.size()) {
		
		tree[idx] += freq;
		idx += (idx&-idx);
	}
}


int main() {
	int n,q;
	cin >> n >> q ;
	vi tree(n+1), values(n+1,1) ;
	rep(i,n)
		change_freq(tree,i+1,1) ;
	int type,flip,l,r;
	int init = 1 ;
	rep(i,q) {
		cin >> type ;
		cout << "init : " << init << endl;
		if(type == 1) {
			cin >> flip ;
			for(int j=flip+init;j<=n;j++) {
				int val = values[init] ;
				change_freq(tree,j,val) ;
			}
			init += flip ;
		}
		else {
			cin >> l >> r ;
			cout << cal_cum_freq(tree,init+r-1) - cal_cum_freq(tree,init+l-1) << endl ;
		}
	}	
}


