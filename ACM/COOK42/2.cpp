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

int countsteps (int a,int b) {
	int count = 0;
	int temp = 0;
	while(a!=b && a && b) {
//		cout << a << " " << b << endl;
		if(a<b) {
			b = b%a;
		}
		else {
			a = a%b;
		}
		count++;			
	}
	return count;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a,b;
		int count = 0;
		bool flag = false;
		for(int i=0;i<n;i++) {
			cin >> a >> b;
			if(countsteps(a,b)==2)
				count++ , flag = true;
		}
		if(n==count)
			cout << "NO";
		else
			cout << "YES";
		cout << endl;
	}
}


