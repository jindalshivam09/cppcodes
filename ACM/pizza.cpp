#include<iostream>
#include<cstdlib>
#include<cstring>
#include<list>
#include<vector>
#define INT_MAX 1000000
#define MAX 100009
#define NIL 0
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

typedef long long ll;

list<int> planets[MAX];
int cc[MAX];
int color[MAX];
int parent[MAX];
int components = 0;

void add (int a,int b) {
    planets[a].push_back(b);
    planets[b].push_back(a);
    //cout << planets[a].front() << " ";
}

void dfs_visit(list<int> &u , int i) {
  //  cout << i << " dfs_visit..  ";
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
    /*for(int i=1;i<=n;i++) {
        //cout << planets[i].front() << " ";
        color[i] = WHITE;
        parent[i] = NIL;
    }*/
    //cout << "coloring done..";
    for(int i=1;i<=n;i++) {
        if(color[i] == WHITE) {
      //      cout << "nodes visiting..";
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

main() {
    int t;
    cin >> t;
    while(t--) {
	    int n,m,a,b;
	    cin >> n >> m;
	    
	   // memset(color,0,sizeof(color));
//	    memset(parent,0,sizeof(parent));
//	    memset(cc,0,sizeof(cc));
	    components = 0;
	    
	    for(int i=0;i<m;i++) {
	        cin >> a >> b;
	        add(a,b);
	    }
	
//		adjList(n);
	    dfs(n);
	
		vector<int> total(components+1); 
		for(int i=1;i<=n;i++) {
//			cout << cc[i] << " ";
			total[cc[i]]++;
		}
		
		int count=0,ans=0;
		int temp = -1;
		for(int i=1;i<=components;i++) {
		
			if(!(total[i]%2)) {
				count++;
				ans += total[i];
			}
			else {
				temp = max(temp,total[i]);
			}	
		}
		
		if(count == components)		cout << ans << endl;
		else						cout << ans+temp+1 << endl;
		
		for(int i=1;i<=n;i++) {
			color[i] = 0;
			planets[i].clear();
		}
	 
	}
}

