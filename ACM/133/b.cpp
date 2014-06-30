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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
int n,m;
vector<vi> arr(101,vi(101));
vi enter;
#define RED 1 
#define BLUE 2
int bfs () {
	queue<int>	q ;
	int count = 0 ,len;
	vb seen(n+1);
	for(int i=1;i<=n;i++) {
		if (enter[i] != 0 && seen[i] == false) {
			len = 1 ;
			q.push(i);
			seen[i] = true;
			while(q.empty()==false) {
				int v = q.front() ;
				q.pop() ;
//				cout << "popped" << v << endl;
				for(int j=1;j<n+1;j++) {
					int temp = j ;
					if(arr[v][j] == 0) continue;
//				cout << temp << " ";
					if (seen[temp] == false) 	{
						q.push(temp) ;
						len ++ ;
						seen[temp] = true;
						arr[temp][v] = 0;
					}
					else if(seen[temp] && seen[v]){
						if(len&1)
							count += len-1;
						else
							count += len;
						len = 0;
					}
				}
//				cout << endl;
			}				count += len ;

//			cout << count << endl;
		}
	}
	return count  ;
} 

int main() {
	cin >> n >> m;
//	arr.resize(n+1);
	enter.resize(n+1);
	int tot = 0 ;
	int a,b; 
	rep(i,m) {
		cin >> a >> b ;
		arr[a][b]  = 1;
		arr[b][a] = 1;
		if (enter[a] == false)
			enter[a] = true , tot ++ ;
		if (enter[b] == false)
			enter[b] = true , tot++;
	}
	cout << tot-bfs();
}


