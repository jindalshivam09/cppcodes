#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
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
#define MAX 100009

ll n;
vll arr(MAX);
ll cal_max_rect(){
	stack<ll> stk;
	ll ans = 0;
	ll len , index , tmp;
	ll pre = 0,i;
	for(i=0;i<n;) {
		if(stk.empty() || arr[i] >= arr[stk.top()]) 
			stk.push(i++);
		else {
			index = stk.top();
			stk.pop();
			len = arr[index];
			ans = max(ans,arr[index]*(stk.empty()?i:i-stk.top()-1));
		}
	}
	while(!stk.empty()) {
		index = stk.top();
		stk.pop();
		ans = max(ans,arr[index]*(stk.empty()?i:i-stk.top()-1));
	}
	return ans;
}
int main() {
	cin >> n;
	while(n) {
		rep(i,n)
			cin >> arr[i];
		cout << cal_max_rect() << endl;
		
		cin >> n;
	}
}
