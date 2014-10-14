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
	for(int i=1;i<str.size();i++) {
		int LCP = lcp(positions[i].second,positions[i-1].second) ;
		mapped[positions[i].second] = i ;
		ranks[i] = ranks[i-1] + str.size()-positions[i].second - LCP;
		same[i] = LCP ;
	}
}

int chainNum = -1;
vector<int> chainHead(MAX), chainPos(MAX), chainIndex(MAX), father(MAX) ;
vector<vector<pair<int,int> > > chains(MAX) ;

void finding_k2() {
	stack<pair<int,int> > stk ;
	for(int i=str.size()-1;i>=0;i--) {
		int temp = same[i] ;
		vector<int> popped ;
		while(stk.empty()==false && stk.top().first > temp && positions[i].second > positions[i-1].second) {
			popped.push_back(stk.top().second) ;
			stk.pop() ;
		}
		int n = popped.size() ;
		temp = i ;
		if(n == 0) {
			father[temp] = -1;
			chainNum ++ ;
			chainHead[chainNum] = temp ;
			chainPos[temp] = chainNum ;
			chains[chainNum].push_back(make_pair(same[i],i)) ;
			chainIndex[temp] = chains[chainNum].size()-1 ;
		}
		else {
			int num = chainPos[popped[n-1]] ;
			father[popped[n-1]] = temp ;
			father[temp] = -1;
			chainHead[num] = temp ;
			chainPos[temp] = num ;
			chains[num].push_back(make_pair(same[i],i)) ;
			chainIndex[temp] = chains[num].size()-1 ;
			for(int j=n-2;j>=0;j--) {
				father[popped[j]] = temp ;
			}
		}
		stk.push(make_pair(same[i],i)) ;
	}
}

void preprocess()  {
	suffix_array() ;
	calculate_ranks();
	finding_k2() ;
}

pair<int,int> selectk1k2(int l, int r) {
	pair<int,int> ans ;
	int index = lower_bound(ranks.begin(),ranks.end(),l) - ranks.begin() ;
	if(index<ranks.size()) {
		if(index == 0) {
			ans.first = positions[r].second ;
			ans.second = ans.first + l ;
			ans.first += 1 ;
		}
		else if(ranks[index] == l) {
			index += r ;
			ans.first = positions[index].second ;
			ans.second = str.size() ;
			ans.first +=  1 ;
		}
		else {
			int rank = l - ranks[index-1] + lcp(positions[index-1].second,positions[index].second);
			index = index + r ;
			ans.first = positions[index].second ;
			ans.second = ans.first + rank ;
			ans.first += 1;
		}
		return ans ;
	}
	return make_pair(-1,-1) ;
}

pair<int,int> ranklr(int l, int r) {
	int a = mapped[l], b = r-l+1 ;
	int num, head ;
	pair<int,int> ans ;
	int val ;
	while(true) {
		num = chainPos[a] , head = chainHead[num] ;
		int index1 = chainIndex[a], index2 = chainIndex[head] ;
		if( same[head] >= b) {
			a = father[head] ;
		}
		else {
			int sz = chains[num].size() - chainIndex[a] ;
			int idx = lower_bound(chains[num].rbegin(),chains[num].rbegin()+sz,make_pair(b,0)) - chains[num].rbegin() ;
			idx = chains[num].size() - idx  ;
			val = chains[num][idx].second ;
			break;		
		}
	}
	if(val == 0) {
		ans.first = (r-l+1) ;
		ans.second = (mapped[l]-val) ;
	}
	else {
		int LCP = same[val] ;
		ans.first = ranks[val-1] + (r-l+1) - LCP ;
		ans.second = (mapped[l]-val);
	}
	return ans ;
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
		else					ans = ranklr(l-1,r-1) ;
		cout << ans.first << " " << ans.second << endl;	
	}
}
