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
#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 4000009
void scan(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}
struct node {
	int freq[3];
 	int count ;
} tree[MAX];
int n,q ;
void init (int pos,int a,int b) {
	if ( a == b ) {
		tree[pos].freq[0] ++;
		return;
	}
	int mid = (a+b)/2;
	init(2*pos,a,mid);
	init(2*pos+1,mid+1,b);
	tree[pos].freq[0] = tree[2*pos].freq[0] + tree[2*pos+1].freq[0];
}
void swap_val ( int pos ) {
	int temp = tree[pos].freq[2];
	tree[pos].freq[2] = tree[pos].freq[1];
	tree[pos].freq[1] = tree[pos].freq[0];
	tree[pos].freq[0] = temp;
}
void update ( int pos,int a,int b,int l,int r) {
	if ( b < l || a > r )
		return;
	if ( a <= l && b >= r ) {
		tree[pos].count++;
		swap_val(pos);
		return;
	}
	int mid = (l+r)/2;
	update (2*pos,a,b,l,mid);
	update (2*pos+1,a,b,mid+1,r);
	rep(i,3)	tree[pos].freq[i] = tree[2*pos].freq[i] + tree[2*pos+1].freq[i];
	rep(i,tree[pos].count%3)	swap_val(pos);
}
int query ( int pos,int a,int b,int l,int r,int count = 0) {
	if ( b < l || a > r )
		return 0;
	if ( a <= l && b >= r )
		return tree[pos].freq[(3-count%3)%3];
	int mid = (l+r)/2;
	count += tree[pos].count;
	return query(2*pos,a,b,l,mid,count) + query(2*pos+1,a,b,mid+1,r,count);
}
int main() {
	scan(n);
	scan(q);
	int a,b,c;
	init(1,1,n);
	while(q--) {
		scan(c);
		scan(a);
		scan(b);
		a ++ ;
		b ++ ;
		if ( c == 0 )
			update (1,a,b,1,n);
		else
			printf("%d\n",query(1,a,b,1,n));
	}
}
