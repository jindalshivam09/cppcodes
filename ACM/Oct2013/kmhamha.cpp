#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<limits>
using namespace std;

bool cmpx(const pair<int,int> &a,const pair<int,int> &b) {
	
	 if(a.first != b.first)		return a.first < b.first;
	 else						return a.second < b.second;
}


int min_moves(vector<pair<int,int> > &xy,int n) {
	
	int ans=0;
	
	sort(xy.begin(),xy.end(),cmpx);
	
	for(int i=0;i<n;i++) {
		
		int x = xy[i].first;
		int y = xy[i].second;
		int count_x=0,count_y=0;
		
		if(x!=-1 && y!=-1) {
			
			cout << x << " " << y << endl;
			for(int j=0;j<n;j++) {
				
				if(x==xy[j].first)		count_x++;
				if(y==xy[j].second)		count_y++;
			}
			
			cout << count_x << " " << count_y << endl;
			
			if(count_x >= count_y) {
				
				for(int j=0;j<n;j++)  {
					
					if(x==xy[j].first) {
							
						xy[j].first = xy[j].second = -1;
					}
				}
				
			}
			else {
				
				for(int j=0;j<n;j++)  {
					
					if(y==xy[j].second) {
						
						xy[j].first = xy[j].second = -1;
					}
				}
			}
			ans++;
		}
		
		
	}		
	
	return ans;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		vector<pair<int,int> > xy(n);
		int a,b;
		
		for(int i=0;i<n;i++){
			cin >> a >> b;
			xy[i] = make_pair(a,b);
		}
		
		cout << min_moves(xy,n) << endl;
	}
}
