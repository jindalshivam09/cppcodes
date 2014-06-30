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

vector<vi> route ,ans;
vi degree , temp_route;
int tot_route , n;
vb visited ;

void dfs(int u) {
	temp_route.pb(u) ;
	visited[u] = true ;
	int count  = 0 ; 
	rep(i,route[u].size()) {
		int v = route[u][i] ;
		if(visited[v] == false) {
			count ++;
			dfs(v) ;
		}
		if(count==1)
			break;
	}
}

void cal_routes() {
	for(int i=1;i<=n;i++) {
		if(visited[i]==true)
			continue;
		int count  = 0 ;
		visited[i] = true ;
		for(int j=0;j<route[i].size();j++) {
			int v = route[i][j] ;
			bool flag = false;
			temp_route.clear() ;
			if(visited[v] == false) {
				count ++ ;
				flag = true ;
				dfs(v) ;
			}
			if(count==1 && flag) {
				for(int k=temp_route.size()-1;k>=0;k--)
					ans[tot_route].pb(temp_route[k]) ;
//					cout << i << endl;			
					ans[tot_route].pb(i);
			}
			if(count==2 && flag) {
				for(int k=0;k<temp_route.size();k++)
					ans[tot_route].pb(temp_route[k]) ;				
			}			
			if(count==2)
				break;
		}
		if(count == 0 )
			ans[tot_route].pb(i) ;
		tot_route ++ ;
	}
}

bool cmp(int a, int b) {
	return degree[a] < degree[b] ;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n ;
		visited.resize(n+1) ;
		route.resize(n+1) ;
		ans.resize(n+1) ;
		degree.resize(n+1) ;
		int a,b ;
		rep(i,n-1) {
			cin >> a >> b ;
			route[a].pb(b) , route[b].pb(a) ;
			degree[a] ++ , degree[b] ++ ;
		}
		rep(i,n) {
			sort(route[i+1].begin() ,route[i+1].end(),cmp);
		}
		cal_routes() ;
		cout << tot_route << endl;
		rep(i,tot_route) {
			rep(j,ans[i].size())
				cout << ans[i][j] << " " ;
			cout << endl;
		}
		tot_route = 0;
		visited.clear() ;
		route.clear() ;
		degree.clear() ;
		ans.clear() ;
	}
}


