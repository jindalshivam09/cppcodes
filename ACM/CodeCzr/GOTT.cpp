/*
	Name: 0-1 knapsack problem O(nW)
	Copyright: no rights
	Author: Shivam Jindal
	Date: 01/09/13 16:38
	Description: using dp in this we have a knapsack and few objects with certain weight and certain values. we are given a weight that the
				 knapsack can bear at max. we need to max the values of all the objects taken within the given max weight
				 simply use top-down approach
*/


#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<limits>
using namespace std;

#define value first
#define weight second

int cal_max_value(vector<pair<int,int> > &objects,int sum,int W) {
	
	vector<long long> arr(sum+1,numeric_limits<int>::max());
	
	for(int i=1;i<=sum;i++) {
		
		for(int j=0;j<objects.size();j++) {
			
			int val = objects[j].first;
			long long wt = objects[j].second;
			
			if(val < i) {
				
				arr[i] = min(arr[i],arr[val]+arr[i-val]);
			}
			else if(val == i )
				arr[i] = min(arr[i],wt);
		}
	}
	
	for(int i=0;i<=sum;i++)
	if(i==W)
	cout << arr[i] << " ";	
	
	int pl = W , cost = numeric_limits<int>::max();
	for(int i=W;i<=sum;i++) {
		
		if(cost >= arr[i]) {
			
			pl = i;
			cost = arr[i];
		}
	}
	cout << cost << " " << pl << endl;
}


int ks (const vector<pair<int,int> > &objects , int W) {

	vector<vector <int> >  v (objects.size()+1, vector<int>(W+1,0));
	 
	
	int wt , val;
	for (int i = 1 ; i <= objects.size() ; i ++) {
	
		val = objects[i-1].value;
		wt = objects[i-1].weight;
		
		for (int j = 1 ; j <= W ; j ++) {
		
			if (wt <= j)		v[i][j] = min (v[i-1][j-wt] + val , v[i-1][j]);
			else 				v[i][j] = v[i-1][j];
//			cout << v[i][j] << " ";
		}
//		cout << endl;
	}
	return v[objects.size()][W];
}

int main() {


	int t;
	cin >> t;
	while(t--) {
		
		int n,W;
		cin >> n >> W;
		
		vector<pair<int,int> > 	objects(n);
		
		//cout<<sizeof(objects[3]);
		
		int a,b;
		string str;
		int sum = 0;
		for (int i=0;i<n;i++) {
		
			cin >> str >> a >> b;
			objects[i] = make_pair(a,b);
			sum += a;
		}
		sort(objects.begin(),objects.end());
		cal_max_value(objects,sum,W);
//		cout << ans << endl;
//		cout << ks(objects,ans) << endl;
		
	}
}
