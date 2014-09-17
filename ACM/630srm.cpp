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

vpii positions ;

typedef struct node {
	int first , second , id ;
} sa ;
vector<sa> suffixes; 
vector<vi> pos(MAXC,vi(MAXR));
int steps=1;

bool cmp (const struct node &a,const struct node &b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

void suffix_array (string str) {	
	rep(i,str.size()) 
		pos[0][i] = str[i]-'a';
	for(int cnt = 1 ; cnt >> 1 < str.size() ; steps++ , cnt <<= 1) {
		
		rep(i,str.size()) {
			suffixes[i].first = pos[steps-1][i];
			suffixes[i].second = i+cnt < str.size() ? pos[steps-1][i+cnt] : -1 ;
			suffixes[i].id = i ;
		}
		sort(all(suffixes),cmp);
		rep(i,str.size()) {
			pos[steps][suffixes[i].id] = i > 0 && suffixes[i-1].first == suffixes[i].first && 
										 suffixes[i-1].second == suffixes[i].second ? pos[steps][suffixes[i-1].id] : i ;
		}
	}
/*	rep(j,steps) {
		rep(i,str.size())
			cout << pos[j][i] << " ";
		cout << endl;
	}
*/
	rep(i,str.size()) {
		positions[i].first = i ;
		positions[i].second = pos[steps-1][i] ;
	}
	

	}	

bool cmp2 ( const pii &a, const pii &b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second ;
}

string same_sa ( string str ) {
	char ch = 'a' ;
	string ret;
	ret.resize(str.size()) ;
	int cur, last = -1 ;	
	sort(all(positions),cmp2) ;
	rep(i,str.size()) {
		cur = positions[i].first;
//		cout << cur << " " << positions[i].second << " ";;
//		cout << positions[last+1].second << " " << positions[cur+1].second << " ";
//		cout << pos[steps-1][last+1] << " " << pos[steps-1][cur+1] << " ";
//		cout << last << " " << ch << endl;
		if(last != -1) {
			if(cur+1==str.size())
				ret[cur] = (char)(++ch) ;
			else if(last+1==str.size() || pos[steps-1][last+1] < pos[steps-1][cur+1] )
				ret[cur] = ret[last] ;
			else 
				ret[cur] = (char)(++ch);
		}
		else 
			ret[cur] = ch ;
		last = cur ;
	}
	return ret ;
}


class SuffixArrayDiv2 {
	public :
		string smallerOne ( string str ) {
				steps = 1 ;
		suffixes.resize(str.size()) ;
		pos.resize(MAXC,vi(str.size()));
		positions.resize(str.size()) ;
				
		suffix_array(str) ;
		string ans;
		int cnt = 0;
		ans = same_sa(str) ;
		bool flag = false ;
		rep(i,str.size()) {
			if(ans[i] > str[i] ) {
				flag = true ;
				break;
			}
			else if(ans[i] == str[i])
				cnt ++;
		}
		if(cnt==str.size() || flag)
			return "Does not exist" ;
		return "Exists" ;
		}
};

int main() {
	string str;
	cin >> str ;
	SuffixArrayDiv2 obj ;
	cout << obj.smallerOne(str) ;
}


