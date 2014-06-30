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

vi arr ;

struct node {
	ll sum , five , ans;
};
vector<node> segment_tree ;

long long int calPow(int q,int n)
{
	 long long int ans;
	 if ( n == 0)	return 1;
	 if(n==1)	return q;
	 else{
		ans=calPow(q,n/2) ;
 		ans*=ans;
		if(n%2)	{
				  ans*=q;
		}
	}
	return ans;
}

void update(int num, int i, int j, int a, int b) {
//	cout << i << " " << j << " " << a << " " << b << " " << num << endl;
	if( j<a || i>b)
		return ;
	if ( a <= i && b >= j ) {
		segment_tree[num].five ++ ;
		segment_tree[num].ans = segment_tree[num].sum / 5 ;
		segment_tree[num].sum = ( segment_tree[num].ans / 5 ) * 5 ; 
		return ;
	}
	int mid = (i+j)/2 ;
	update(num*2,i,mid,a,b) ;
	update(num*2+1,mid+1,j,a,b) ;
	ll den = calPow(5,segment_tree[num].five) ;
	segment_tree[num].five = 0 ;
	segment_tree[num].ans = ( ( segment_tree[2*num].ans / den ) * den +  ( segment_tree[2*num+1].ans / den ) * den ) ;
	segment_tree[num].sum = (segment_tree[num].ans / den ) * den ; 
	
}

ll query(int num, int i, int j, int a, int b) {
	if ( j < a || i > b )
		return  0;
	if ( a <= i && b >= j ) {
		return segment_tree[num].ans ;
	}
	int mid = (i+j)/2 ;
	ll ans1 = query(num*2,i,mid,a,b) ;
	ll ans2 =  query(num*2+1,mid+1,j,a,b) ;
	cout << i << " " << mid <<  " " << j << endl;
	cout << ans1  << " " << ans2 << endl;
	return ans1+ans2 ;
}

int n;

void init_update(int num, int i,int j, int a, int b) {
	if ( j < a || i > b )
		return ;
	if ( a <= i && b >= j ) {
		segment_tree[num].ans = (arr[i]/5)*5 ;
		return  ;
		
	}
	int mid = (i+j)/2 ;
	init_update(num*2,i,mid,a,b) ;
	init_update(num*2+1,mid+1,j,a,b) ;
	segment_tree[num].ans = ( (segment_tree[2*num].ans + segment_tree[2*num+1].ans ) / 5 ) * 5 ; 
}

void init() {
	rep(i,n)
		init_update(1,1,n,i+1,i+1) ;
	cout << segment_tree[1].ans << endl;
}

int main() {
	cin >> n ;
	arr.resize(n+1) ;
	segment_tree.resize(4*n) ;
	rep(i,n)
		cin >> arr[i+1] ;
	init() ;
	int q ;
	cin >>q  ;
	while(q-- ) {
		int type, l , r;
		cin >> type >> l >> r ;
		if (type==1) 
			update(1,1,n,l,r) ;
		else
			cout << query(1,1,n,l,r) << endl;
	}
}


