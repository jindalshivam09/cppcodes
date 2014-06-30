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
#define INT_MAX 1000000
#define MAX 100009
#define NIL 0
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long ll;

list<int> planets[MAX];
int cc[MAX];
int color[MAX];
int parent[MAX];
int components = 0;

void add (int a,int b) {
    planets[a].push_back(b);
    planets[b].push_back(a);
}

void dfs_visit(list<int> u , int i) {
    color[i] = GRAY;
    list<int>::iterator itr = u.begin();
    for( ; itr != u.end() ; itr++) {
        if(color[*itr] == WHITE) {
            parent[*itr] = i;
            cc[*itr] = cc[i];
            dfs_visit(planets[*itr],*itr);
        }
    }
    color[i]  = BLACK;
}

void dfs(int n) {
    for(int i=1;i<=n;i++) {
        if(color[i] == WHITE) {
            cc[i] = ++components;
            dfs_visit(planets[i],i) ;
        }
    }
}
void adjList(int n) {
    for(int i=1;i<=n;i++) {
        cout << i << " ";
        for(list<int>::iterator itr = planets[i].begin() ; itr != planets[i].end(); itr++)
        cout << *itr << " ";
        cout << endl;
    }
}

int main() {
  	int n,m,a,b;
    cin >> n >> m;
    vi color(n+1);
    for(int i=1;i<=n;i++)
    	cin >> color[i];
	for(int i=0;i<m;i++) {
        cin >> a >> b;
        add(a,b);
    }
    dfs(n);
    vi freq(n+1);
    for(int i=1;i<=n;i++) {
		int temp = cc[i];
		if ( color[i] == 1) {
			freq[temp] ++;
		}
	}
	ll furik = 0 , rubik = 0;
    for(int i=1;i<=n;i++) {
		if (freq[i]>1) {
			rubik += freq[i];
			furik += (freq[i]*(freq[i]-1)) / 2;
		}
	}
	cout << furik << " " << rubik << endl;
}
