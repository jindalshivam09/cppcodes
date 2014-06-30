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

	int t;
	cin >> t;
	while(t--) {
		
		int n,c;
		cin >> n >> c;
		
		int temp = n/c;
		if(n%c)
			temp++;
		
		cout << temp-1 << endl;
	} 
}


