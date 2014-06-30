#include<iostream>
#include<vector>
#include<limits>
using namespace std;

#define v1 first.first
#define v2 first.second
#define wt second
#define parent first

void init(const vector<pair<pair<int,int> ,int > > &edges, vector<pair<int,int> > &path,int v, int source) {

	for(int i=0;i<v;i++) {
	
		path[i].wt = numeric_limits<int>::max();
		path[i].parent = 0;
	}
	
	path[source].wt = 0;
	
}

void relax(const vector<pair<pair<int,int>,int> > &edges ,vector<pair<int,int> > &path, int j) {

	int u = edges[j].v1;
	int v = edges[j].v2;
	
	if (path[v].wt > path[u].wt + edges[j].wt) {
	
		path[v].wt = path[u].wt + edges[j].wt;
		path[v].parent = u;
	}
}

bool bellman_ford(const vector<pair<pair<int,int>,int> > &edges,vector<pair<int,int> > &path,int v , int source) {


	init(edges,path,v,source);
	for(int i=1;i<v;i++) {
		
		for(int j=0;j<edges.size();j++) {
		
			relax(edges,path,j);
		}
	}
	
	
	for (int j=0;j<edges.size();j++) {
	
		int u = edges[j].v1;
		int v = edges[j].v2;
	
		if (path[v].wt > path[u].wt + edges[j].wt) 
			return false;	
	}
	return true;
}

int main() {

	int v,e;
	cin >> v >> e;
	int source;
	cin >> source;
	vector<pair<pair<int,int>,int> > edges(e);
	vector<pair<int,int> >	path(v);
	int a,b,c;
	for(int i=0;i<e;i++) {
	
		cin >> a >> b >> c;
		edges[i] = make_pair(make_pair(a,b),c);
	}
	
	if (bellman_ford(edges,path,v,source)) {
	
		cout << "shortest path possible" << endl;
		for(int i=0;i<v;i++) {
		
			cout << source << " " << i << " " << path[i].wt << endl;
		}
	}
	else {
	
		cout << "negative cycle present";
	}
	
	
	
}
