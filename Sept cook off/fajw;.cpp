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
		int i,j;
		if (n==1 )	cout << m << endl;
		else if (m==1) cout << n << endl;
		else if (n==m) cout << n << endl;
		else 
		{
		if (n < m ) {
			
			for (i=2;i<=n;i++) {
			
				j = (i*(m-1)-m+n)/(n-1);
				
				if (i*(m-1)-m == j*(n-1)-n)
				break;
			}
			int temp = (j-1)*n + i;
			if(temp == n*m)	cout << (m*n)/temp+1<< endl;
			else cout << (m*n)/temp+1<< endl;
		}
		else {
		
			for (j=2;j<=m;j++) {
			
				 i = (j*(n-1)-n+m)/(m-1);
				
				if (i*(m-1)-m == j*(n-1)-n)
				break;
			}
			
			int temp = (i-1)*m + j;
			if(temp == n*m) cout << (m*n)/temp+1 << endl;
			else
			cout << (m*n)/temp+2 << endl;
		}
		
		}
	}
}
