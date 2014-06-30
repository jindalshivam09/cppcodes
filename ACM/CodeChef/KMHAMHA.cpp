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
#define dmax            nunmeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 1009
int n;
map<int,vi> bipartite;

bool dfs(map<int,int> &match,map<int,bool> &seen,int i) {
	for(int k=0 ; k<bipartite[i].size() ; k++) {
		int j = bipartite[i][k] ;
//		cout << j << " ";
		if(!seen[j]) {
			seen[j] = true;
			if(match[j] == 0 || dfs(match,seen,match[j])) {
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}

int mbp() {
	map<int,int> match;
	int count = 0;
	for(map<int,vi>::iterator itr = bipartite.begin() ; itr != bipartite.end() ; itr ++) {
		int i = itr->first ;
//		cout << i <<  " ";
		map<int,bool> seen;
		if(dfs(match,seen,i))
			count++;
//		cout << endl;
	}
	return count;
}


int main() {
	int t;
	cin >> t ;
	while(t--) {
		int a,b ;
		cin  >> n ;
		rep(i,n) {
			cin >> a >> b ;
			a++;
			b++;
			bipartite[a].pb(b) ;
		}
		cout << mbp() << endl;
		for(map<int,vi>::iterator itr = bipartite.begin() ; itr != bipartite.end() ; itr ++)
			bipartite[itr->first].clear();
	}
}


