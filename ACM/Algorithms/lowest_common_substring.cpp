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

#define MAXC 500
#define MAXR 500009
string str ;	
string str1,str2 ;

struct node {
	int first , second , id , num;
} suffixes[MAXR] ;
vector<vi> pos(MAXR,vi(MAXC));
int steps=1;

bool cmp (const struct node &a,const struct node &b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

void suffix_array () {	
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
	cin >> str1 >> str2;
	str = str1 + str2 ;
	vi common_prefixes(str.size());
	suffix_array();
	int ans = imin , start = -1;
	rep(i,str.size()-1) {
		int a = suffixes[i].id , b = suffixes[i+1].id ;
		if ( (a>=str1.size()&&b<str1.size()) || (a<str1.size()&&b>=str1.size()) )  {
			int temp = lcp(a,b) ;
			if (ans < temp) {
				ans = temp ;
				start = a ;
			}
			else if (ans==temp && a >= str1.size() && a < start) {
				ans = temp;
				start = a ;
			}
			else if (ans==temp && b >= str1.size() && b < start) {
				ans = temp;
				start = b ;
			}
			
		}
	}
	repi(i,start,start+ans) 
	cout << str[i] ;
	if(ans)
	cout << endl;
	cout << ans << endl ;

}


