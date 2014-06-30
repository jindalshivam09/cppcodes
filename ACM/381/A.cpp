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



int main() {
	int n;
	cin >> n;
	vi arr(n);
	int sereja = 0, dimmy = 0;
	rep(i,n)
		cin >> arr[i];
	int left = 0 , right = n-1;
	for(int i=0;i<n;i++) {
		if(i%2==0) {
			if(arr[left]>arr[right]) {
				sereja += arr[left];
				left++;
			}
			else {
				sereja += arr[right];
				right--;
			}
		}
		else {
			if(arr[left]>arr[right]) {
				dimmy += arr[left];
				left++;
			}
			else {
				dimmy += arr[right];
				right--;
			}
		}
	}
	cout << sereja << " " << dimmy << endl;
}


