#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp (const pair<int,pair<int,int > > &a , const pair<int, pair<int,int> > &b) {
	
	return a.second.first > b.second.first;
}


bool cmp2 (const pair<int,pair<int,int > > &a , const pair<int, pair<int,int> > &b) {
	
	return a.second.second > b.second.second;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		int inner = -1 , outer = -1;
		
		vector<pair<int,pair<int,int> > > rad(n), rad2(n);
		int r,R;
		for(int i=0;i<n;i++) {
	
			cin >> r >> R;
			rad[i] = make_pair(i+1,make_pair(r,R));
			rad2[i] = make_pair(i+1,make_pair(r,R));
		}
		
		sort(rad.begin(),rad.end(),cmp);
		sort(rad2.begin(),rad2.end(),cmp2);
		
/*		for(int i=0;i<n;i++) {
			
			cout << rad[i].first << " " << rad[i].second.first << endl;
			
			cout << rad2[i].first << " " << rad2[i].second.second << endl;
		}
*/	
		int max_r = rad[0].second.first;
		int index = rad[0].first;
		int max_R;
		
		if (rad2[0].first == rad[0].first)
			max_R = rad2[1].second.second;
		else
			max_R = rad2[0].second.second;
			
//		cout << max_r <<  " "<< max_R << endl;
		if (max_R < max_r)
			cout << index << endl;
		else
			cout << -1 << endl;
	}
}
