#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n,m,c2,c3;
		cin >> n >> m >> c2 >> c3;
		vector<vector<char > >  input(n,vector<char>(m));
		
		int count=0;
		for(int i=0;i<n;i++) {
			
			for(int j=0;j<m;j++) {
	
				cin >> input[i][j];
				if(input[i][j] == 'B')
				count++;
			}
		}
		
		cout << count << endl;
		for(int i=0;i<n;i++) {
			
			for(int j=0;j<m;j++) {
				
				if(input[i][j] == 'B') {
					
					cout << 3 << " " << i+1 << " " << j+1 << endl;
				}
			}
		}
	}
}
