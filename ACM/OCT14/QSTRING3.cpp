#include<bits/stdc++.h>
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
#define MAXR 1000009
#define MAX MAXR
string str ;
struct node {
	int first , second , id ;
} suffixes[MAXR] ;
vector<vi> pos(MAXC,vi(MAXR));
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

vector<int> ranks, same(MAXR) ;
vector<pair<int,int> > positions ;
map<int,int> mapped ;

void calculate_ranks() {
	positions.resize(str.size()) ;
	ranks.resize(str.size()) ;
	for(int i=0;i<str.size();i++) {
		positions[i].first = pos[steps-1][i];
		positions[i].second = i ;
	}
	sort(positions.begin(),positions.end()) ;
	ranks[0] = str.size()-positions[0].second ;
	mapped[positions[0].second] = 0 ;
	same[0] = 0;
	cout << ranks[0] << " " << same[0] << " " << positions[0].second << " " << mapped[positions[0].second] << " " << endl;
	for(int i=1;i<str.size();i++) {
		int LCP = lcp(positions[i].second,positions[i-1].second) ;
		mapped[positions[i].second] = i ;
		ranks[i] = ranks[i-1] + str.size()-positions[i].second - LCP;
		same[i] = LCP ;
		cout << ranks[i] << " " << same[i] << " " << positions[i].second << " " << mapped[positions[i].second] << " " << endl;
	} 
	cout << endl;
}

vector<pair<int,int> > segment(MAX) ;

void makeSegment(int num, int l, int r) {
	if(l == r) {
		segment[num].first = same[l] ;
		segment[num].second = l ;
		return ;
	}
	int mid = (l+r)/2 ;
	makeSegment(2*num,l,mid), makeSegment(2*num+1,mid+1,r) ;
	segment[num] = min(segment[2*num],segment[2*num+1]) ;
}

pair<int,int> findMin(int num,int l,int r, int a, int b) {
	if(l > b || r < a)
		return make_pair(INT_MAX,-1);
	if(l>=a && r<=b)
		return segment[num];
	int mid = (l+r)/2;
	return min(findMin(2*num,l,mid,a,b), findMin(2*num+1,mid+1,r,a,b)) ;
}

void preprocess()  {
	suffix_array() ;
	calculate_ranks();
	makeSegment(1,0,str.size()-1) ;
}

int nextMin(int l, int len) {
	
	int pre = l ;
	int a = l+1, b = str.size()-1 ;
	while(a<=b) {
		cout << a << " " << b << endl;
		int mid = (a+b)/2 ;
		pair<int,int> ans = findMin(1,0,str.size()-1,a,mid) ;
		int idx = ans.second, val = ans.first ;
		if(val > len) {
			a = mid+1 ;
		}
		else {
			b = mid-1 ;
		}	
	}
	return a ;
}

pair<int,int> selectk1k2(int k1, int k2) {
	pair<int,int> ans ;
	int index = lower_bound(ranks.begin(),ranks.end(),k1) - ranks.begin() ;
	if(index<ranks.size()) {
		if(index == 0) {
			ans.first = 0 ;
			ans.second = ans.first + k1 ;
			ans.first += 1 ;
		}
		else if(ranks[index] == k1) {
			ans.first = positions[index].second ;
			ans.second = str.size() ;
			ans.first +=  1 ;
		}
		else {
			int rank = k1 - ranks[index-1] + lcp(positions[index-1].second,positions[index].second);
			ans.first = positions[index].second ;
			ans.second = ans.first + rank ;
			ans.first += 1;
		}
	}
	cout << ans.first << " " << ans.second << endl;
	int range = nextMin(mapped[ans.first-1],ans.second-ans.first) ;
	cout << range << endl;
}

int main() {
	cin >> str ;
	preprocess() ;
	int q ;
	cin >> q ;
	while(q--) {
		string type ;
		int l,r ;
		cin >> type >> l >> r ;
		pair<int,int> ans ;
		if(type[0] == 'S')		ans = selectk1k2(l,r) ;
//		else					ans = ranklr(l-1,r-1) ;
//		cout << ans.first << " " << ans.second << endl;	
	}
}
