#include <bits/stdc++.h>
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

#define MAX 100009
vll max_right(MAX) , max_left(MAX);

void kadane (const vll  &arr , int n ) {
	ll max_till_yet = arr[0];
	ll sum = arr[0];
	
	max_left[0] = max_till_yet ;
	if(sum < 0)
		sum = 0;
	for (int i = 1 ; i < n ; i ++)  {
		sum += arr[i];
		max_till_yet = max ( max_till_yet , sum);			
		max_left[i] = max_till_yet;
		if(sum < 0)
			sum = 0;
	}
	
	max_till_yet = arr[n-1];
	sum = arr[n-1];
	max_right[n-1] = max_till_yet;
	if(sum < 0)
		sum = 0;
	for (int i = n-2 ; i >= 0 ; i --)  {
		
		sum += arr[i];
		max_till_yet = max ( max_till_yet , sum);			
		max_right[i] = max_till_yet;
		if(sum < 0)
			sum = 0;
	}
}


int main() {

	int t;
	cin >> t;
	while(t--) {
		
		int n,k;
		cin >> n >> k;
		vll arr(n);
		for(int i=0;i<n;i++)
			cin >> arr[i];
		kadane(arr,n);
/*		for(int i=0;i<n;i++)
			cout << max_left[i] << " ";
		cout << endl;
		
		for(int i=0;i<n;i++)
			cout << max_right[i] << " ";
		cout << endl;
*/		
		ll max_sum = imin;
		for(int i=0;i+k+1<n;i++) {
			
			max_sum = max(max_sum , max_left[i] + max_right[i+k+1]);
		}
		cout << max_sum << endl;
	}
}


