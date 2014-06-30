#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

#define MAX 3509
#define INFINITE numeric_limits<int>::max()
vector<int> weight(MAX,INFINITE);
vector<int> parent(MAX,INFINITE);
class vertice{
	public:
		int v;
		int wt;
		vertice(int a=0,int b=0) {
			
			v = a;
			wt = b;
		}
		bool operator() (const vertice &a,const vertice &b) const {
			
			return a.wt < b.wt;
		}
		bool operator < (const vertice &a) const {
		
			return this->wt < a.wt;
		}
};
	priority_queue<vertice> Q ;

void dijsktra(int e,int v,list<pair<int,int> > *edges,int source) {
	
	Q .push(vertice(source,0));
	
	weight[source] = 0;
	
	while(!Q.empty()) {
		
		vertice v = Q.top();
		Q.pop();
		int u = v.v;
		int wu = v.wt;
	
		for(list<pair<int,int> >::iterator i = edges[u].begin() ; i != edges[u].end() ; i ++) {
			
			int v = i->first;
			int wv = i->second;
			if(weight[v] > wv + weight[u]) {
				
				weight[v] = wv + weight[u];
				parent[v] = u;
				Q.push(vertice(v,weight[v]));
			}
			
		}
	}
}
	list<pair<int,int> >  edges[MAX];

int main() {
	
	int e,v;
	cin >> v >> e;
	
	int a,b,wt;
	for(int i=0;i<e;i++) {
		
		cin >> a >> b ;
		edges[a].push_back(make_pair(b,1));
		edges[b].push_back(make_pair(a,1));
	}
	int source,destination;
	cin >> source >> destination;
	dijsktra(e,v,edges,source);
	
//	for(int i=0;i<v;i++) 
//	cout << weight[i] << endl;
	if(weight[destination]==INFINITE)		cout << 0;
	else                                    cout << weight[destination];
}
