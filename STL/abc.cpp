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

bool cmp(const int &a,const int &b) {
	return a>b;
}

int main() {

	int n;
	cin >> n ;
	vector<int> arr(n);
	rep(i,n) 
		cin >> arr[i];
	sort(all(arr));
	vector<int>::iterator itr; 
	
	int count = 0;
	for(int i=n-1;i>=0;i--) {
		int temp = 2*arr[i];
		cout << temp << " ";
		itr = lower_bound(all(arr),temp);
		if(itr != arr.end()) {
			count ++;
			arr.erase(itr);
//			arr.erase(i);
		}		
		else
			count ++;
	}
	cout << count << endl;
}


