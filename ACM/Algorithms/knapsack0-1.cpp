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
#include<limits>
using namespace std;

#define value first
#define weight second
#define ll long long

ll cal_max_value (const vector<pair<ll,ll> > &objects , ll W) {

	vector<vector <ll> >  v (objects.size()+1, vector<ll>(W+1,0));
	 
	
	ll wt , val;
	for (ll i = 1 ; i <= objects.size() ; i ++) {
	
		val = objects[i-1].value;
		wt = objects[i-1].weight;
		
		for (ll j = 1 ; j <= W ; j ++) {
		
			if (wt <= j)		v[i][j] = max (v[i-1][j-wt] + val , v[i-1][j]);
			else 				v[i][j] = v[i-1][j];
//			cout << v[i][j] << " ";
		}
//		cout << endl;
	}
	
/*	for(ll i=1;i<=objects.size();i++) {
		
		for(ll j=1;j<=sum;j++) 
			cout << v[i][j] << " ";
		cout << endl;
	}
*/	
/*	ll cost = numeric_limits<ll>::max() , pl = W; 
	
		
		for(ll j=0;j<sum;j++) {
			
			if(pl <= v[objects.size()][j] && cost > j) {
				
				pl = v[objects.size()][j];
				cost = j;
				break;
			}
		}
	
	
	cout << cost << " " << pl << endl;
*/	return v[objects.size()][W];
	
}


int main() {

	ll n,W;
	cin >> n >> W;
	
	vector<pair<ll,ll> > 	objects(n);
	
	//cout<<sizeof(objects[3]);
	
	ll a,b;
	ll sum = 0;
	for (int i=0;i<n;i++) {
	
		cin >> a >> b;
		objects[i] = make_pair(a,b);
//		sum += b;
	}
	
	cout << cal_max_value(objects,W);
}
