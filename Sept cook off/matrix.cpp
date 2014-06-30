#include<iostream>
#include<vector>
using namespace std;


int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int n,m;
		cin >> n >> m ;
		int count = 0;
		
		if (n==1 )	cout << m << endl;
		else if (m==1) cout << n << endl;
		else if (n==m) cout << n << endl;
		else 
		{
		if (n < m ) {
			
			for (int i=1;i<=n;i++) {
			
				int j = (i*(m-1)-m+n)/(n-1);
				
				if (i*(m-1)-m == j*(n-1)-n)
				count++;
			}
		}
		else {
		
			for (int j=1;j<=m;j++) {
			
				int i = (j*(n-1)-n+m)/(m-1);
				
				if (i*(m-1)-m == j*(n-1)-n)
				count++;
			}
		}
		
		cout << count << endl;
		}
	}
}
