#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;

#define rep(n)    		for(int i=0;i<n;i++)
#define repi(k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()

int main() {

	vi parking(50) ;
	int x;
	
	for(int i=0;i<6;i++) {
		
		cin >> x;
		parking[x] = 1;
	}
	
	int bonus;
	cin >> bonus;
	
	for(int i=0;i<5;i++) {
		
		int count = 0;
		bool flag = false;
		for(int j=0;j<6;j++) {
			
			cin >> x;
			if(parking[x])
				count++;
			else if ( x == bonus )
				flag = true;
		}
		
		if(count==6)
			cout << "First Parking slot" << endl;
		else if(count==5 && flag )
			cout << "Second Parking slot" << endl;
		else if(count==5)
			cout <<"Third Parking slot" << endl;
		else if(count==4)
			cout << "Fourth Parking slot" << endl;
		else if(count==3)
			cout << "Fifth Parking slot" << endl;
		else 
			cout << "No Parking slot" << endl;
	}
	
}


