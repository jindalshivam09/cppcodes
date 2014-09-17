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
	int n,m ;
	cin >> n >> m ;
	vi arr(n+1) ;
	rep(i,n)
		cin >> arr[i+1] ;
	int init = 1 ;
	char ch ;
	int pos ;
	while(m--) {
		cin >> ch >> pos ;
		if(ch == 'R')   {
			int index = (pos+init-1)%n ;
			if(index==0)
				index = n ;
			cout << arr[index] << endl;
		}
		else if (ch == 'C') {
			init = (init+pos)%n ;
			if(init==0)
				init = n ;
		}
		else {
			int temp = (n-pos) ;
			init = (init+temp)%n;
			if(init==0)
				init = n ;
		}
	}
}


