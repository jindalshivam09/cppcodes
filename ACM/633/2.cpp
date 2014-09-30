#include<bits/stdc++.h>
using namespace std;

class Jumping {
	public :
		string ableToGet ( int x, int y, vector<int> len ) {
			int dist = x*x + y*y ;
			int tot = 0 ;
			for(int i=0;i<len.size();i++)
				tot += len[i]*len[i] ;
			if(len.size()==1) {
				if(tot != dist )
					return "Not able";
				return "Able" ;
			}	
			for(int i=0;i<len.size();i++) {
				if( tot-len[i]*len[i] <  len[i]*len[i] )
					return "Not able" ;
			}
			if( tot < dist )
				return "Not able";
			return "Able";		}
};
