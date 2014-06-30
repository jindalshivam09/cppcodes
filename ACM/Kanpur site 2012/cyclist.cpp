#include<iostream>
#include<vector>
#include<list>
#include<cstring>
#include<limits>
using namespace std;

#define MAX 1000009
#define EPSILON 0.000001

double minv (double a, double b) {

	if( a > b + EPSILON )
	return b;
	return a;
}

double maxv (double a, double b) {

	if( a > b + EPSILON )
	return a;
	return b;
}

void dfs (int u,int src,int des, list<pair<int,double> > *road,vector<bool> &is_visited,vector<bool> &is_reachable,vector<double>&value) {

//	cout << u << endl;
	is_visited[u] = true;
	
	if( u == des) {
	
		is_reachable[u] = true;
		value[u] = numeric_limits<double>::max();
		return;
	}
	
	for (list<pair<int,double> >::iterator i = road[u].begin() ; i != road[u].end() ; i ++) {
	
		int v = (*i).first;
		double f = (*i).second;
		if (!is_visited[v]) {
		
			dfs(v,src,des,road,is_visited,is_reachable,value);
		}
		
		if (is_reachable[v]) {
			
				is_reachable[u] = true;
				value[u] = maxv (value[u] , minv (value[v],f) );
//				cout << u << " " << value[u] << " " << v << endl;
		}
	}
}

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int v;
		cin >> v;
		
		list<pair<int ,double> > road[v+1];
		vector<bool> is_visited(v+1);
		vector<bool> is_reachable(v+1);
		vector<double> value(v+1,0.0);		
			
		int a,b;
		double sf;
		cin >> a >> b >> sf; 
		
		int i=0;	
		while(a != -1) {
		
			road[a].push_back(make_pair(b,sf));
			road[b].push_back(make_pair(a,sf));
			cin >> a >> b >> sf; 
		}
		
		
		dfs(1,1,v,road,is_visited,is_reachable,value);
		cout.precision(10); 
		
		if (v==1)		cout << 0.0000 << endl;
		else			cout << value[1] << endl;
		
		
	}
}
