/*
	Name: Maximum Bipartite Matching Problem using BFS
	Copyright: no rights
	Author: jindalshivam09
	Date: 03/02/14 20:40
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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 100
vector<vi> graph (MAX);
vi row_match(MAX) , col_match(MAX);
int v,e;

bool find_match (int source) {
	vi path(v,-1);
	queue < int > q ;
	q.push ( source );
	path[source] = source;
	bool path_find = false ;
	vi left(v) , right(v) ;
	int where , match ;
	while(!path_find && !q.empty()) {
		where = q.front();
		q.pop();
		for(int i=0;i<graph[where].size();i++) {
			match = graph[where][i] ;
			int next = col_match[match] ;
			if ( next != where ) {
				if ( !next ) {
					path_find = true ;
					break;
				}
				if ( path[next] == -1 ) {
					q.push( next ) ;
					path[next] = where ;
				}
			}
		}
	}
	if ( !path_find )
		return false ;
	while(path[where] != where) {
		int aux = row_match[where] ;
		col_match[match] = where ;
		row_match[where] = match ;
		where = path[where] ;
		match = aux ;
	}
	col_match[match] = where ;
	row_match[where] = match ;
	return true;
}

int maximum_matching () {
	int ans = 0;
	for(int i=1;i<=v;i++) {
		ans += find_match(i);
	}
	return ans;
}

int main() {
	cin >> v >>  e;
	int a,b ;
	rep(i,e) {
		cin >> a >> b;
		graph[a].pb(b) ;
	}
	cout << maximum_matching () << endl;
	repi(i,1,v+1) 
		cout << i << " " << row_match[i] << endl;
}
