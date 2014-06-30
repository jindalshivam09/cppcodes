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
#define ull unsigned long long

ull l,d,s,c,temp;
bool calpow() {
	 ull ans=c;
	 vector<ull> powers;
	 ull i;
	 powers.pb(ans);
	 for(i=2;i<d;i*=2) {
	 	ans*=ans;
		powers.pb(ans);
		if(s*ans >= l)
			return true;
	}
	ull powl = 1;
	int count = 0,index =powers.size()-1;
	ull j=i/2;
	for(int k=0;k<powers.size();k++) {
		if(count+j<d) {
			count += j;
			powl *= powers[index];
		} 
		index--;
		if(s*powl >= l)
			return true;
		j /= 2;
	} 
		return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> l >> d >> s >> c;
		c++;
		if(calpow())
			cout << "ALIVE AND KICKING" << endl;
		else
			cout << "DEAD AND ROTTING" << endl;
	}
}


