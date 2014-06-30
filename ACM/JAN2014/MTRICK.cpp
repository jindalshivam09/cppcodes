#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long 		ull;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<unsigned long long> 	vull;
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

ull mulmod(ull a,ull b,ull c) {
	ull x=0,y=a%c;
	while(b>0) { 
		if(b%2)
			x = (x+y)%c;
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ull n;
		cin >> n;
		vull l(n);
		rep(i,n)
			cin >> l[i];
		ull a,b,c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		ull front = 0 , last = n-1;
		ull mul = 1, temp = 0;
		char ch;
		bool rev = false ;
		rep(i,n) {
			ch = s[i];
			if(ch=='A') 			temp = (temp+a%c)%c;
			else if(ch=='M')		mul = mulmod(mul,b,c) , temp = mulmod(temp,b,c);
			else {
				if(!rev)
					rev = true;
				else
					rev = false;
			}
			if(rev) {
				cout << (mulmod(l[last],mul,c) + temp%c)%c;
				last--;
			}
			else {
				cout << (mulmod(l[front],mul,c) + temp%c)%c;
				front++;
			}
			cout << " ";
		}
		cout << endl;
	}
}
