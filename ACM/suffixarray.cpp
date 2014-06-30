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

#define MAX 100
int n=0,var,length;
vi pos(MAX);
bool cmp (const pii &a,const pii &b) {
	
}

int main() {

	string str;
	cin >> str;
	
	length = str.size();
	
	vpii arr(length);
	
	rep(i,length) {
	
		pos[i] = str[i]-'a';
	}
	
	for(int i=0 ; i<length ; i = i << 1) {
		
		for(int j=0;j<length;j++) {
			
			arr[j].first = 
		}
	}
}


