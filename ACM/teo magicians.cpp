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

const int maxsize=10000+5;

int n,m,p;
int father[maxsize],cnt[maxsize];

const int C=10;
const int P=2;

char f[2][2][C][C][2][P][P];

bool solve(int s1,int s2,int c0,int c1,int x,int p1,int p2);

bool solve2(int s1,int s2,int c0,int c1,int x,int p1,int p2)
{
	if (!solve(s1,s2,c0,c1,x,p1,p2)) return false;
	if (p2>0 && s2==0 && c1>=1 && !solve(s1,1,c0+1,c1-1,x,p1,p2-1)) return false;
	if (p2>0 && s2==1 && c0>=1 && !solve(s1,0,c0-1,c1+1,x,p1,p2-1)) return false;
	return true;
}

bool solve(int s1,int s2,int c0,int c1,int x,int p1,int p2)
{
	char &ret=f[s1][s2][c0][c1][x][p1][p2];
	if (ret>=0) return ret;
	if (x && !solve2(s2,s1,c0,c1,0,p2,p1)) return ret=1;
	if (c0>=2 && !solve2(s2,s1,c0-1,c1,x^1,p2,p1)) return ret=1;
	if (c1>=2 && !solve2(s2,s1,c0+1,c1-2,x,p2,p1)) return ret=1;
	if (c0>=1 && c1>=1 && !solve2(s2,s1,c0-1,c1,x^1,p2,p1)) return ret=1;
	if (c0>=1 && !solve2(s2,s1,c0-1,c1,x^1,p2,p1)) return ret=1;
	if (c0>=1 && !solve2(s2,s1,c0-1,c1,x^1,p2,p1)) return ret=1;
	if (c1>=1 && !solve2(s2,s1^1,c0,c1-1,x^1^s1,p2,p1)) return ret=1;
	if (c1>=1 && !solve2(s2^1,s1,c0,c1-1,x^1^s2,p2,p1)) return ret=1;
	if (p1>0)
	{
		if (c0>=1 && !solve(s1^s2,0,c0-1,c1,x^1^(s1&s2),p2,p1-1)) return ret=1;
		if (c1>=1 && !solve(s1^s2,1,c0,c1-1,x^1^(s1&s2),p2,p1-1)) return ret=1;
	}
	return ret=0;
}

int getfather(int p)
{
	return (father[p]<0)?p:(father[p]=getfather(father[p]));
}
void addedge(int a,int b)
{
	a=getfather(a);
	b=getfather(b);
	if (a==b) { cnt[a]++; return; }
	if (cnt[a]>cnt[b]) swap(a,b);
	father[a]=b;
	cnt[b]+=cnt[a];
	cnt[b]++;
}
bool solve()
{
	if (getfather(0)==getfather(1)) return true;
	int s1=0,s2=0,c0=0,c1=0,x=0;
	for (int i=0;i<n;i++) if (father[i]<0)
	{
		int node=cnt[i]>>15;
		int edge=cnt[i]&32767;
		if (getfather(0)==i) s1=node&1;
		else if (getfather(1)==i) s2=node&1;
		else if (node&1) c1++;
		else c0++;
		x^=(node*(node-1)/2-edge)&1;
	}
	if (p==0)
	{
		for (;c0>=2;c0-=2);
		for (;c1>=2;c1-=2) x^=1;
		return solve(s1,s2,c0,c1,x,0,0);
	}
	else
	{
		for (;c0>=4;c0-=2);
		for (;c1>=4;c1-=2) x^=1;
		return solve(s1,s2,c0,c1,x,1,1);
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	memset(f,255,sizeof(f));
	int testcase;
	for (scanf("%d",&testcase);testcase>0;testcase--)
	{
		scanf("%d%d%d",&n,&m,&p);
		for (int i=0;i<n;i++) father[i]=-1;
		for (int i=0;i<n;i++) cnt[i]=(1<<15);
		for (int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(a-1,b-1);
		}
		if (solve())
			printf("First\n");
		else
			printf("Second\n");
	}
	return 0;
}

