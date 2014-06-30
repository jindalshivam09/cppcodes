#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int r,c;
		cin >> r >> c;
		vector<vector<int> > matrix(r,vector<int>(c));
		
		char ch;
		int temp;
		cin >> ch;
		for (int i=0;i<r;i++) {
		
			cin >> ch;
			for(int j=0;j<c;j++) {
		
				if (j != c-1) {
	
/*					if(!i) {				
						scanf ("[(%d,",&temp);
						matrix[i][j] = temp;
					}
					else {
*/					
						scanf ("%d,",&temp);
						matrix[i][j] = temp;					
//					}
				}	
				else {
						
						scanf("%d",&temp);
						matrix[i][j] = temp;		
				}
//				cout << matrix[i][j] << " ";
			}
			if( i != r-1)
			cin >> ch >> ch;
			else cin >> ch;

		}
		cin >> ch;
		for (int j=0;j<c;j++) {
		
			for(int i=0;i<r;i++) {
			
				temp = matrix[i][j];
				if (!i) {
	
					if(!j) {				
						printf ("[(%d, ",temp);
					}
					else {
					
						printf ("(%d, ",temp);
					}
				}	
				else if (i!=r-1) {
					
					printf("%d, ",temp);
				}
				else {

					if(j!=c-1) {
						
						printf("%d), ",temp);
					}
					else {
						
						printf("%d)]",temp);
					}
				}
//				cout << matrix[i][j] << " ";
			}
			
		}
		cout << endl;
	}
}

