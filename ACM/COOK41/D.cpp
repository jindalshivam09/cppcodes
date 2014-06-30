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
#define MAX 5001
vector<vi> ones(MAX,vi(MAX));
char matrix[MAX][MAX];
	
void count_ones(int n,int m) {
	
	for(int i=0;i<n;i++) {
		ones[i][m-1] = matrix[i][m-1]-'0';
//		cout << ones[i][m-1];
		for(int j=m-2;j>=0;j--) {
			if(matrix[i][j]=='0')
				ones[i][j] = 0;
			else
				ones[i][j] = ones[i][j+1] + 1;
		}
//		cout << ones[i][j];
	}
}

int main() {
	int n,m;
	cin >> n >> m;
	rep(i,n)
			scanf("%s",matrix[i]);
			
	count_ones(n,m);
	int ans = 0;
	
		vi column(n);
	for(int j=0;j<m;j++) {
		int temp = imax;
		int count = 0;
		for(int i=0;i<n;i++)
			column[i] = ones[i][j];
		sort(all(column),greater<int>());
		int	overall_min = column[0];
		for(int i=0;i<n;i++) {
			temp = column[i];
			if(temp) {
				count ++;
				overall_min = min(overall_min,temp);
			}			
			ans = max(ans,overall_min*count);
		}
	}
	cout << ans << endl;
	
}


