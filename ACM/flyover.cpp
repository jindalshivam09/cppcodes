/*

	for M = 0 ;			(C-2).x + 2.N^2 + (C-4).N – (C-2)
	if C – 2 < 0 i.e. C < 2			x = (N (N - 1)) / 2 – (N – 1); C (N (N-1))/2 + (N (N-1))
*/	
	


#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<utility>
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		long long n,m;
		double c;
		cin >> n >> c >> m;
		vector<pair<int,int> > free_edge(m);
		int a,b;
		for(int i=0;i<m;i++) {
			cin >> a >> b;
			free_edge[i] = (make_pair(a,b));
		}
		
		float ans;
		if(m==0) {
		
			if(c<2)	{

				cout.precision(10);
				cout << c * (n * (n-1))/2 + (n * (n-1)) ;
			}
			else if (c>2) {
			
				cout.precision(10);
				cout << ((2*n*n) + (c-4)*n - (c-2));
			}	
			else {
			
				cout.precision(10);
				cout << 2*n*n + (c-4)*n ;
			}
		}
		
		else if(m==1) {
			
			if(c<2)	{

				cout.precision(10);
				cout << c * (n * (n-1))/2 + (n * (n-1)) - c;
			}
			else if (c>2) {
			
				cout.precision(10);
				cout << 2*n*n + (c-4)*n - (c-2) - c;
			}	
			else {
			
				cout.precision(10);
				cout << 2*n*n + (c-4)*n - c;
			}
		}
		else {
			
			if (free_edge[0].first == free_edge[1].first || free_edge[0].first == free_edge[1].second || free_edge[0].second == free_edge[1].first || free_edge[0].second == free_edge[1].second) {
			
				if(c<2)	{
	
					cout.precision(10);
					cout << c * (n * (n-1))/2 + (n * (n-1)) - 2*c;
				}
				else if (c>2) {
				
					cout.precision(10);
					cout << 2*n*n + (c-4)*n - (c-2) - 2*c;
				}	
				else {
				
					cout.precision(10);
					cout << 2*n*n + (c-4)*n - 2*c;
				}
			}
			else {
			
				if (c<2) {
				
					cout.precision(10);
					cout << c * (n * (n-1))/2 + (n * (n-1)) - 2*c;
				}
				else if(c==2) {
				
					cout.precision(10);
					cout << 2*n*n + (c-4)*n - 2*c;
				}
				else if (c>2){
				
					if( c >= 2*(n-2)) {
					
						cout.precision(10);
						cout << 2*n*n + (c-4)*n - (c-2) - 2*c;
					}
					else {
					
						cout.precision(10);
						cout << 2*n*n + (c-4)*n - (c-2) - c;
					}
 				}
 			}
					
		}
		cout << endl;
	}
}
