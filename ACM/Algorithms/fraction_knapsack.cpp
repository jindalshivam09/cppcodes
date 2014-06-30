/*
	Name: Fractional knapsack problem O(n)
	Copyright: shobhit saxena
	Author: Shivam Jindal
	Date: 04/09/13 13:51
	Description: using divide and conquer approach and selection in expected linear time
				
			knapsack(W , p, q)
				
				median = find_median(p,q);
				wt = cal_wt;
				val = cal_val;
				
				if (wt == W)	return val;
				if (wt < W)		return val + knapscak (W-wt , p ,median);
				if (wt > W)     return knapsack (W,median,q);
	
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define value first
#define weight second.first
#define fraction second.second
#define VALUE true
#define WEIGHT false

void swap (vector<pair<int,pair<int,float> > > &object , int p , int q) {
	
	pair<int,pair<int,float> > temp = object[p];
	object[p] = object[q];
	object[q] = temp;
}

int find_median (vector<pair<int,pair<int,float> > > &object , int p, int q ,int r) {
	
	pair<int,pair<int,float> > pivot = object[q-1];
	int i = p - 1;
	
	for (int j = p ; j < q-1 ; j ++) {
	
		if (object[j].fraction <= pivot.fraction) {
		
			i++;
			swap (object , i , j);
		}
	}
	swap (object , i+1 , q-1);
	
	return i+1;
/*	
	if (r == i+1)			return i+1;
	else if (r < i+1) 		return find_median (object,p,i,r);
	else					return find_median (object,i+2,q,r);
*/	
}

int cal_weight (vector<pair<int,pair<int,float> > > &object , int p  , int q ) {

	int sum = 0;

		for (int i = p ; i < q ; i ++) 
			sum += object[i].weight;
	
	return sum ;
}

int cal_value (vector<pair<int,pair<int,float> > > &object , int p, int q  ) {

	int sum = 0;

		for (int i = p ; i < q ; i ++) 
			sum += object[i].value;
	
	return sum ;
}

float knapsack (vector<pair<int,pair<int,float> > > &object , int W , int p , int q)  {

	int r = find_median (object,p,q,(p+q)/2);
	float sum = cal_weight (object,r,q);
	int val = cal_value (object,r,q) ;
	
//	cout << r << " " << sum << " "  << val << endl;
	
	if (sum == W) {
	
		return  val ;
	}
	
	else if (sum < W) {
	
		return val + knapsack(object , W-sum , p , r);
	}
	else  {
		
		int diff = sum - W ;
//		cout << diff << " "  << object[r].weight << " " <<  object[r].value <<  " " << object[r].fraction << endl ;
		if (diff <= object[r].weight) {
			
			return (val - object[r].value + (float)(object[r].weight-diff)*(float)object[r].fraction); 
		}
		else {
			
			return knapsack (object, W , r , q);
		}
	}
}

int main() {

	int n , W;
	cin >> n >> W;
	vector<pair<int,pair <int,float> > >	object(n);
	
	int val,wt;
	for (auto &i : object) {
		
		cin >> val >> wt;
		i = make_pair (val,make_pair(wt,(float)val/wt));
	}
	
	cout << knapsack (object,W,0,n);
}
