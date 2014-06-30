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
	int t;
	cin >> t;
	int temp = t/5+1;
	int n = log(temp)/log(2);
	int den = pow(2,n);
	int num = t - 5*(pow(2,n)-1);
//	cout << n << " " << num << " " << den << endl; 
	int ans = ceil((double)num/den);
	if(ans == 1)	cout << "Sheldon";
	else if(ans == 2)	cout << "Leonard";
	else if(ans == 3)	cout << "Penny";
	else if(ans == 4)	cout << "Rajesh";
	else	cout << "Howard";
	
}


