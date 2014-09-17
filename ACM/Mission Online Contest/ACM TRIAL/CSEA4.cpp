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

string input ;
vi number(26) ;
vb banned ;
bool permuted_twice () {
	vi mapped(26) ;
	bool flag = false ;
//	cout <<  input << endl;
	int pos,cur,assignedval,finalval ;
	for(int i=0;i<input.size();i++) {
		if(banned[i])
			continue ;
		pos = 0 ;
		mapped[pos] = i ;
		vb used(26) ;
//		cout << i << endl;
		used[pos] = true ;
		bool ok = true ;
		rep(j,input.size()-1) {
			finalval = number[pos] ;
			assignedval = mapped[pos] ;
			if(used[assignedval]) {
				ok = false ;
				break;
			}
			used[assignedval] = true ;			
//			cout << pos << " " << assignedval << " " << finalval << endl;
			
			mapped[assignedval] = finalval ;
			pos = assignedval;	
		}
//		cin.get() ;
		if(ok)
			return ok ;
	}
	return false ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		string str  ;
		cin >> str ;
		bool flag = false ;
		banned.clear() ;
		input.clear() ;
		banned.resize(26) ;
		rep(i,str.size()) {
			if(str[i]-'A' != i) {
				
				flag = true ;
				input.pb(str[i]);
			}
			else 
				banned[i] = true ;
		}
//		cout << input << endl;
		rep(i,input.size()) 
			number[i] = input[i]-'A' ;
		if(flag == false) {
			cout << "Yes" << endl;
			continue ;
		}
		if(permuted_twice())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}


