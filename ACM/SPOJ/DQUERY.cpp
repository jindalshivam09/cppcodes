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

vi BIT;
map<int,vi> indexes;

typedef struct queries {
	pii cords;
	int id ;
} queries;

bool cmp(const queries &a,const queries &b) {
	return a.cords.first == b.cords.first ? a.cords.second < b.cords.second : a.cords.first < b.cords.first ;
}

void update(int idx,int val) {
	while(idx<BIT.size()) {
		BIT[idx] += val;
		idx = idx + (idx&-idx) ;
	}
}

int query(int idx) {
	int ret = 0 ;
	while(idx>0) {
		ret += BIT[idx] ;
		idx = idx - (idx&-idx);
	}
	return ret ;
}

int main() {
	int n;
	scanf("%d",&n) ;
	vi arr(n+1) ;
	BIT.resize(n+1) ;
	repi(i,1,n+1)
		scanf("%d",&arr[i]) ;
	repi(i,1,n+1) {
		indexes[arr[i]].pb(i) ;		
	}
	int q ;
	scanf("%d",&q) ;
	vector<queries> que(q) ;
	rep(i,q) {
		que[i].id = i ;
			scanf("%d%d",&que[i].cords.first,&que[i].cords.second) ;
	}
	sort(all(que),cmp) ;
	for(map<int,vi>::iterator itr = indexes.begin() ; itr != indexes.end() ; itr++) {
		int a = (itr->second)[0] ;
		update(a,1) ;
	}
	vi ans(q+1) ;
	int last = 1 ;
	rep(i,q) {
		int a = que[i].cords.first , b = que[i].cords.second ;
		while(last<a) {
			int temp = arr[last];
			int index = upper_bound(all(indexes[temp]),last) - indexes[temp].begin() ;
			index = indexes[temp][index] ;
			update(last,-1) ;
			update(index,1) ;
			last++;
		}
		ans[que[i].id] = query(b) - query(a-1) ;
	}
	rep(i,q)
		printf("%d\n",ans[i] ) ;
}


