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

	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int t;
	in >> t; 
	for(int test=1;test<=t;test++) {
		int n,c,k;
		in >> n >> k >> c;
		vi arr(n);
		int countzero = 0;
		int steps = imax;
		
		for(int i=1;i<=n;i++) {
			
			int zeroes = (n-i);
			int temp = k/i;
			int remain = k%i;
			int less = i-remain;
			int count=0;
			if(temp*i >= c) {
				count += zeroes + c;
			}
			else {
				count += zeroes + less + c;
			}
//			cout << count << " ";
			steps = min(steps,count);
		}
		out << "Case #" << test << ": ";
		out << steps << endl;
	}
}


