#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int MAXN=128;

struct MaxMatching 
{
	int n,match[MAXN];
	bool g[MAXN][MAXN];
	int idx[MAXN][MAXN];
	int q[MAXN],prev[MAXN],father[MAXN];
	bool visited[MAXN],is_shrinked[MAXN];
	bool is_in_path[MAXN];

	void clear()
	{
		for (int i=0;i<n;i++) match[i]=-1;
	}
	void init(int n) 
	{
		this->n=n;
		memset(g,false,sizeof(g));
		clear();
	}
	void addedge(int u,int v,int d) 
	{
		g[u][v]=g[v][u]=true;
		idx[u][v]=idx[v][u]=d;
	}
	int ford() 
	{
		int r=0;
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (match[i]<0 && match[j]<0 && g[i][j]) match[i]=j,match[j]=i,r++;
		for (int i=0;i<n;i++) if (match[i]<0 && bfs(i)) r++;
		return r;
	}
	bool bfs(int src) 
	{
		for (int i=0;i<n;i++) prev[i]=-1;
		for (int i=0;i<n;i++) visited[i]=false;
		for (int i=0;i<n;i++) father[i]=i;
		int op=0;
		q[op++]=src;
		visited[src]=true;
		for (int cl=0;cl<op;cl++) for (int key=q[cl],other=0;other<n;other++)
			if (g[key][other] && father[key]!=father[other] && other!=match[key])
				if (other==src || (match[other]>=0 && prev[match[other]]>=0)) 
				{
					int next=contract(key,other);
					for (int i=0;i<n;i++) if (is_shrinked[father[i]])
					{
						father[i]=next;
						if (!visited[i]) visited[i]=true,q[op++]=i;
					}
				}
				else if (prev[other]<0)
				{
					prev[other]=key;
					if (match[other]<0)
					{
						expand(other);
						return true;
					}
					else
					{
						q[op++]=match[other];
						visited[match[other]]=true;
					}
				}
		return false;
	}
	void expand(int v)
	{
		while (v>=0)
		{
			int p=prev[v];
			int k=match[p];
			match[v]=p;
			match[p]=v;
			v=k;
		}
	}
	void change_blossom(int b,int u)
	{
		while (father[u]!=b)
		{
			int v=match[u];
			is_shrinked[father[v]]=is_shrinked[father[u]]=true;
			u=prev[v];
			if (father[u]!=b) prev[u]=v;
		}
	}
	int contract(int u,int v)
	{
		memset(is_shrinked,false,sizeof(is_shrinked));
		int key=get_father(father[u],father[v]);
		change_blossom(key,u);
		change_blossom(key,v);
		if (father[u]!=key) prev[u]=v;
		if (father[v]!=key) prev[v]=u;
		return key;
	}
	int get_father(int u,int v) 
	{
		for (int i=0;i<n;i++) is_in_path[i]=false;
		while (1)
		{
			is_in_path[u]=true;
			if (match[u]<0) break;
			u=father[prev[match[u]]];
		}
		for (;!is_in_path[v];v=father[prev[match[v]]]);
		return v;
	}
};

MaxMatching p;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int testcase;
	for (scanf("%d",&testcase);testcase>0;testcase--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		p.n=n;
		memset(p.g,false,sizeof(p.g));
		for (int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			p.g[a][b]=p.g[b][a]=true;
		}
		p.clear();
		if (p.ford()*2==n)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

