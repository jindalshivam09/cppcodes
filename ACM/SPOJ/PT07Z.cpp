#include <iostream> 
#include <list>
#include <vector>
#include <algorithm>
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

#define MAX 100009
list<int> adj[MAX] ;
vector<vi> path(MAX);
int n;
vb visited(MAX);

int dfs(int i=1) {
	int temp = 0;
	int ret = 0 ;
	visited[i] = true;
	for(list<int>::iterator itr = adj[i].begin() ; itr != adj[i].end() ; itr ++) {
		if(!visited[*itr]) {
	   		temp = 1+dfs(*itr);
			path[i].pb(temp);
			ret = max(ret,temp);
		}
		
	}
//	cout << ret << endl;
	return ret;
	
}

int longest_path() {
	dfs();
	int ans = 0;
	for(int i=1;i<=n;i++) {
		sort(all(path[i]),greater<int>());
		if(path[i].size()>1)
			ans = max(ans,path[i][0]+path[i][1]);
		else if (path[i].size()==1)
			ans = max(ans,path[i][0]);
	}
	return ans;
}

int main() {
	cin >> n;
	int a,b;
	for(int i=0;i<n-1;i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	cout << longest_path() << endl;
}
