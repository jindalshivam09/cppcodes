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
int n, m;
vi arr ;
typedef struct node {
	vi sorted_arr ;
} node;
vector<node> trees(MAX) ;

ll merge (int num) {
	int sz1 = trees[2*num].sorted_arr.size() ;
	int sz2 = trees[2*num+1].sorted_arr.size() ;
	int i=0,j=0;
	ll inversions = 0;
	vi arr ;
	vi arr1 = trees[2*num].sorted_arr , arr2 = trees[2*num+1].sorted_arr ;
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
		trees[num].sorted_arr.pb(arr[r]) ;
		return 0LL;
	}
	int mid = (l+r)/2 ;
	ll inversions = create_sorted_tree (2*num,l,mid) ;
	inversions += create_sorted_tree (2*num+1,mid+1,r) ;
	inversions += merge(num) ;
	return inversions ;
}

pii query ( int num, int i, int j, int a, int b, int key ) {
	if ( j < a || i > b )	
		return mp(0,0) ;
	if ( i <= a && j >= b) {
		int sz = trees[num].sorted_arr.size() ;
		int pos1 =  lower_bound (all(trees[num].sorted_arr),key) - trees[num].sorted_arr.begin() ;
		int pos2 =  upper_bound (all(trees[num].sorted_arr),key) - trees[num].sorted_arr.begin() ;
		int lesser = pos1;
		int same = pos2-pos1;
		int greater = sz - lesser - same ;
		return mp(lesser,greater) ;
	}
	int mid = (a+b)/2 ;
	pii ret1 = query(2*num,i,j,a,mid,key) , ret2 = query(2*num+1,i,j,mid+1,b,key) ;
	return mp(ret1.first+ret2.first,ret1.second+ret2.second) ;
}

int main() {
//	ifstream cin("test.txt") ;
//	ofstream cout("2.txt") ;

//	cin >> n >> m ;
	scanf("%d%d",&n,&m) ;
	arr.resize(n+1) ;
	rep(i,n)
		scanf("%d",&arr[i+1]) ;
//		cin >> arr[i+1] ;
	ll inversions = create_sorted_tree(1,1,n) ;
	int i, j;
	while(m--) {
//		cin >> i >> j ;
		scanf("%d%d",&i,&j) ;
		if(i>j)
			swap(i,j) ;
		if(arr[i] == arr[j]) {
//			cout << inversions << endl;
			printf("%lld\n",inversions) ;
			continue ; 
		}
		pii x = query(1,i+1,j-1,1,n,arr[i]) ;
		pii y = query(1,i+1,j-1,1,n,arr[j]) ;
		int lesser_than_x = x.first ;
		int greater_than_x = x.second  ;
		int lesser_than_y = y.first ;
		int greater_than_y = y.second ;
	//	cout << lesser_than_x << " " << lesser_than_y << " " << greater_than_x << " " << greater_than_y <<  endl;
 		ll ans = inversions + (greater_than_x-lesser_than_x) + (lesser_than_y-greater_than_y) ;
 		if(arr[i]>arr[j])
 			ans -- ;
 		else 
 			ans ++;
// 		cout << ans << endl;
		printf("%lld\n",ans) ;
	}
}


