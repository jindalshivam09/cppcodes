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
	string str;
	cin >> str;
	char ch;
	for(int i=0;i<str.size();i++) {
		ch = str[i];
		if(ch == 'a' || ch == 'A')
			continue;
		if(ch == 'e' || ch == 'E')
			continue;
		if(ch == 'i' || ch == 'I')
			continue;
		if(ch == 'o' || ch == 'O')
			continue;
		if(ch == 'u' || ch == 'U')
			continue;
		if(ch == 'y' || ch == 'Y')
			continue;
		else {
			cout << "." ;
			if (ch >= 'a' && ch <= 'z')
				cout << ch;
			else {
				ch = ch + 32;
				cout << ch ;
			}
		}	
	}
}


