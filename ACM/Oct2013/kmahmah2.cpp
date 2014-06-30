#include<iostream>
#include<vector>
#include<map>
using namespace std;


int min_moves(vector<pair<int,int> > &xy,int n) {
	
	map <int,int> x,y;
	
	for(int i=0;i<n;i++) {
		
		x[xy[i].first] ++;
		y[xy[i].second] ++;
	}
	
	int ans1 = min(x.size(),y.size());
	for(int i=0;i<n;i++) {
		
		int q = xy[i].first;
		int w = xy[i].second;					
	}
}

int main() {
		
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		vector<pair<int,int> > xy(n);
		
		int a,b;
		for(int i=0;i<n;i++)	{
			
			cin >> a >> b;
			xy[i] = make_pair(a,b);
		}

		cout << min_moves(xy,n) << endl;
	}
}
