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

#define MAX 100009

struct item {
	int id , val , ans ;
} item[MAX] ;

string str ;
bool cmp (const struct item &a, const struct item &b) {
	return a.val < b.val ;
}

bool cmp2 (const struct item &a, const struct item &b) {
	return a.id < b.id ;
}

int main() {
	int n , m ;
	cin >> n >> m ;
	cin >> str ;
	vi arr(n+1) ;
	rep(i,n)
		arr[i] = str[i] - '0' ;
	int idx ;
	rep(i,m) {
		cin >> idx ;
		idx -- ;
		item[i].id = i ;
		item[i].val = idx ;
		item[i].ans = 0;
	}
	sort(item,item+m,cmp) ;
	int index = 0 ;
	ll ans = 0;
	vi freq(10) ;
	rep(i,m) {
		int val = item[i].val; 
		while ( index < val ) {
			freq[str[index]-'0'] ++ ;
			index ++ ;
		}
//		cout << index << " " << val << endl;
		val = arr[val] ;
//		cout << val << endl;
		ans = 0;
		rep(i,10) {
//				cout << freq[i] << " " ;
				ans += freq[i]*abs(val-i) ; 
		}
//		cout << endl;
		item[i].ans  = ans ;
	}
	sort(item,item+m,cmp2) ;
	rep(i,m)
		cout << item[i].ans << endl;
}


