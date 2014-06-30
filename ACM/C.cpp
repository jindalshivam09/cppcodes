#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main() {
	
	int n,m;
	cin >> n >> m;
	
	vector<int> t(m),l(m),r(m),val(m);
	vector<int> ans(n+1,1000000000),sum(n+1);
	
	for(int i=0;i<m;i++) {
		
		cin >> t[i] >> l[i] >> r[i] >> val[i];
		if( t[i] == 1) {
			
			for(int j = l[i] ; j <= r[i]; j ++) {
				
				sum[j] += val[i];
			}
		}
		else {
			
			for(int j=l[i] ; j <= r[i] ; j ++) {
				
				ans[j] = min (ans[j] , val[i] - sum[j] );
			}
		}
	}
	
//	sum.clear();
	vector<int> sum2(n+1);
	
	bool flag = true;
	for(int i=0 ; i<m ; i++) {
		
		if(t[i] == 1) {
			
			for(int j=l[i]  ; j <= r[i] ; j ++) {
				
				sum2[j] += val[i];
			}
		}
		else {
			
			int max_val = numeric_limits<int>::min();
			for(int j = l[i] ; j <= r[i] ; j ++) {
				
				max_val = max (max_val , sum2[j] + ans[j]);
			}
//			cout << max_val << endl;
			if (val[i] != max_val) {
				
				flag = false;
				break;
			}
		}
	}
	
	if(flag) {
		
		cout << "YES" << endl;
		for(int i=1;i<=n;i++) 
			cout << ans[i] << " ";
		cout << endl;
	}
	else 
		cout << "NO" << endl;
}
