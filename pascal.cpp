#include<iostream> 
#include<vector>
#define MAX 100

using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	vector<vector<int> > pas(MAX,vector<int>(2*MAX));
	
	for(int i=1;i<=t;i++) {
		
		pas[i][1] = 1;
		
		for(int j = 2 ; j < i ; j++) {
				
			pas[i][j] = pas[i-1][j] + pas[i-1][j-1] ;
		}
		
		pas[i][i] = 1;
	}
	
	for(int i=1;i<=t;i++) {
		
		for(int j=1;j<=t - i ; j++)
		cout << "  ";
		
		for(int j=1;j<=i;j++){
			
			cout.width(3);
			cout <<  pas[i][j] << " ";
		}
			
		cout << endl;
	}

}
