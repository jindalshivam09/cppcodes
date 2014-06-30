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
#define MAX 500009
char input[MAX] , pattern[2*MAX];
vi prefix(MAX);
int m,p,length;
void prefix_func () {
	prefix[0] = 0;	
	int k = 1 , len = 0;
	while ( k < length ) {
		if ( pattern[len] == pattern[k] ) {
			len++;
			prefix[k++] = len;
		}
		else {
			if ( len )
				len = prefix[len-1];
			else
				prefix[k++] = 0;
		}
	}
	int count = 0;
	for(int i=2*length;i>=0;i--){
		if (prefix[i]) 
			prefix[i] = ++count;
		else
			prefix[i] = count = 0 ;
	}
	rep(i,2*length)
		cout << prefix[i] << " ";
}
int main() {
	int t;
	cin >> t ;
	while(t--) {
		scanf("%s",input) ;
		length = strlen(input);
		cin >> m >> p ;
		rep(i,length)
			pattern[i] = input[i] ;
		rep(i,length) 
			pattern[i+length] = input[i]  ;
		prefix_func();
	}
}
