// under construction

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

#define MAX 1000009
int rows,cols ;
vector<string> table , patterns ;

//////////////////////////aho corasick--------------------------------------------------------------------------

vector<vi> go(MAX,vi(MAX,-1));
vi failure(MAX,-1) ;
vector<set<int> > output(MAX);

void reset_containers () {
	rep(i,MAX)	rep(j,26)	
		go[i][j] = -1 ;
	rep(i,MAX)
		failure[i] = -1;
	rep(i,MAX)
		output[i].clear() ;
	patterns.clear();
	table.clear() ;
}

void build_matching_machine () {

	int states = 1;	
	// build goto function ----------------
	for(int i=0;i<patterns.size();i++) {
		string keyword = patterns[i] ;
		int current_state =  0 ;
		for(int j=0;j<keyword.size();j++) {
			int c = keyword[j] - 'a' ;
			if ( go[current_state][c] == -1)
				go[current_state][c] = states ++ ;
			current_state = go[current_state][c] ;
		}
		output[current_state].insert(i);	
	}
	
	// build faiure function ---------------------
	for(int i=0;i<26;i++) if (go[0][i] == -1)			// this is to make all edges from the beginning of the machine
		go[0][i] = 0;
	queue<int> q;
	
	for(int i=0;i<26;i++) {
		if (go[0][i] != 0 && go[0][i] != -1) {
			failure[go[0][i]] = 0 ;
			q.push(go[0][i]);
		}
	}
	int state ,fail;
	while(q.empty()==false) {
		state = q.front() ;
		q.pop();
		for(int i=0;i<26;i++) {
			if(go[state][i] != -1) {
				fail = failure[state] ;
				while (go[fail][i] == -1)
					fail = failure[fail] ;
			
				fail = go[fail][i] ;
				failure[go[state][i]] = fail ;
				// merging the output function 
				for(set<int>::iterator itr = output[fail].begin() ; itr != output[fail].end() ; itr ++)
				output[go[state][i]].insert(*itr) ;
				q.push(go[state][i]);
			}
		}
	}
}

int go_state (int state , int i) {
	while (go[state][i] == -1)
		state = failure[state] ;
	return go[state][i] ;
}

void find_patterns(int dir) {
	int state = 0;
	for(int i=0;i<text.size();i++) {
		state = go_state (state,text[i]-'a');
		if (output[state].size()==0)	continue ;
		for (int j=0;j<patterns.size();j++) {
			set<int>::iterator itr = lower_bound(all(output[state]),j);
			if (itr != output[state].end() && (*itr)==j) {
				cout << patterns[j] << " at " << i-patterns[j].size()+1 << endl;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void find_words () {
	build_matching_machine();
	rep(i,8) {
		find_patterns(i);
	}
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		reset_containers() ;
		int pat;
		cin >> rows >> cols >> pat ;
		string temp ;
		rep(i,rows) {
			cin >> temp ;
			table.pb(temp);
		}
		rep(i,pat) {
			cin >> temp ;
			patterns.pb(temp);
		}
		find_words() ;
	}
	
}


