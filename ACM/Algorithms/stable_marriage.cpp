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
#define MAX 509
vector<vi > male(MAX,vi(MAX)) , female(MAX,vi(MAX));
vi male_match(MAX) , female_match(MAX);
int n;
int preference ( int u ,int v ) {
	rep(i,n) {
		if ( female[u][i] == v )
			return i+1;
	}
}
void stable_marriage () {
	queue<int> q ;
	rep(i,n)
		q.push(i+1);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i=0;i<n;i++) {
			int u = male[v][i];
//			if ( u == -1 )
//				continue ;
			if ( female_match[u] == 0 ) {
				male_match[v] = u;
				female_match[u] = v ;
				break;
			}
			else {
				int already_matched = female_match[u] ;
				int p1 = preference(u,already_matched) ;
				int p2 = preference(u,v);
				if ( p2 < p1 ) {
					q.push(already_matched) ;
//					male[already_matched][u] = -1;
					male_match[v] = u;
					female_match[u] = v ;
					male_match[already_matched] = 0 ;
					break;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int a,b;
		rep(i,n) {
			cin >> a ;
			rep(j,n)  {
				cin >> b ;
				female[a][j] = b;
			}
		}
		rep(i,n) {
			cin >> a ;
			rep(j,n)  {
				cin >> b ;
				male[a][j] = b;
			}
		}
		stable_marriage() ;
		rep(i,n)
			cout << i+1 << " " << male_match[i+1] << endl;
		rep(i,n)
			male_match[i+1] = female_match[i+1]  = 0;
	}
}


