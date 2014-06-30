#include <bits/stdc++.h>
#include <regex>
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
#define all(a) 			a.begin() 	,a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

regex reg ;
string pattern = "[^abc]{2,}" ;
string text = "shivam" ;
regmatch matches[1] ;


int main() {
	regcomp ( &reg , pattern.c_str() , REG_EXTENDED | REG_ICASE ) ;
	if ( regexec(&reg,text.c_str(),1,matches,0) == 0 ) {
		cout << "match found  : " << endl;
		cout << text.substr ( matches[0].rm_so , matches[0].rm_eo - matches[0].rm_so ) << endl;
	}
	else
		cout << "no matches found..." ;
}	
