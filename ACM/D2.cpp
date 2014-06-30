#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2009
int n,k;
vector<int> dp(MAX),arr(MAX);

bool possible (long long ca) {
	
	dp[0] = 0;
	
	for(int i=1;i<n;i++) {
		
		dp[i] = i;
		for(int j = 0 ; j < i ; j ++) {
			
			if( abs (arr[i] - arr[j]) < (long long)(i-j)*ca) 
				dp[i] = min ( dp[i] , dp[j] + i - j - 1 );
		}
		if (dp[i] + n - i <= k)		
			return true;
	}
	return false;
}

int main() {
	
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	if( n == 0 || n == 1) {
		
		cout << 0 << endl;
		return 0;
	}	
	
	long long l = -1 , r = 2000000000;
	long long m;
	
	while( r-l > 1) {
		
		m = (l+r)/2;
		cout << r << " " << l << " " << m << endl;
		if ( possible(m) ) 	
			r = m;
		else
			l = m;
	}
	
	cout << r << endl;
}
