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
#define MAX 1000000
ll n, m;
vll arr ;
typedef struct node {
	vll sorted_arr ;
} node;
vector<node> trees(MAX) ;


ll merge (ll num) {
	ll sz1 = trees[2*num].sorted_arr.size() ;
	ll sz2 = trees[2*num+1].sorted_arr.size() ;
	ll i=0,j=0,inversions = 0;
	vll arr ;
	vll arr1 = trees[2*num].sorted_arr , arr2 = trees[2*num+1].sorted_arr ;
	while(i<sz1 && j<sz2) {
		if(arr1[i] <= arr2[j]) 
			arr.pb(arr1[i++]) ; 
		else
			arr.pb(arr2[j++]) , inversions += (sz1-i) ;
	}
	while(i<sz1) 	
		arr.pb(arr1[i++]) ;
	while(j<sz2) 
		arr.pb(arr2[j++]) ;
	trees[num].sorted_arr = arr ;
	return inversions ;
}

ll create_sorted_tree (ll num, ll l, ll r) {
	if ( l == r ) {
		trees[num].sorted_arr.pb(arr[l]) ;
//		cout << arr[l] <<  endl;
		return 0;
	}
	ll mid = (l+r)/2 ;
	ll inversions = create_sorted_tree (2*num,l,mid) ;
	inversions += create_sorted_tree (2*num+1,mid+1,r) ;
	inversions += merge(num) ;
	return inversions ;
//	rep(i,trees[num].sorted_arr.size())
//		cout << trees[num].sorted_arr[i] << " ";
//	cout << endl;
}

pii query ( ll num, ll i, ll j, ll a, ll b, ll key ) {
	if ( j < a || i > b )	
		return mp(0,0) ;
	if ( i <= a && j >= b) {
		int sz = trees[num].sorted_arr.size() ;
		ll pos1 =  lower_bound (all(trees[num].sorted_arr),key) - trees[num].sorted_arr.begin() ;
		ll pos2 =  upper_bound (all(trees[num].sorted_arr),key) - trees[num].sorted_arr.begin() ;
		int lesser = pos1;
		int same = pos2-pos1;
		int greater = sz - lesser - same ;
		return mp(lesser,greater) ;
	}
	ll mid = (a+b)/2 ;
	pii ret1 = query(2*num,i,j,a,mid,key) , ret2 = query(2*num+1,i,j,mid+1,b,key) ;
	return mp(ret1.first+ret2.first,ret1.second+ret2.second) ;
}

int main() {
	ifstream cin("test.txt") ;
	ofstream cout("2.txt") ;

	cin >> n >> m ;
//	n = 200000,m=n;
	arr.resize(n+1) ;
	rep(i,n)
		cin >> arr[i+1] ;
//	arr[i+1] = n-i;
	ll inversions = create_sorted_tree(1,1,n) ;
	ll i, j;
	while(m--) {
		cin >> i >> j ;
//		i = n-m, j=m;
		if(i>j)
			swap(i,j) ;

		if(arr[i] == arr[j]) {
			cout << inversions << endl;
			continue ;
		}
		pii x = query(1,i+1,j-1,1,n,arr[i]) ;
		pii y = query(1,i+1,j-1,1,n,arr[j]) ;
		int lesser_than_x = x.first ;
		int greater_than_x = x.second  ;
		int lesser_than_y = y.first ;
		int greater_than_y = y.second ; ;
	//	cout << lesser_than_x << " " << lesser_than_y << " " << greater_than_x << " " << greater_than_y <<  endl;
 		ll ans = inversions + (greater_than_x-lesser_than_x) + (lesser_than_y-greater_than_y) ;
 		if(arr[i]>arr[j])
 			ans -- ;
 		else if (arr[i] < arr[j])
 			ans ++;
 		cout << ans << endl;
 //		cin.get();
	}
}


