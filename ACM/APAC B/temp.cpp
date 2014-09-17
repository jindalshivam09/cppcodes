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

string nth(int numPairs,int N) {
	int q, p, c, c1, m;
  string str = "";
  q = numPairs;
  m = p = c = 1;
  while  (p < numPairs)  {
    p = p + 1;
    c = ((4 * p - 2) * c)/(p + 1);
  }
  cout << c << endl;
  N = c - (N - 1);
  while  (true)  {
    if  (q != 0)  {
      c1 = ((q + 1) * (q - p) * c)/((q + p) * (q - p + 1));
      if  (N > c1)  {
        p = p - 1;
        c = c - c1; 
        N = N - c1;
        str += "(";
        m = m + 1;
      }
      else {
        q = q - 1;
        c = c1;
        str += ")";
        m = m + 1;
      }
    }
    else break;
  }
  return str;
}


int main() {
	int t ;
	cin >> t;
	while(t--) {
		int numPairs,n ;
		cin >> numPairs >> n ;
		cout << nth(numPairs,n) << endl;
	}
}


