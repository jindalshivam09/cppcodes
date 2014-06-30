#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
vector<vpii> adj(7);
int N,T;
priority_queue< pair<pii,int> > q ;

void insert_q ( int pri,int qua,int i ){
	pri *= -1 ;
	qua *= -1 ;
	q.push ( mp ( mp(qua,pri) , i ) ) ;
}

pair<pii,int> remove_q () {
	pair<pii,int> temp = q.top();
	q.pop() ;
	temp.first.first *= -1 ;
	temp.first.second *= -1;
	return temp ;
}

int quality () {
	int qua , pri ,cost = 0 , num ,next;
	vi next_index(7);
	int temp = imax;
	int i = 1 ;
	for(;i<7;i++)	if(adj[i].size()>0){
		next_index[i] = 1;
		pri = adj[i][0].first;
		qua = adj[i][0].second;
		if ( cost + pri > T )
			return 0;
		cost += pri ;
		insert_q(pri,qua,i);
	}
	if(i<6)
		return 0 ;

	pair<pii,int> popped ;
	while ( cost <= T && N-- && !q.empty()) {
		popped = remove_q();
		num = popped.second ;
		pri = popped.first.second ;
		qua = popped.first.first ;
		next = next_index[num] ;
		if (next < adj[num].size() && cost-pri+(adj[num][next].first) <= T && qua < adj[num][next].second) {
			cost = cost - pri + (adj[num][next].first) ;
			insert_q (adj[num][next].first,adj[num][next].second,num);
		}
		else if (next+1 < adj[num].size()) {
			next_index[num] = next+1;
			insert_q(pri,qua,num);
		}
		else
			return qua;
	}
	return qua;
}


int main() {
	cin >> N >> T ;
	int a,b,c;
	rep(i,N) {
		cin >> a >> b >> c ;
		adj[a].pb(mp(b,c));
	}
	repi(i,1,7) {
		sort(all(adj[i]));
	}
	cout << quality() ;
}
