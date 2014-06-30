/* Author :: Yash */
#include <vector>
#include <list>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <deque>
#include <fstream>
#include <stack>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class A, class B> A cvt(B x) {stringstream s;s<<x;A r;s>>r;return r;}

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define PP pop()
#define EM empty()
#define INF 1000000000
#define PF push_front
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define V(x) vector< x >
#define Debug false
#define PRINT(x)        cout << #x << " " << x << endl
#define LET(x,a) 	    __typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define PRESENT(c,x) 	((c).find(x) != (c).end())
#define SZ(x) 		x.size();
#define CPRESENT(c,x) 	(find(c.begin(),c.end(),x) != (c).end())
#define D(N) 		int N
#define S(N)		scanf("%d",&N)
#define Max             150000

typedef pair<int,int>  PI;
typedef pair<int,PI>   TRI;
typedef V( int )       VI;
typedef V( PI  )       VII;
typedef V( string )    VS;
typedef V( set<int> )  VSI;
typedef long long      LL;


// Fast I/O.

char* ipos, infile[20000000];
int input()
{
	int x=0, neg=0;
	char c;
	while(*ipos <= 32) ++ipos;
	while( true ) {
		c=*ipos++;
		if (c<=32) return neg?-x:x;
		if (c=='-') neg=1;
		else x=(x<<1)+(x<<3)+c-'0';
	}
	return x;
} 







int n, k;
VI Graph[Max << 1] , Transpose[Max << 1], SCC[Max << 1];
//set<int> GraphSCC[Max << 1];
VI Topological;
set < PI > Check;


int  Label[Max << 1], Visited[Max << 1];


void GetVal(int &x) {

	if(x < 0) x = n - x - 1;
	else      x--;
}
int Counter(int x) {

	if(x >= n ) return x - n;
	else return n + x;
}

void DFS(int i) {

	if(!Visited[i]) {
		Visited[i] = 1;
		int size = Graph[i].size();
		REP(j,size) if(!Visited[Graph[i][j]]) DFS(Graph[i][j]);
		Topological.PB(i);
	}
}

void DFS(int i,int nSCC) {

	if (!~Label[i]) {
		Label[i] = nSCC; SCC[nSCC].PB(i);
		EACH(it,Transpose[i]) {
			if(!~Label[*it]) DFS(*it,nSCC);
			else {
				// Here We can Build Up the SCC-Graph.
				if(Label[*it] != nSCC) Check.insert(PI(Label[*it],nSCC));
			}
		}
	}
}


void PreProcess(int t) {
	int First = 0, x, y;
	memset(Visited,-1,(t+10)*4);
	REP(i,n) if(!~Visited[Label[i]]) {
		Visited[Label[i]  ] = First;
		Visited[Label[n+i]] = t - First++ - 1; // This Ensures that we only look for (Size - i - 1) in the path.
	}
}

void DFS(VSI& newSCCGraph, int v,int t) {

	if(!Visited[v]) {
		Visited[v] = Visited[t-v-1] = 1;   
		EACH(it,newSCCGraph[v]) DFS(newSCCGraph,*it,t);
	}
}
int main() {

	ipos = infile;
	fread_unlocked(infile,20000000,1,stdin); 

	int kases, x, y, t, N; kases = input(); //scanf("%d",&kases);	
	while (kases--) {

		Check.clear();
		//scanf("%d%d",&n,&k); 
		n = input(); k = input(); N = n << 1;
		REP(i,N) Graph[i].clear(), Transpose[i].clear(), SCC[i].clear(); //, GraphSCC[i].clear();
		REP(i,k) {

			x = input(); y = input(); //scanf("%d%d",&x,&y);
			GetVal(x); GetVal(y);                              // Get the value of Nodes in 2*n node Graph 
			Graph[Counter(x)].PB(y); Graph[Counter(y)].PB(x);  // Graph Formation 
			Transpose[x].PB(Counter(y)); Transpose[y].PB(Counter(x));  // Transpose Graph
		}

	        // Now We Form the Strongly Connected Components of this Graph

		memset(Visited,0,N<<2);
		Topological.clear();
		REP(i,N) if(!Visited[i]) DFS(i);
		reverse(ALL(Topological));   // In Decreasing Order of the finishing time 
	
		/*
			REP(i,n << 1) {
				printf("%d -- ",i);
				REP(j,Graph[i].size()) printf("%d ",Graph[i][j]); puts("");
			}
		*/
		
		memset(Label,-1,N<<2); t = 0;
		EACH(it,Topological) if(!~Label[*it]) DFS(*it,t++);
	
		//t == Total Number of SCC.
		//  So Decomposed into Strongly Connected Components 
		int Ans = 1;
		REP(i,n) if(Label[i] == Label[n+i]) {

			// Conflict Detected.
			Ans = 0;
			break;
		}

		/* Now we have to deal with Multiple and Unique 
		 * Okay, ;) Deal with any one of them :P
		 */
		if( Ans ) {

			VSI newSCCGraph(t);PreProcess(t);
			EACH(it,Check) {
				x = Visited[(*it).first];y = Visited[(*it).second];
				newSCCGraph[x].insert(y);
			}

			/*
			 * REP(i,N) printf("%d %d\n",i , Label[i]);
			   REP(i,t) {
			  		printf("%d -- ",i);
					EACH(it,newSCCGraph[i]) cout << *it << " "; cout << endl;
				}		
		  	*/
	
			memset(Visited,0,t<<2);
			REP(i,t) if(!Visited[i] && newSCCGraph[i].count(t-i-1)) DFS(newSCCGraph,t-i-1,t);
			REP(i,t) if(!Visited[i]) { Ans = 0; break; }
			puts(Ans ? "UNIQUE" : "MULTIPLE");
		}
		else puts("CONFLICT");
	}
	return 0;
}


