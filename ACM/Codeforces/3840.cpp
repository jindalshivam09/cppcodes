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
	int count = ceil(double(n)/2) * ceil(double(n)/2);
//	cout << count << endl;
	count  += (n/2) * (n/2);
	cout << count << endl;
	for(int i=0;i<n;) {
		for(int j=0;j<n;j++) 
			if(j%2==0)
				cout << "C";
			else
				cout << ".";
		cout << endl;
		i++;
		if(i<n) {
			for(int j=0;j<n;j++) 
				if(j%2==0)
					cout << ".";
				else
					cout << "C";
		}
		cout << endl;
		i++;
	} 
}


