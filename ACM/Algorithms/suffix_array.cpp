/*
	Name: Suffix Array
	Copyright: no rights
	Author: jindalshivam09
	Date: 23/03/14 14:08
	Description: 
*/


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

#define MAXC 100
#define MAXR 10000
string str ;
struct node {
	int first , second , id ;
} suffixes[MAXR] ;
vector<vi> pos(MAXC,vi(MAXR));
int steps=1;

bool cmp (const struct node &a,const struct node &b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

void suffix_array (const string &str) {	
	rep(i,str.size()) 
		pos[0][i] = str[i]-'a';
	for(int cnt = 1 ; cnt >> 1 < str.size() ; steps++ , cnt <<= 1) {
		
		rep(i,str.size()) {
			suffixes[i].first = pos[steps-1][i];
			suffixes[i].second = i+cnt < str.size() ? pos[steps-1][i+cnt] : -1 ;
			suffixes[i].id = i ;
		}
		sort(suffixes,suffixes+str.size(),cmp);
		rep(i,str.size()) {
			pos[steps][suffixes[i].id] = i > 0 && suffixes[i-1].first == suffixes[i].first && 
										 suffixes[i-1].second == suffixes[i].second ? pos[steps][suffixes[i-1].id] : i ;
		}
	}
	rep(j,steps) {
		rep(i,str.size())
			cout << pos[j][i] << " ";
		cout << endl;
	}

}

int lcp (int x,int y) {
	if (x==y)	return str.size()-x ;
	int ans = 0;
	for(int k=steps-1;k>=0&&x<str.size()&&y<str.size();k--) {
		if(pos[k][x] == pos[k][y] )	
			x += 1<<k , y += 1<<k , ans += 1<<k ;
	}
	return ans ;
}

int main() {
	cin >> str ;
	suffix_array (str) ;
	int x,y; 	// to pos to calculate the lcp
	cin >> x >> y ;
	cout << lcp(x,y) << endl;
}


