#include<iostream>
#include<cstdlib>
#include<cstring>
#include<list>
#include<set>
#define INT_MAX 1000000
#define MAX 100000
#define NIL 0
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

typedef long long ll;

set<int> nodes;
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

void dfs_visit(list<int> u , int i) {
   // cout << i << " dfs_visit..  ";
    color[i] = GRAY;
    list<int>::iterator itr = u.begin();
    for( ; itr != u.end() ; itr++) {
      //  cout << *itr << " ";
        if(color[*itr] == WHITE) {
          //  cout << *itr << " ";
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
    for(int i=1 ; i <= n;  i++) {
        if(color[i] == WHITE) {
        //    cout << "nodes visiting.." << *i;
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
    int n,m,a,b;
    cin >> n >> m;
    int tax[n];
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        nodes.insert(a);
        nodes.insert(b);
        add(a,b);
    }

    //cout << "adding done..";
    for(int i=1 ; i<=n ; i++)
    cin >> tax[i];

    //cout << "tax add ...." ;
    if(n==1 ) {
        if(tax[1]>=0)
        cout << tax[1];
         cout << -1 ;
    }
    else{
        adjList(n);
        dfs(n);

        ll minTax[MAX];
       // memset(minTax,1,sizeof(minTax));
        for(int i=1;i<=n;i++)
        minTax[i] = MAX;

        for(int i=1 ; i<=n ; i++) {
            if(cc[i] > 0)
            //cout << cc[i] << " " << tax[i] << " " << minTax[cc[i]] << " ";
            if(minTax[cc[i]] > tax[i] && tax[i] >= 0)
            minTax[cc[i]] = tax[i];
        }
        for(int i=1;i<=n;i++)
        cout << " " << cc[i] << " ";
        cout << endl;
        ll sum = 0;
        int count=0;
        int min = MAX;
        for(int i=1;i<=components;i++) {
            if(minTax[i] < MAX) {
                sum += minTax[i];
                count++;
            }
        }
        for(int i=1;i<=n;i++)
        if(!cc[i])
        sum += tax[i];
        //cout << sum << " " << components << " ";
        if(count == components )
        cout << sum + min*(components-2);
      //  else if(n==1 && tax[1] >=0) cout << 0 << endl;
        else cout << -1;
    }
}
