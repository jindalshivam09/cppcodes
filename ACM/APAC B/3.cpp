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
int cnt = 0,n,k;
string str ;
void brute(int l, int r, string s) {
//	cout << l << " " <<r  << endl;
	if(l==0&&r==0) {
		cnt ++;
		if(cnt == k) {
//			cout << s << endl;
//			return s;
			str = s ;
		}
		return ;
	}
	if(r==0 || l<0)
		return ;
	if(l)
		brute(l-1,r,s+"(") ;
	if(l<r)
		brute(l,r-1,s+")") ;
}

int main() {


	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;

	int t;
	cin >> t ;
	for(int test=1;test<=t;test++) {
		cin >> n >> k ;
		string s = "";
		cout << "Case #" << test << ": ";
		brute(n,n,s);
		if(str.size())
			cout << str ;
		else
			cout << "Doesn't Exist!";
		cout << endl;
		str.clear() ;
	}
}


