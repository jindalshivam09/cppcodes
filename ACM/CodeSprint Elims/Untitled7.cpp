#include<bits/stdc++.h>
using namespace std;
#define MAX 21
int n,k ;
vector<vector<int> > matrix(MAX,vector<int>(MAX)) , sum(MAX,vector<int>(MAX));
map<pair<int,int>,int> memo ;
#define MAX 1000000009

int funct(int index, int num) {
//	cout << index << " " << num << endl;
	if(index > n)
		return 0 ;
	
	if(memo.count(make_pair(index,num)) )
		return memo[make_pair(index,num)] ;
	int ans = MAX ;
	for(int j=1;j<=k;j++) {
		if((num&(1<<j)) == 0) {
			int cnt = 0 ;
			for(int i=index;i<=n;i++) {
				cnt += matrix[j][i] ;
				ans = min ( ans, cnt + funct(i+1,num|(1<<j)) ) ;
			}
		}
	}
//	cout << ans << endl;
	return memo[make_pair(index,num)] = ans ;		
}

int main() {
	cin >> n >> k ;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) {
			cin >> matrix[i][j] ;
			sum[i][j] = sum[i][j-1] + matrix[i][j] ;
		}
			
	cout << funct(1,0) << endl;
}
