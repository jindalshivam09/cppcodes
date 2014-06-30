// expression to postfix

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

map<char,int> priority;

void set_prio() {
	priority['+'] = 1;
	priority['-'] = 2;
	priority['*'] = 3; 
	priority['/'] = 4;
	priority['^'] = 5;
}

vector<char> post_fix (const string &str) {

	stack<char> stk;
	vector<char> ans;
	for(int i=0;i<str.size();i++) {		
		char temp = str[i];
		if(temp == '(') 
			stk.push(temp);
		else if(temp == ')') {			
			stk.push(temp);
			char poped = stk.top();
			stk.pop();
			while(!stk.empty() && poped != '(') {
				poped = stk.top();
				if(poped != '(')
				ans.pb(poped);
				stk.pop();
			}
		}
		else if (temp >= 'a' && temp <= 'z')
			ans.pb(temp); 
		else{			
			if(!stk.empty()) {				
				char poped = stk.top();
//				stk.pop();
				while(!stk.empty() && priority[poped] > priority[temp]) {
					stk.pop();
					ans.pb(poped);
					poped = stk.top();
				}
				stk.push(temp);
			}
			else
				stk.push(temp);
		}		
	}
	while(!stk.empty()) {
		char poped = stk.top();
		ans.pb(poped);
		stk.pop();
	}
	return ans;
}

int main() {

	set_prio();
	int t;
	cin >> t;
	while(t--) {		
		string str;
		cin >> str;
//		cout << str;
		vector<char> ans =  post_fix(str);
		for(int i=0;i<ans.size();i++)
			cout << ans[i];
		cout << endl;
	}
}


