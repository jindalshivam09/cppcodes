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

int histogram (vector<vi> &arr,int index,int n) {
	stack<int> stk;
	vi bars(n);
	rep(i,n)
		bars[i] = arr[i][index];
	int area = 0;
	int i=0;
	for(i=0;i<n;) {
		if(stk.empty() || bars[stk.top()] <= bars[i])
			stk.push(i),i++;
		else {
			int tp = stk.top();
			stk.pop();
			area = max (area , (int)pow(min(stk.empty() ? i : i-stk.top()-1 , bars[tp]),2) );
		}
	}
	while(!stk.empty()) {
			int tp = stk.top();
			stk.pop();
			area = max (area , (int)pow(min(stk.empty() ? i : i-stk.top()-1 , bars[tp]),2) );		
	}
	return area;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		string str[n];
		rep(i,n)
			cin >> str[i];
		vector<vi> arr(n,vi(m));
		for(int i=0;i<n;i++) {
			for(int j=m-1;j>=0;j--) {
				if(j==m-1)
					arr[i][j] = 1;
				else if (str[i][j]==str[i][j+1])
					arr[i][j] = 1 + arr[i][j+1];
				else
					arr[i][j] = 1;				
			}
		}
		int ans = 0;
		for(int i=0;i<m;i++) {
			ans = max(ans,histogram(arr,i,n));
		}
		cout << ans << endl;
	}
}
