/* Author - Rishi */
#include <vector>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <cstring>
#include<string.h>
#include<math.h>
#include <climits>
#include <fstream>
#include <sstream>

using namespace std;

#define FOR(i,a,b)         for(int i= (int )a ; i < (int )b ; i++) 
#define FORD(i,a,b)        for(int i= (int )a ; i >= (int )b ; i--) 
#define REP(i,n)           FOR(i,0,n)
#define REPD(i,n)          FORD(i,n-1,0)
#define F                  first
#define S                  second
#define MP                 make_pair
#define PB                 push_back
#define PP                 pop()
#define EM                 empty()
#define INF                2000000000
#define PF                 push_front
#define ALL(x)             x.begin(),x.end()
#define SORT(x)            sort(ALL(x))
#define V(x)               vector< x >
#define PRINT(x)           cout << #x << " " << x << endl
#define SZ(x)              x.size();
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define PRV(v)             REP(Ind,v.size())cout<<v[Ind]<<" ";cout<<endl;
#define NT()               int nt;for(scanf("%d",&nt);nt;nt--)
#define SI                 ({int t;scanf("%d",&t);t;})

typedef map<int,int>    MI;
typedef pair<int,int>   PI;
typedef long long int   LL;
typedef V( int )        VI;
typedef V( VI )         VVI;
typedef V( PI  )        VPI;
typedef V( string )     VS;
typedef V( VS )         VVS;

int A[51],B[51];
int dp[51][51][61][61];

int fn(int ind1,int ind2 , int lt1 , int lt2){
	if(ind1==0 && ind2==0){
		return max(lt1,lt2);
	}
	int &r=dp[ind1][ind2][lt1][lt2];
	if(r!=-1)return r;
	r=INF;
	if(lt1==lt2){
		if(ind1>0 && ind2>0)
			r=min(r,lt1+fn(ind1-1,ind2-1,A[ind1],B[ind2]));
		if(ind1>0)
			r=min(r,lt1+fn(ind1-1,ind2,A[ind1],0));
		if(ind2>0)
			r=min(r,lt1+fn(ind1,ind2-1,0,B[ind2]));
	}else if(lt1<lt2){
		if(ind1>0 )
			r=min(r,lt1+fn(ind1-1,ind2,A[ind1],lt2-lt1));
		if(ind2>0)
			r=min(r,lt1+fn(ind1,ind2-1,lt2-lt1,B[ind2]));
		
	}else{
		if(ind1>0 )
			r=min(r,lt2+fn(ind1-1,ind2,A[ind1],lt1-lt2));
		if(ind2>0)
			r=min(r,lt2+fn(ind1,ind2-1,lt1-lt2,B[ind2]));
	
	}
	return r;
}

int main(){
	int la=SI,lb=SI;
	A[0]=B[0]=0;
	FOR(i,1,la+1)A[i]=SI;
	FOR(i,1,lb+1)B[i]=SI;
	REP(i,la+1)REP(j,lb+1)REP(k,61)REP(m,61)dp[i][j][k][m]=-1;
	printf("%d\n",fn(la,lb,0,0));
}

