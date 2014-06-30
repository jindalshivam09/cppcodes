#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

#define MAX 100

vector<int> weight(MAX,numeric_limits<int>::max());
vector<int> parent(MAX,numeric_limits<int>::max());
class vertice{
	public:
		int v;
		int wt;
		vertice(int a=0,int b=0) {
			
			v = a;
			wt = b;
		}
		bool operator() (const vertice &a,const vertice &b) const {
//			cout << "E";
			return a.wt < b.wt;
		}
		bool operator < (const vertice &a) const {
//			cout << "F" ;
			return this->wt < a.wt;
		}
};

void dijsktra(int e,int v,list<pair<int,int> > *edges,int source) {
	
	priority_queue<vertice> Q ;
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

int main() {
	
	int e,v;
	cin >> v >> e;
	list<pair<int,int> >  edges[MAX];
	
	int a,b,wt;
	for(int i=0;i<e;i++) {
		
		cin >> a >> b >> wt;
		edges[a].push_back(make_pair(b,wt));
	}
	int source;
	cin >> source;
	dijsktra(e,v,edges,source);
	
	for(int i=0;i<v;i++) 
	cout << weight[i] << endl;                                                                                                                                                                   
}
