#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
vector<int> mice, holes ;

bool possible(int val) {
	int i=0,j=0;
	while(i<n) {
		while(j<m && abs(mice[i]-holes[j]) > val)
			j++;
		if(j == m)
			return false;
		i++, j++;
	}
	return true;
}


int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n >> m ;
		mice.resize(n) ;
		holes.resize(m) ;
		for(int i=0;i<n;i++)
			cin >> mice[i] ;
		for(int i=0;i<m;i++)
			cin >> holes[i] ;
			
		sort(mice.begin(),mice.end()) ;
		sort(holes.begin(),holes.end()) ;
		
		int ans, a = 0, b = 200000000;
		
		while(a<=b) {
			int mid = (a+b)/2 ;
			if(possible(mid)) {
	//			cout << mid << endl;
				ans = mid, b = mid-1;
			}
			else
				a = mid+1;
		}
		cout << ans << endl;
	}
}
