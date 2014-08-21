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

vi arr ;
set<int> ans ;

void func() {
	ll sum = accumulate(all(arr),0) ;
	vb visited(sum+1) ;
	for(int i=2;i<=sum;i++) {
//		cout << i <<  "->";
		if(visited[i]==false) {
			int temp = 0 ;
			bool possible = true ;
			rep(j,arr.size()) {
//				cout << temp << " " << arr[j] << ", " ;
				if(temp > i) {
					possible = false ;
					break ;
				}
				if(temp == i)
					temp = 0;
				temp += arr[j] ;
			}
			for(int k=i;k<=sum && possible;k+=i) {
				visited[k] = true;
				if(sum%k == 0)
					ans.insert(k);
			}
		}
//		cout << endl;
	}
}

int main() {
	int t ;
	cin >> t ;
	arr.resize(t) ;
	bool one = true ;
	rep(i,t) {
		cin >> arr[i] ;
		if (arr[i] != 1)
			one = false ;
	}
	
	func() ;
	
	if(one)
		ans.insert(1) ;
	
	for(set<int>::iterator itr = ans.begin() ; itr != ans.end() ; itr ++ ) 
		cout << (*itr) << " " ;
}

// 1 2 1 1 1 2 1 3
