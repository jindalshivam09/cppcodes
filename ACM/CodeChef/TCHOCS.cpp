#include <bits/stdc++.h>
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
#define MAX 509
vector<vi> cell(MAX,vi(MAX)) ;
vector<vector<pair<int,bool> > > memo(MAX,vector<pair<int,bool> >(MAX)) , memo2(MAX,vector<pair<int,bool> >(MAX));
vector<vb> visited(MAX,vb(MAX));
int n;

pair<int,bool> po (int i,int j) {
//	cout << i << " " << j << endl;
	if (i==n && j==1) 	return mp(cell[i][j],true);
	if (i==n)			return mp(0,false);
	if (j<1 || j>i)		return mp(0,false);
	if (memo[i][j].first)		return memo[i][j];
	visited[i][j] = true; 
	pair<int,bool> temp , ans(0,false);
	temp = po(i+1,j-1);
	if (temp.second) 	ans = temp ;
	temp = po(i+1,j);
	if(temp.second && ans.first < temp.first) {
		ans = temp ;
		if(j>0)	visited[i+1][j-1] = false;
	}
	temp = po(i+1,j+1);
	if (temp.second && ans.first < temp.first)	{
		ans = temp;
		if (j>0) visited[i+1][j-1] = false;
		visited[i+1][j] = false;
	}
	ans.first += cell[i][j] ;
	if(!ans.second)	ans.first = 0 , visited[i][j] = false;
	return memo[i][j] = ans ;

}

pair<int,bool> mantis (int i,int j) {
	if (i==n&&j==1)	return mp(0,true);
	if (i<1||j<1)	return mp(0,false);
	if (memo2[i][j].first)	return memo2[i][j];
	
	pair<int,bool> temp , ans(0,false);
	temp = mantis(i,j-1);
	if(temp.second)	ans = temp;
	temp = mantis(i-1,j-1);
	if(temp.second && ans.first < temp.first) {
		ans = temp ;
	}
	temp = mantis(i+1,j-1);
	if (temp.second && ans.first < temp.first)	{
		ans = temp;
	}
	if(!visited[i][j])	ans.first += cell[i][j] ;
	if(!ans.second)	ans.first = 0;// , visited[i][j] = false;
	return memo2[i][j] = ans ;
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		int  a;
		cin >> n ;
		repi(i,1,n+1) {
			repi(j,1,i+1) {
				cin >>cell[i][j] ;
			}
		}
		pair<int,bool> Po = po(1,1);
		visited[n][1] = true;
		pair<int,bool> Mantis = mantis(n,n);

		cout << Mantis.first + Po.first << endl;

		repi(i,1,n+1)
			cell[i].clear() ;
		rep(i,MAX)
			rep(j,MAX)
				memo[i][j].first = 0 , visited[i][j] = false , memo2[i][j].first = 0 ;
		
	}
}


