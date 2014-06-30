/*
	Name: Attending Events
	Copyright: 
	Author: jindalshivam09
	Date: 02/03/14 22:58
	Description: 
*/


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
#define MAX 28
vi one(MAX) , two(MAX);
vector<vi> adj(MAX,vi(MAX));
int edges = 0 ;
void dfs (int i) {
		for(int v=0;v <26;v++) {
			if(adj[i][v]) {
				adj[i][v] -- ;
				adj[v][i] --;
				edges ++ ;
				dfs (v);
			}
		}
}
int main() {
	int t;
	scanf("%d",&t) ;
	while(t--) {
		int n;
		scanf("%d",&n) ;
		edges = 0;
		int a,b,ch;
		char str[100009] ;
		rep(i,n) {
			scanf("%s",&str) ;			
			a = str[0] - 'a';
			b = str[strlen(str)-1] - 'a';
			adj[a][b] ++ ;
			adj[b][a] ++ ;
			one[a] ++ ;
			two[b] ++ ;
		}
		int count  = 0;
		for(int i=0;i<26;i++) {
			if ( one[i] == two[i] )
				continue;
			else 
				count += abs(one[i]-two[i]);
		}
		if ( count && count != 2 ) {
			printf("NO\n");	
		}
		else {
			for(int i=0;i<26;i++)
				if (one[i]) {
					dfs (i) ;
					break;
				}
			if ( edges == n) 			// to check whether each edges is visited or not
				printf("YES\n");
			else
				printf("NO\n");
		}
		
		rep(i,26) {
			rep(j,26) {
				adj[i][j] =  0;
				one[j] = two[j] = 0;
			}
		}
	}
}


