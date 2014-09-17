#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t ;
	while(t--) {
		vector<int> candles(10);
		int pos , mincandles = 100 ;
		for(int i=0;i<10;i++){
			cin >> candles[i] ; 
			if(mincandles > candles[i]) 	
				mincandles = candles[i] , pos = i ;
		}
		if (pos == 0 ) {	
			int secondmin = 100 , secondpos ;
			for(int i=1;i<10;i++){
				if(secondmin > candles[i]) 	
					secondmin = candles[i] , secondpos = i ;
			}
			if(secondmin != mincandles)
				cout << "1";
			else	
				pos = secondpos ;
		}
			for(int i=0;i<candles[pos]+1;i++)
				cout << pos ;
			cout << endl;
	}
		
}
