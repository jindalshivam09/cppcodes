#include<bits/stdc++.h>
using namespace std ;

class Target {
	public :
		vector<string> draw ( int n ) {
			int cnt = n ;
			vector<string> ans(n) ;
			for(int i=0;i<n;i++)
				ans[i].resize(n) ;
			for(int i=0;i<n/2;i+=2) {
//				cout << cnt << endl;
				if(i%2==0) {
					int till = (n-cnt) / 2 ;
					int j=0;
					for(;j<=till;j++) {
						if(j%2==0)
							ans[i+1][j] = ans[i][j] = '#';
						else
							ans[i+1][j] = ans[i][j] = ' ';
					}
					for(int k=0;k<cnt-2;k++,j++)
						ans[i][j] = '#', ans[i+1][j] = ' ' ;
					for(;j<n;j++) {
						if(j%2==0)
							ans[i+1][j] = ans[i][j] = '#';
						else
							ans[i+1][j] = ans[i][j] = ' ';
					}
					cnt -= 4;
				}
			}
			for(int i=0;i<n;i++)
				if(i%2==0)
					ans[n/2][i] = '#';
				else
					ans[n/2][i] = ' ';
			for(int i=n-1;i>n/2;i--)
				ans[i] = ans[n-1-i] ;
		for(int i=0;i<n;i++)
			cout << ans[i] << endl;
		}
};

int main() {
	Target obj ;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n ;
		obj.draw(n) ;
	}
}
