/*
	Name: Maximum Weight Independent Set  O(n)
	Copyright: no rights
	Author: Shivam Jindal
	Date: 09/08/13 23:57
	Description: we are given some nodes and their weight . we have to find the max possible weighted set from these
				 nodes such that no adjacent nodes are taken in the set so formed 			
*/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

vector<int> cal_wis(const vector<int> &nodes) {
	
	vector<int> max_weights(nodes.size());
	
	max_weights[0] = nodes[0];
	max_weights[1] = max ( max_weights[0] , nodes[1] );

	for(auto i = 2 ; i < nodes.size() ; i ++) {
	
		max_weights[i] = max( max_weights[i-1] , max_weights[i-2] + nodes[i] );
	}
	
	return max_weights;
}

list<int> reconstruct (vector<int> nodes , vector<int> wt) {
	
	
//	cout << "reconstructing the set " ;
	int j = 0;
	list<int> indep_set;
	
	for(auto i = wt.size()-1 ; i > 0 ; ) {
	
//		cout << i << " ";
//		cin.get();
		if (wt[i] > wt[i-1]) {
			indep_set.push_front ( nodes[i] );
			if(i>1) 	i -= 2;
			else 		i--;
		}
		else {
			indep_set.push_front ( nodes[i-1] );
			i --;
		}
	}
	
	return indep_set;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> nodes(n);
	
	for(auto &i : nodes)
		cin >> i;
		
	vector<int>	max_weights = cal_wis (nodes);	
	
//	for_each ( max_weights.begin() , max_weights.end() , [](int n) {cout << n << " "; });
	cout << max_weights[max_weights.size()-1];
	cout << endl;
	
	list<int> indep_set = reconstruct ( nodes , max_weights );

	for_each ( indep_set.begin() , indep_set.end() , [](int n) {cout << n << " "; });
	cout << endl;
	
}

