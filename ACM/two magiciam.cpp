// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

#ifdef DEBUG
#include"debug.h"
#include"print.h"
#endif
// }}}

//{{{ Union Find
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
//}}}

int N,M,P;

void main2(){
	int s,t,first_objective,odd,even;
	bool is_first;
	set<int> comps;
	scanf("%d%d%d",&N,&M,&P);
	UnionFind uf(N);
	vector<pii> es;
	REP(i,M){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		es.push_back(MP(a,b));
	}
	int rest=N*(N-1)/2-M;
	REP(i,M)uf.unionSet(es[i].first,es[i].second);
	if(uf.findSet(0,1)){
		is_first=true;
		goto OUT;
	}
	if(N%2==1){
		if(rest%2==1){
			is_first=true;
		}else{
			is_first=false;
		}
		goto OUT;
	}
	REP(u,N)comps.insert(uf.root(u));
	odd=even=0;
	FOR(it,comps){
		int sz=uf.size(*it);
		if(sz%2==0)even++;
		else odd++;
	}
	assert(odd%2==0);
	s=uf.size(0),t=uf.size(1);
	first_objective=0;//even
	if(rest%2==0){
		first_objective=1;
	}
	if(P==0){
		if(s%2!=t%2){
			is_first=true;
		}else{
			if(first_objective==0){
				if(s%2==1){
					is_first=false;
				}else{
					is_first=true;
				}
			}else{//first_objective==1
				if(s%2==0){
					is_first=false;
				}else{
					is_first=true;
				}
			}
		}
	}else{
		if(first_objective==0){
			if(odd==2 and even==0){
				is_first=false;
			}else{
				is_first=true;
			}
		}else{//first_objective==1
			if(odd==2 and even<=1){
				is_first=true;
			}else{
				is_first=false;
			}
		}
	}
OUT:
	if(is_first){
		printf("First\n");
	}else{
		printf("Second\n");
	}
}

//{{{ main function
int main() {
	int T;scanf("%d", &T);
	REP(ct, T){
		//		printf("Case %d: ",ct+1);
		main2();
	}
	return 0;
}
//}}}
