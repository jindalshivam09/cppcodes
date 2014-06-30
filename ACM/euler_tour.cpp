/*
	Name: Fleury Algorithm for euler tour
	Copyright: no rights
	Author: Shivam Jindal
	Date: 20/09/13 18:28
	Description: 
*/


#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int odd_vertices(list<int> *adj_list,int v) {

	int count = 0;
	
	for(int i=0 ; i<v ; i++) {
		
		if ((adj_list[i].size())&1)
			count++;
	}
	return count;
}

void remove_edge (list<int> *adj_list ,int u,int v ) {

	list<int>::iterator i = find(adj_list[u].begin() , adj_list[u].end() , v) ;
	*i = -1;
	
	list<int>::iterator j = find(adj_list[v].begin() , adj_list[v].end() , u) ;
	*j = -1;
	
}

void add_edge (list<int> *adj_list ,int u,int v ) {

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
}

int dfs_count(list<int> *adj_list ,vector<bool> &is_visited ,int u) {
	
	is_visited[u] = true;
	int count = 1;
	for(list<int>::iterator i = adj_list[u].begin() ; i != adj_list[u].end() ; i ++) {
	
		int j = *i;
		if( j != -1 && !is_visited[j])  {
	
			count += dfs_count(adj_list,is_visited,j);
		}
	}
	return count;
}

bool is_not_bridge(list<int> *adj_list ,int vertices , int u,int v) {

	int count = 0;  // To store count of adjacent vertices
  	list<int>::iterator i;
  	for (i = adj_list[u].begin(); i != adj_list[u].end(); ++i)
    	 if (*i != -1)
       		 count++;
  	if (count == 1)
   		 return true;

	vector<bool> is_visited(vertices);
	
	int count1 = dfs_count(adj_list,is_visited,u);
	remove_edge(adj_list,u,v);
	vector<bool> visited(vertices);
	
	int count2 = dfs_count(adj_list,visited,u);
	add_edge(adj_list,u,v);
	return count1 == count2;
}

void dfs (list<int> *adj_list ,int vertices,int u,list<pair<int,int> > &pairs) {

	for (list<int>::iterator i = adj_list[u].begin() ; i != adj_list[u].end() ; i++) {

		int v = *i;
		if ( v != -1 && is_not_bridge(adj_list,vertices,u,v) ) {

			pairs.push_back(make_pair(u,v));
			remove_edge(adj_list,u,v);
			dfs(adj_list,vertices,v,pairs);
		}
	}
}
	
void print_euler(list<int> *adj_list,int vertices) {

	int odd = odd_vertices(adj_list,vertices);			// this will return total number of odd vertices
	
	if (odd != 0 && odd != 2) {
	
		cout << "euler path not possible\n";
		return;
	}
	
	int i;
	for(i=0 ; i<vertices ; i++) {
		
		if (adj_list[i].size()&1) 		// this will give the odd vertex to start from
			break;
	}

	list<pair<int,int> > pairs;
	dfs(adj_list,vertices,i,pairs);

	cout << "euler tour: \n";	
	for(list<pair<int,int> >::iterator i = pairs.begin() ; i != pairs.end() ; i++) 
	cout << (*i).first << " " << (*i).second << endl;
}

int main() {

	int vertices,edges;
	cin >> vertices >> edges;
	
	list<int> adj_list[vertices];

	int a,b;
	for(int i=0 ; i<edges ; i++) {
	
		cin >> a >> b ;
		add_edge(adj_list,a,b);
	}
	
	print_euler(adj_list,vertices);

}

