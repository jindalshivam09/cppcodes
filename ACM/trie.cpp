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

class trie {
	
	int key;
	char value;
	trie *next , *child;
	public:
		trie(int k = 0 ,char a = 0) {
			this->key = k;
			this->value = a;
			this->next = NULL;
			this->child = NULL;
		}
		void addNode (string str,int key,int i=0) {
			
			trie *temp = this->next;
			while(temp) {
				if(temp->key == str[i])
					break;
				temp = temp -> next; 
			}
			if(!temp) z
		}
};
int main() {


}


