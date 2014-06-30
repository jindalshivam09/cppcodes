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
#define MAX 501
vector<vector<int> > memo(MAX,vector<int>(MAX));

int dp (const vector<string> &str,int n,int m,int i,int j,bool flag,vector<vector<bool> > visited,int count=0) {
	cout << "dp";
	if(i<0 || j<0 || i>n-1 || j >n-1)
		return 0;
	cout << i <<  " " << j << " " << flag << " " << count <<  " " << str[i][j] << endl;
	if(str[i][j] == '#')
		return 0;
	if(visited[i][j])
		return 0;
	visited[i][j] = 1;
	
	int queue = 0;
	if(memo[i][j])
		return memo[i][j];
	if(!flag){
		if(i+1<n)			queue = 1+dp(str,n,m,i+1,j,false,visited,count+1);
		if(j+1<m)			queue = max(queue,1+dp(str,n,m,i,j+1,false,visited,count+1));
		
		if(i>0){
			cout << "if \n";
			int c = 0;
//			visited[i][j] = 0 ;
			int temp = i;
			i--;
			while(i>=0 && str[i][j] != '#' && !visited[i][j]) {
				visited[i][j] = 1;
				cout << i << " " << j << endl;
				i--;
				c++;
			}		
			if(i>=0 && i<n) {
				visited[i][j] = 0;
				if(str[i][j] == '#')
					i++;
				if(temp != i+1)
				queue = max(queue,c+1+dp(str,n,m,i,j,true,visited,count+1+c));
			}
		}
		
		if(j>0 && i<n && j<n)	{
			cout << "else \n";
			int c = 0;
//			visited[i][j] = 0;
			int temp = j;
			j--;
			cout << "he";
			while(j>=0 && str[i][j] != '#' && !visited[i][j]) {
				c++;
				cout << "dfsa";
				visited[i][j] = 1;
				cout << "jindal";
				j--;
			}		
			if(j>=0 && j<n) {
				visited[i][j] = 0;
				if(str[i][j] == '#')
					j++;
				if(temp != j+1)
				queue = max(queue,c+1+dp(str,n,m,i,j,true,visited,count+1+c));
			}
		}
	}
	else {
		if(i+1<n)		queue = 1+dp(str,n,m,i+1,j,true,visited,count+1);
		if(j+1<m)		queue = max(queue,1+dp(str,n,m,i,j+1,true,visited,count+1));
	}
	return memo[i][j] = queue;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		vector<string> str(n);
		vector<vector<bool> > visited(n,vector<bool>(m));
		for(int i=0;i<n;i++)
			cin >> str[i];
		cout << dp(str,n,m,0,0,false,visited) << endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				visited[i][j] = memo[i][j] = 0;
	}

}


