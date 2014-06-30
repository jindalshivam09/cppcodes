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

#define MAX 100009
list<pii> adj[MAX];
vi problem(MAX);
vi ans;

int dfs(int n,int i=1){
	
	bool flag = false;
	for(list<pii>::iterator j = adj[i].begin() ; j != adj[i].end() ; j++) {
		
		if(j->second == 2)
			problem[i]++;
		int temp = dfs(n,j->first);
		 	problem[i]+=temp;
	}
	return problem[i];
}

bool elections(int n,int i=1) {
	
//	cout << i << endl;
	bool flag = false;
	int t=problem[i],e;
	for(list<pii>::iterator j = adj[i].begin() ; j != adj[i].end() ; j++) {
		
//		cout << problem[j->first] << " "<< j->first << " " << j->second << endl;
		if(problem[j->first])
			e  = elections(n,j->first);
		else if(e){
			
			ans.pb(j->first);
		}
//			problem[]
	}
	return t;
}

int main() {

	int n;
	cin >> n ;
	
	for(int i=0;i<n-1;i++) {
		
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
	}
	
	dfs(n);
//	for(int i=1;i<=n;i++)
//		cout << problem[i] << " ";
//		cout << endl;
	if(problem[1]) {
	
		elections(n);
		
//	for(int i=1;i<=n;i++)
//		cout << problem[i] << " ";
//		cout << endl;
		cout << ans.size() << endl;
		for(vi::iterator i = ans.begin() ; i!=ans.end() ; i++)
			cout << (*i) << " ";
	}	
	else
		cout << 0 << endl;	
}


