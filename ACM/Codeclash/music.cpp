#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define MAX 1000009
#define NIL 0
#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<int> differ(MAX);

list<int> singer[MAX];
int cc[MAX];
int color[MAX];
int parent[MAX];
int components = 0;


void add (int a,int b) {
    singer[a].push_back(b);
    singer[b].push_back(a);
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
            dfs_visit(singer[*itr],*itr);
        }
    }
    color[i]  = BLACK;
}

void dfs(int n) {
    for(int i=1 ; i <= n;  i++) {
        if(color[i] == WHITE) {
        //    cout << "nodes visiting.." << *i;
            cc[i] = ++components;
            dfs_visit(singer[i],i) ;
        }
    }
}
int main() {
	
	int n,m;
	cin >> n >> m;
	
	int a,b;
	for(int i=0;i<m;i++) {
		
		cin >> a >> b;
		add(a,b);
	}
	
	dfs(n);
	
	for(int i=1;i<=n;i++) {
		
		differ[cc[i]]++;
//		cout << cc[i] << " ";
	}
	vector<int> sum(n);
	for(int i=1;i<=components;i++) {
		
		if(i)		sum[i] = sum[i-1] + differ[i];
		else		sum[i] = differ[i];
	}
	long long ans = 0;
	for(int i=1;i<=components ; i++){
		
		ans += differ[i] * (sum[components]-sum[i]);
	}
	cout << ans << endl;
	 
			
}
