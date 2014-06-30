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

bool dfs(const vector<vector<int> > &graph,int jobs,vector<int> &match,vector<bool> &seen,int i) {

	for(int j=0 ; j<jobs ; j++) {
	
		if(!seen[j] && graph[i][j] > 0) {
		
			seen[j] = true;
			if(match[j] < 0 || dfs(graph,jobs,match,seen,match[j])) {
			
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}

int mbp(const vector<vector<int> > &graph,int jobs,int applicants) {
	
//	cout << "mbp";
	vector<int> match(jobs,-1);
	int count = 0;
	for(int i=0 ; i<applicants ; i++) {
	
		vector<bool> seen(jobs);
	
		if(dfs(graph,jobs,match,seen,i))
			count++;
	}
	
	return count;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,m ;
		cin >> n >> m ;
		vector<vi> graph(n+1,vi(n+1));
		vi freq(n+1);
		int a,b;
		rep(i,m) {
			cin >> a >> b;
			graph[a][b]=1;
			graph[b][a]=1;
		}
		int count  = mbp(graph,n,n);
		cout << count  << endl;
		if(count == n)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}
