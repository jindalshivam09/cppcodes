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

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,m ;
		cin >> n >> m ;
		vector<vi> graph(n+1,vi(n+1));
		vi freq(n+1);
		int a,b;
		rep(i,m) {
			cin >> a >> b;
			graph[a][b]++;
			graph[b][a]++;
		}
		bool multi = false;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(graph[i][j])
					freq[j]++;
				if(graph[i][j]>1)
					multi = true;
			}
		}	
		bool all_one = false,connected = false;
		int count = 0,count_zero = 0;
		for(int i=1;i<=n;i++) {
			if(freq[i]==1)
				count_zero ++;
			if(freq[i])
				count++;
		}
		if(count_zero==n)
			all_one = true;	
		if(count==n)
			connected = true;
		
		bool flag = false;
		for(int i=1;i<=n;i++) {
			int count = 0;
			for(int j=1;j<=n;j++) {
				if(graph[i][j] && freq[j]==1)
					count++;
			}
			if(count >= 2 ) {
				flag = true;
				break;
			}
		}
//		cout << all_one <<  " " << multi << endl;
		if(all_one && multi)											cout << "YES";
		else if (flag || !connected || (all_one && !multi))				cout << "NO";
		else															cout << "YES";
		cout << endl;
	
	}
}


