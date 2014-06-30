/*
	Name: Ford Fulkerson Max flow network
	Copyright: no rights
	Author: Shivam Jindal
	Date: 20/09/13 13:00
	Description: using bfs
		for further details refer : 	D:\Algorithms docs\Ford Fulkerson
*/

#include<iostream>
#include<queue>
#include<limits>
using namespace std;

bool bfs(vector<vector<int> > &rgraph,int s,int t,int v,vector<int> &parent) {

	queue<int> q;
	vector<bool> is_visited(v,false);

	is_visited[s] = true;
	parent[s] = -1;
	q.push(s);
	
	while(!q.empty()) {
	
//		cout << "bfs ";
		int u = q.front();
		q.pop();
		
		for(int i=0;i<v;i++) {
		
			if(!is_visited[i] && rgraph[u][i] > 0) {
			
				is_visited[i] = true;
				parent[i] = u;
				q.push(i);
			}
		}
	}
	
	return is_visited[t];			// this will tell whether target has been reached
}


int ford_fulkerson(vector<vector<int> > &graph , int v, int s, int t) {

	int max_flow = 0;
	vector<vector<int> > rgraph(v,vector<int>(v));

	for(int i=0;i<v;i++) {
	
		for(int j=0;j<v;j++) {
		
			rgraph[i][j] = graph[i][j];				// initialise residue graph with full capacity
		}
	}
	
	vector<int>	parent(v);							// parent will store the parent of the node in bfs traversal
	int min_residue = numeric_limits<int>::max();
	
	while(bfs(rgraph,s,t,v,parent)) {				// loop will continue till target is reached through residual flow
	
//		cin.get();
		for(int i = t ; i != s ; i = parent[i]) {
		
			int u = parent[i];
			min_residue = min (min_residue, rgraph[u][i]);		// find min residue flow
		}
		
		for (int i = t ; i != s ; i = parent[i]) {
		
			int u = parent[i];
			rgraph[u][i] -= min_residue;				// decrease the rgraph edges with min residue flow
			rgraph[i][u] += min_residue;		
		}
		
		max_flow += min_residue;
	}
	
	return max_flow;
}


int main() {

	int v;
	cout << "enter total vertices: ";
	cin >> v;
	
	cout << "enter capacity of each edge of graph :\n";
	
	vector<vector<int> > graph(v,vector<int>(v));
	
	for(int i=0;i<v;i++) {
	
		for(int j=0;j<v;j++) {
		
			cin >> graph[i][j];
		}
	}
	
	int s,t;
	cout << "source and sink: ";
	cin >> s >> t; 
	
	cout << ford_fulkerson(graph,v,s,t) << endl;
	
}

