#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int, int> > vpii;
typedef vector<double> 	vd;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {

	int n;
	cin >> n;
	int c;
	cin >> c;
	
	vi arr(n),ans(n);
	
	int tot=0;
	for(int i=0;i<n;i++){
	
		cin >> arr[i];
		tot += arr[i];
	}
		
	sort(arr.begin(),arr.end());
	
	int avg = c/n;
	
	if(tot < c){
		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	int temp = 0;
	for(int i=0;i<n-1;i++) {
		
		if(avg >= arr[i] ) {
			
			ans[i] = arr[i];
			c -= arr[i];
		}
		else{
		
			ans[i] = avg;
			c -= avg;
		}
			
		avg = c/(n-i-1);
//		temp += ans[i];
//		c -= arr[i];
	}
		
	ans[n-1] = c;
	
	for(int i=0;i<n;i++)
	cout << ans[i] << endl;
}


