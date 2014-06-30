#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <limits>
#include <cstdio>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 2009
int m,n;
vector<vi> matrix(MAX,vi(MAX)) , height(MAX,vi(MAX)) ;

void cal_height () {
	rep(i,m)
		if(matrix[0][i] == 0)			height[0][i] = 0 ;
		else							height[0][i] = 1 ;
		
	rep(i,n) repi(j,1,m)
		if(matrix[j][i] == 0)			height[j][i] = 0 ;
		else							height[j][i] = 1 + height[j-1][i] ;
}

int cal_area() {
	cal_height() ;
	int ans = imin , j;
	rep(i,m) {
		stack<int> stk ;
		for(j=0;j<n;) {
			if(stk.empty() || height[i][stk.top()] <= height[i][j] ) 
				stk.push(j) , j ++;
			else {
				int top = stk.top() ;
				stk.pop() ;
				ans = max ( ans , height[i][top]*(stk.empty() ? j : j-stk.top()-1) ) ;
			}
		}
		while (stk.empty() == false) {
			int top = stk.top() ;
			stk.pop() ;
			ans = max ( ans , height[i][top]*(stk.empty() ? j : j-stk.top()-1) ) ;			
		}
	}
	return ans ;
}
 
int main() {
	freopen("input.txt","r",stdin) ;
	while(scanf("%d%d",&m,&n)!=EOF) {
		rep(i,m)	rep(j,n)
			scanf("%d",&matrix[i][j]) ;
		printf("%d\n",cal_area());	
	}
}


