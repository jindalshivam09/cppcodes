#include <bits/stdc++.h>
#include<cstdio>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
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

#define MAX 109
int main() {

	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		long long int arr[109],input[100005];
		memset(arr,0,sizeof(arr));
		long long int a;
		for(int i=0;i<n;i++) {
		
			cin >> a;
			arr[a]++;
			input[i] = a;
		}	
		int k;
		cin >> k;
		long long ans = 0;
		for(int i=0;i<n;i++) {
			
			int temp = input[i];
			arr[temp]--;
			int ways = 0;
	//		if(k-temp > 0)
			ways = arr[k-temp];
			ans += ways;
		}
		
		cout << ans << endl;
	}
}


