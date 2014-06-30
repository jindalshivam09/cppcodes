#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef unsigned int ui;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vui;
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
#define LEVEL 20
ui n,k;

class trie {
	public:
		class trie *left , *right ;
		ui leftc , rightc ;
		class trie* insert(class trie * root , ui q  , ui pos) {
			if(pos==-1)		return NULL; 
			ui v = ( q >> pos ) & 1 ;
			if ( !v ) {
				root->leftc ++ ;
				if ( root->left == NULL) {
					root->left = new class trie ;
					root->left->leftc = root->left->rightc = 0;
				}
				root->left = insert(root->left,q,pos-1);
			}
			else {
				root->rightc ++ ;
				if ( root->right == NULL) {
					root->right = new class trie ;
					root->right->leftc = root->right->rightc = 0;
				}
				root->right = insert(root->right,q,pos-1);				
			}
			return root;
		}
		ui query (class trie *root, ui q, ui pos) {
			if(pos==-1 || root==NULL)	return 0;
			ui v = ( q >> pos ) & 1 ;
			ui u = ( k >> pos ) & 1;
			if ( u ) {
				if ( v )		return root->rightc + query(root->left,q,pos-1);
				else			return root->leftc + query(root->right,q,pos-1);
			}
			else {
				if ( v )		return query (root->right,q,pos-1);
				else			return query (root->left,q,pos-1);
			}
		}
};

int main() {
	ui t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		class trie* root = new class trie;
		root->left = root->right = NULL;
		root->leftc = root->rightc = 0;
		root = root->insert(root,0,LEVEL);
		ui p , q = 0;  
		ll ans = 0;
		rep(i,n) {
			cin >> p;
			q = q^p;
			ans += root->query(root,q,LEVEL);
			root = root->insert(root,q,LEVEL);
		}
		cout << ans << endl;
	}
}
