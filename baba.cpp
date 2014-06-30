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
typedef vector<char> 	vc;
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

	vector<vector<pair<bool,int> > > hp(12,vector<pair<bool,int> >(12));
	vector<vector<pair<bool,int> > > vp(12,vector<pair<bool,int> >(12));
	
	vector<vector<char > > b(12,vector<char>(12));
	

pair<bool,int> brute (int r,int c,int i,int j,int count,vector<vector<pair<bool,int> > > &hp) {
	
//	cout << 4;
	hp[i][j].first = true;
	count++;	
	if(b[i][j] == 'E') 		return hp[i][j] = mp(true,count) ;
	pair<bool,int> temp;
	if (i+1 < r && !hp[i+1][j].first && b[i+1][j] != '#')			temp = brute(r,c,i+1,j,count,hp);
	if (i-1 >= 0 && !hp[i-1][j].first && b[i-1][j] != '#' && !temp.first)			temp = brute(r,c,i-1,j,count,hp);
	if (j+1 < c && !hp[i][j+1].first && b[i][j+1] != '#' && !temp.first)			temp = brute(r,c,i,j+1,count,hp);
	if (j-1 >= 0 && !hp[i][j-1].first && b[i][j-1] != '#' && !temp.first)			temp = brute(r,c,i,j-1,count,hp);
	
	return hp[i][j] = mp(temp.first,count);
}

int main() {

	int r,c;
	cin >> r >> c;
	pii v,h,e;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) {
		
			cin >> b[i][j];
			if(b[i][j] == 'H') {
				
				h.first = i;
				h.second = j;
			}
			if(b[i][j] == 'V'){
				
				v.first = i;
				v.second = j;
			}
			if(b[i][j] == 'E') {
				
				e.first = i;
				e.second = j;
			}
 			
		}
		
//cout << 4;
	brute(r,c,h.first,h.second,-1,hp);
	brute(r,c,v.first,v.second,-1,vp);
	
	pair<bool,int> tmph = hp[e.first][e.second];
	pair<bool,int> tmpv = vp[e.first][e.second];
	/*
	rep(i,r)	{
	
		rep(j,c)
			cout << hp[i][j].second << " ";
			cout << endl;
	}
	cout << endl;
	rep(i,r)	{
	
		rep(j,c)
			cout << vp[i][j].second << " ";
			cout << endl;
	}
	*/
	for(int i=0;i<r;i++) {
		
		for(int j=0;j<c;j++) {
			
			if(vp[i][j].second && hp[i][j].second && b[i][j] != 'E' ) {
//				cout << i << " " << j << endl;
				cout << max(1,hp[i][j].second);
				return 0;
			}
 			
		}
	}
	
/*	rep(i,r)	{
	
		rep(j,c)
			cout << hp[i][j].second << " " << i << " " << j << endl;;
			cout << endl;
	}
	cout << tmph.second << "  " << tmpv.second << endl  << h.first << " " << h.second << " " << hp[h.first][h.second].second;
*/	if (tmph.second < tmpv.second/2+tmpv.second%2)	
		cout << "escape" ;
	else if (tmph.second < tmpv.second/2+tmpv.second%2)
		cout << tmph.second + 1 << endl;
	else
		cout << tmph.second << endl;
	
}
