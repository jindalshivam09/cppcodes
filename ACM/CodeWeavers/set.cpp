#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;

#define rep(n)    		for(int i=0;i<n;i++)
#define repi(k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()

struct node {
	
	int u,v;
	public:
		bool operator < (const node &a) const {
		
			return this->u < a.u;
		}
		bool operator = (const node &a) const {
		return false;
		//	return this->u == a.u ? this->v == a.v : this->u == a.u;
		}
};

int main() {

	set<node> p;
	node temp,temp2;
	temp2.u = temp.u = 1;
	temp.v = 2;
	temp2.v = 3;
	
	p.insert(temp);
	p.insert(temp2);
	
	set<node>::iterator i = p.begin();
	for(;i!=p.end();i++)
	
	cout << (*i).u << " " <<  i->v << endl ;
}


