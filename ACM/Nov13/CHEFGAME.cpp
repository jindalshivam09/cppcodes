#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int k;
		cin >> k;
		if(!k)		cout << "DON'T PLAY" << endl;
		else {
	
			vector<vector<int> > piles(k);
			
			int temp;
			for(int i=0;i<k;i++) {
				
				int p;
				cin >> p;
				for(int j=0;j<p;j++) {
			
					cin >> temp; 
				 	piles[i].push_back(temp);
				 }
			}
			
			for(int i=0;i<k;i++) {
				
				sort(piles[i].begin(),piles[i].end());
			}
			
			long long sum = 0 ;
			
			for(int i=0;i<k;i++) {
				
				if(piles[i].size()) {
					
					long long val = pow(2,46);
					bool flag = false;
					int index = 0;
					int j=0;
					if(piles[i][0]%2) {
			
						for(j=0;j<piles[i].size();j++) {
							
	//						cout << j << " ";
							if( piles[i][j]%2) 
								sum += val;
							else  {
								index = j;
								break;	
							}
						}
					}
					else {
					
						for(j=0;j<piles[i].size();j++) {
							
	//						cout << j << " ";
							if( !(piles[i][j]%2) ) 
								sum -= val;
							else {
								index = j;
								break;
							}
						}
					}
	//				cout << index << " fd " << val << "jj  "<< even_sum << " jj" << odd_sum << endl;
					val /= 2;
//					cout << sum << endl;
					for(;j<piles[i].size();j++) {	
					
						if(piles[i][j]%2) 
							sum += val;
						else  
							sum -= val;
						val /= 2;				
	//						cout << even_sum << " df " << odd_sum << endl;
					}
					
//					cout << sum << endl;
				}
			}
//			cout << sum;
			if(sum > 0) 			cout << "ODD";
			else if(sum < 0)		cout << "EVEN";
			else					cout << "DON'T PLAY";
			cout << endl;
		}
	}
}
