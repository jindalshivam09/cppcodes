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
int n=400,m=600;
vector<vb> matrix(n,vb(m));
vi ans;		
class grafixMask {
	public :
		int bfs(int a,int b) {
			queue<pii> q;
			int count = 0;
			q.push(mp(a,b));
			while(!q.empty()) {
	//			cout << "bfs";
				pii temp = q.front();
				q.pop();
				a = temp.first ;
				b = temp.second;
				if(a < n-1 && matrix[a+1][b] == false) {
						q.push(mp(a+1,b));
						count++;
						matrix[a+1][b] = true;
				}
				if( b < m-1 && matrix[a][b+1] == false) {
						q.push(mp(a,b+1));
						count++;
						matrix[a][b+1] = true;
				}
				if( a > 1 && matrix[a-1][b] == false) {
					q.push(mp(a-1,b));
					count++;
					matrix[a-1][b] = true;
				}
				if( b > 1 && matrix[a][b-1] == false) {
					q.push(mp(a,b-1));
					count++;
					matrix[a][b-1] = true;
				}
			}
			return count ;
		}
		vi sortedAreas ( vector<string> str ) {
			int a,b,c,d;
//			cout << str.size();
//			cin >> a;
			for(int i=0;i<str.size();i++)  {
				stringstream sin(str[i]);
				sin >> a >> b >> c >> d;
	//			cout << a << b << c << d;
				for(int i=a;i<=c;i++) 
					for(int j=b;j<=d;j++)
						matrix[i][j] = true;
			}
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(matrix[i][j] == false)
						ans.pb(bfs(i,j));
			
			sort(all(ans));
			return ans;
		}
};

int main() {
	int n;
	cin >> n;
	vector<string> str(n);
	rep(i,n)
		cin >> str[i];

	grafixMask a;
	vi ans = a.sortedAreas(str);
	for(int i=0;i<ans.size();i++)
		cout << ans[i] <<  " ";
}


