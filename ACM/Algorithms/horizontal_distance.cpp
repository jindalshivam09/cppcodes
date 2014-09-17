/*
	Name: find the horizontal distance between two nodes of a binary tree
	Copyright: no rights
	Author: jindalshivam09
	Date: 26/08/14 18:17
	Description: 
*/


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

typedef struct node {
	int leftsize, rightsize ;
	int left, right ;
}node;
vector<node> edges ;

int calculate_size ( int u ) {
	if(u == -1)
		return 0 ;
	int sz = 0 ;
	int temp = calculate_size( edges[u].left ) ;
	edges[u].leftsize = temp ;
	sz = temp ;
	temp = calculate_size( edges[u].right ) ;
	edges[u].rightsize = temp ;
	sz += temp ;
	return sz + 1 ;
}

vi position ;

void calculate_position ( int u, int ref ) {
	if (u == -1)
		return ;
	position[u] = ref + edges[u].leftsize ;	
	calculate_position (edges[u].left,ref) ;
	calculate_position (edges[u].right,ref+edges[u].leftsize+1) ;
}

int main() {
	int n ;
	cin >> n;
	position.resize(n+1) ;
	edges.resize(n+1) ;
	int a, b, c ;
	rep(i,n) {
		cin >> a >> b >> c;
		edges[a].left = b , edges[a].right = c ;
	}
	int root = 1 ;
	calculate_size(root) ; 
/*	rep(i,n) {
		cout << i+1 << "-> " ;
		cout << edges[i+1].leftsize << " " << edges[i+1].rightsize << endl;
	}
*/
	int reference = 0 ;
	calculate_position (root,reference) ;	
	rep(i,n)
		cout << i+1 << "-> " << position[i+1] << endl;
}



