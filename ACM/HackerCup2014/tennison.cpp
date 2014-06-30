#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int, int> > vpii;
typedef vector<double> 	vd;
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

#define MAX 101

double memo[MAX][MAX][1001];
double pu,pw,pd,pl,ps,pr;
int k;

double dp(double pi,int i,int j,int set) {
	
	if( j >= k)  	  					return 0.00;
	if(i >= k)  	 					return 1.00;
	if(memo[i][j][(int)(pi*1000)])		return memo[i][j][(int)(pi*1000)];
	
	double win = ps*pi + pr*(1-pi);
	double lose = 1-win;
	memo[i][j][(int)(pi*1000)] = (win)*pw*dp(min(1.00,(pi+pu)),i+1,j,set+1) + (win)*(1-pw)*dp(pi,i+1,j,set+1); 
	memo[i][j][(int)(pi*1000)] += (lose)*pl*dp(max(0.00,(pi-pd)),i,j+1,set+1) + (lose)*(1-pl)*dp(pi,i,j+1,set+1);
	
	return memo[i][j][(int)(pi*1000)];
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		
		cin >> k;
		double pi;
		cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
		cout.setf(ios_base::fixed);
		cout.precision(6);
		cout << dp(pi,0,0,1) << endl;		
		for(int i=0;i<=k;i++)
			for(int j=0;j<=k;j++)
				for(int t=0;t<=1000;t++)
				memo[i][j][t]=0;				
	}
}


