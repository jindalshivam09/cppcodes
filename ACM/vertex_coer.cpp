/*
	Name: Vertex Cover Problem
	Copyright: no rights
	Author: Shivam Jindal
	Date: 14/10/13 23:16
	Description: NP Complete problem aims to find an vertes cover that is set of vertices so that each edge of given graph must have atleast one 
				vertice which belong to this cover	
*/

#include<iostream>
#include<vector>
#include<list>
#include<utility>
using namespace std;

list<pair<int,int> > cover;

list<pair<int,int> > vertex_cover (const vector<pair<int,int> > &edges,int e) {
	
	
	vector<bool> visited(e,false); 
//	cout << "vertex cover...";
	for(int i=0;i<e;i++) {
		
		int u = edges[i].first;
		int v = edges[i].second;
		if( !visited[u] && !visited[v] ) {
			
			cover.push_back(make_pair(u,v));
			visited[u] = visited[v] = true;
		}		
	}
	return cover;
	
}

int main() {
	
	int e,v;
	cin >> v >> e;
	
	vector<pair<int,int> > edges(e);
	
	int a,b;
	for(int i=0;i<e;i++) {
		
		cin >> a >> b;
		edges[i] = make_pair(a,b);
	}
	
	list<pair<int,int> > cover = vertex_cover(edges,e) ;
	
	for(list<pair<int,int> >::iterator i = cover.begin() ; i != cover.end() ; i ++)
		cout << i->first << " " << i->second << endl;		
}

