/*
	Name: Bipartite Graph
	Copyright: no rights
	Author: Shivam Jindal
	Date: 22/07/13 14:00
	Description: 
*/

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

#define MAX 100
#define NIL 0
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef list<int> edge;
typedef long long ll;

int cc[MAX];
int color[MAX];
int parent[MAX];
int components = 0;


void dfs_visit(edge *u , int i) {
    color[i] = GRAY;
    edge::iterator itr = u[i].begin();
    for( ; itr != u[i].end() ; itr++) {
        if(color[*itr] == WHITE) {
            parent[*itr] = i;
            cc[*itr] = cc[i];
            dfs_visit(u,*itr);
        }
    }
    color[i]  = BLACK;
}

void dfs(edge *v, int n) {
    for(int i=1;i<=n;i++) {
        if(color[i] == WHITE) {
            cc[i] = ++components;
            dfs_visit(v,i) ;
        }
    }
}
//-------------input from user-------------------------
void input_adj_list(edge *v,int n) {
	int a,b;
	for(int i=0 ; i<n ; i++ ){
		cin >> a >> b;
		v[a].push_back(b);
	}
}
//////////////////////////////////////////////////////

void print(int n) {
	cout << n << " ";
}

//------------------output adjacency list--------------
void output_adj_list(edge *v,int n) {
	for(int i=1 ; i<=n ; i++) {
		cout << i << " ";
		for_each(v[i].begin() , v[i].end() , print);
		cout << endl;
	}
}
///////////////////////////////////////////////////////////

//-------------------bipartite graph----------------------------

void bipartite (edge *v , int edges , int vertices) {
	dfs(v,vertices);
}
////////////////////////////////////////////////////////////

main() {
	
	int edges,vertices;
	cin  >> vertices >> edges;
	edge v[vertices+1];
	input_adj_list(v,edges);
	cout << endl;
	output_adj_list(v,vertices);
	cout << endl;
	
	bipartite(v,edges,vertices);
}

