/*
	Name: 2SAT problem
	Copyright: no rights
	Author: jindalshivam09
	Date: 16/03/14 12:40
	Description: 	Boolean Satis?ability (SAT) in a short sentence:
					– SAT is the problem of deciding (requires a yes/no answer) if
					there is an assignment to the variables of a Boolean formula
					such that the formula is satis?ed
 					Consider the formula (a ? b) ? (¬a ? ¬c)
					– The assignment b = True and c = False satis?es the formula!
					refer : G:\Algorithms docs/2SAT 
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
#define MAX 10009
#define NIL 0
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<vi> clauses;
int n,m;
vi cc , color , parent;
int components = 0;

void dfs_visit(int i) {
    color[i] = GRAY;
    for(int j=0; j<clauses[i].size();j++) {
    	int temp = clauses[i][j] ;
        if(color[temp] == WHITE) {
            parent[temp] = i;
            cc[temp] = cc[i];
            dfs_visit(temp);
        }
    }
    color[i]  = BLACK;
}

void dfs(int n) {
    for(int i=1;i<=n;i++) {
        if(color[i] == WHITE) {
            cc[i] = ++components;
            dfs_visit(i) ;
        }
    }
}

int neg(int a) {
	if ( a > n )
		return a-n;
	else
		return a+n;
}

void correct_val(int &a) {
	if( a < 0 )
		a =  n - a ;
}

void output () {
	
	repi(i,1,2*n+1) {
		cout << i << "-> " ;
		rep(j,clauses[i].size())
			cout << clauses[i][j] << " ";
		cout << endl;
	}
}

bool twoSAT () {
	dfs(2*n);
	for(int i=1;i<=n;i++)  {
		if(cc[i] == cc[neg(i)])
			return false;
	}
	return true;
}

// ----------------------to find SCC ----------------------------------------------------------

#define SCC true
#define CC false

vi finish , start ;
vb visited ;
int  tme = 1 , scc = 1 ;
struct node {
	int id , start , finish ,cc , scc;
} node[MAX] ;
void dfs (int i,bool flag) {
	visited[i] = true;
	node[i].id = i ;
	if(flag == SCC)
		node[i].scc = scc ;
	node[i].start= tme ++ ;
	rep(j,clauses[i].size()) {
		int v = clauses[i][j] ;
		if(visited[v]==false) {
			dfs(v,flag) ;
		}
	}
	node[i].finish = tme++ ;
}

bool cmp_time (const struct node &a,const struct node &b) {
	return a.finish > b.finish ;
}

bool cmp_id (const struct node &a,const struct node &b) {
	return a.id < b.id ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		clauses.resize(2*n+2);
		cc.resize(2*n+2,0);
		start.resize(2*n+2) ;
		finish.resize(2*n+2) ;
		color.resize(2*n+2,0);
		parent.resize(2*n+2,0);
		visited.resize(2*n+2) ;
		components = 0;
		scc = 1 ;
		int a,b ;
		bool mult = false ;
		rep(i,2*n+2)	
			cc[i] = color[i] = parent[i] = 0;
		rep(i,m) {
			cin >> a >> b ;
			correct_val(a) , correct_val(b);
//			cout << a << " " << b << endl;
			if(a == b)	continue;
			clauses[neg(a)].pb(b);
			clauses[neg(b)].pb(a);
		}
		output();
		bool satisify = twoSAT() ;
		if (satisify == false)
			cout << "CONFLICT" << endl;
		else {
			repi(i,1,2*n+1)	visited[i] = false;
			repi(i,1,2*n+1) if (visited[i]==false) {
				dfs(i,CC) ;	
			}
			repi(i,1,2*n+1)	visited[i] = false;
			sort(node+1,node+2*n+1,cmp_time);
			repi(i,1,2*n+1) {
				int u = node[i].id;
				if(!visited[u]) {
					dfs(u,SCC) ;
					scc ++;
				}
			}
			repi(i,1,2*n+1) if (visited[i] == false)
				satisify = false;
			if(satisify==false)
				cout << "UNIQUE"<< endl;
			else
				cout << "MULTIPLE" << endl;
		
		}
		clauses.clear();
//		cout << clauses.size() ;
	}
}


