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

int n ;
vi A, B ;

int min_steps() {
	vi diff(n) ;
	rep(i,n) {
		int a = A[i] , b = B[i] ;
		if( b >= a )
			diff[i] = b - a ;
		else
			diff[i] = 4 + b - a ;
	}
	vi distinct ;
	for(int i=0;i<n;) {
		int temp = diff[i] ;
		while(temp == diff[i]) 
			i++ ;
		distinct.pb(temp) ;
	}
	int size = distinct.size() ;
	int max_flow = distinct[0]+4 , min_flow = distinct[0] ;
	int ans1 = max_flow , ans2 = min_flow ;
	repi(i,1,size) {
		int temp1=0, temp2=0 , temp3=0, temp4=0 ;
		if(distinct[i]+4 > max_flow) 
			temp1 = distinct[i]+4 - max_flow ;
		if(distinct[i] > max_flow)
			temp2 = distinct[i]- max_flow;
		if(distinct[i]+4 > min_flow) 
			temp3 = distinct[i]+4 - min_flow ;
		if(distinct[i] > min_flow)
			temp4 = distinct[i]- min_flow;		
		max_flow = distinct[i]+4 , min_flow = distinct[i] ; 
		int temp = ans1 ;
		ans1 = min(ans1+temp1,ans2+temp3) ;
		ans2 = min(temp+temp2,ans2+temp4) ;
	}
	return min(ans1,ans2) ;
}

int main() {
	ifstream cin("test_SEINC.txt") ;
	ofstream cout("SEINC.txt") ;

	int t ;
	cin >> t ;
	while(t--) {
		cin >> n ;
		A.resize(n) ;
		B.resize(n) ;
		rep(i,n)
			cin >> A[i] ;
		rep(i,n)
			cin >> B[i] ;
		cout << min_steps() << endl;
	}
}


