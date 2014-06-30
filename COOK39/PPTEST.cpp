#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp (const pair<int,int> &a,const pair<int,int> &b) {

	return a.first*b.second > a.second*b.first;
}


#define value first
#define weight second

int cal_max_value (const vector<pair<int,int> > &objects , int W) {

	vector<vector <int> >  v (objects.size()+1, vector<int>(W+1,0));


	int wt , val;
	for (int i = 1 ; i <= objects.size() ; i ++) {

		val = objects[i-1].value;
		wt = objects[i-1].weight;

		for (int j = 1 ; j <= W ; j ++) {

			if (wt <= j)		v[i][j] = max (v[i-1][j-wt] + val , v[i-1][j]);
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

		int n,w;
		cin >> n >> w;
		vector<int> p(n), t(n) , c(n) , mul(n);
		
		vector<pair<int,int> >  arr(n);
		
		for(int i=0;i<n;i++) {

			cin >> c[i] >> p[i] >> t[i] ;
			mul[i] = c[i] * p[i] ;
			arr[i] = make_pair(mul[i],t[i]);
		}
		
		cout << cal_max_value(arr,w) << endl;
	}
}
