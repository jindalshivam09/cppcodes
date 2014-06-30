#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n,m,k;
		cin >> n >> m >> k;
		vector<int> balls(n);
		
		for(int i=0;i<n;i++)
			cin >> balls[i];
			
		sort(balls.begin(),balls.end());
		
		int similar = 0;
		
		for(int i=0;i<n;) {
			
			int last = balls[i];
//			cout << last << endl;
			int count = 0;
			while(balls[i] == last) {
			
//				cout << balls[i] << " ";	 
				i++;
				count++;
			}
			if(count > 1)	similar++;
		}
		
//		cout << similar ;

		
	}
}
