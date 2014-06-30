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
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	int t;
	cin >> t;
	rep(test,t) {
		cout << "Case #" << test+1 << ": " ;
		int n ;
		cin >>  n ;
		vector<string> inputs(n) ;
		rep(i,n)
			cin >> inputs[i] ;
		vector<vector<pair<char,int> > > traverse(n) ;
		rep(i,n) {
			for(int j=0;j<inputs[i].size();) {
				char ch = inputs[i][j] ;
				int cnt = 0;
				while(ch == inputs[i][j]) {
					cnt ++ ;
					j ++ ;
				}
				traverse[i].pb(mp(ch,cnt)) ;
			}
		}
		int steps = 0 ;
		bool flag ;
		rep(i,traverse[0].size()) {
			vi arr; 
			char last = traverse[0][i].first ;
//			cout << last << "->" ;
			flag = false ;
			rep(j,n) {
				if(traverse[j].size() != traverse[0].size()) {
					flag = true;
					break;
				}
				int cnt = traverse[j][i].second ;
				char ch = traverse[j][i].first ;
//				cout << cnt << " " << ch << endl;
				if(ch == last) {
					arr.pb(cnt) ;
				}
				else {
					flag = true ;
					break ;
				}
			}
			if(flag == true)
				break;
				
			sort(all(arr)) ;
			rep(j,arr.size())
				steps += abs(arr[j] - arr[arr.size()/2]) ;
			
		}
		if(flag) 
			cout <<  "Fegla Won" ;
		else
			cout << steps ;
		cout << endl;				
	}
}


