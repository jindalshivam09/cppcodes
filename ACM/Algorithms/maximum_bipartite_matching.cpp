/*
	Name: Maximum Bipartite Matching
	Copyright: no rights
	Author: Shivam Jindal
	Date: 21/09/13 11:59
	Description: using dfs
	refer to : D:\Algorithms docs\Graph\Maximum Bipartite Matching - GeeksforGeeks   GeeksforGeeks
*/

#include<iostream>
#include<vector>
using namespace std;

bool dfs(const vector<vector<int> > &graph,int jobs,vector<int> &match,vector<bool> &seen,int i) {

	for(int j=0 ; j<jobs ; j++) {
	
		if(!seen[j] && graph[i][j] > 0) {
		
			seen[j] = true;
			if(match[j] < 0 || dfs(graph,jobs,match,seen,match[j])) {
			
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}

int mbp(const vector<vector<int> > &graph,int jobs,int applicants) {
	
//	cout << "mbp";
	vector<int> match(jobs,-1);
	int count = 0;
	for(int i=0 ; i<applicants ; i++) {
	
		vector<bool> seen(jobs);
	
		if(dfs(graph,jobs,match,seen,i))
			count++;
	}
	
	return count;
}

int main() {

	int applicants,jobs;
	cin >> applicants >> jobs;
	
	vector<vector<int> > jobs_graph(applicants,vector<int>(jobs));
	
	for(int i=0 ; i<applicants ; i++) {
	
		for(int j=0 ; j<jobs ; j++) {
		
			cin >> jobs_graph[i][j];
		}
	}
	
	cout << mbp(jobs_graph,jobs,applicants) << endl;
}
