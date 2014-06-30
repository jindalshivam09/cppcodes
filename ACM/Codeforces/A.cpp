#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {

	int r1,c1,r2,c2;
	cin >> r1 >> c1 >> r2 >> c2;
	
	//-for rook
	int moves1 = 0;
	if(r1 == r2 && c1 == c2)
		cout << 0 << " ";
	else if (r1 == r2 || c1 == c2)
		cout << 1 << " ";
	else
		cout << 2 << " ";
			
	//for bishop--
	if((r1 + c1) % 2 && (r2+c2)%2) {
		if(r1 == r2 && c1 == c2)
			cout << 0 << " ";
		else if (abs(r1-r2) == abs(c1 -c2))
			cout << 1 << " ";
		else
			cout << 2 << " ";	
	}
	else if (!((r1 + c1)%2) && !((r2+c2)%2)) {
		if(r1 == r2 && c1 == c2)
			cout << 0 << " ";
		else if (abs(r1-r2) == abs(c1 -c2))
			cout << 1 << " ";
		else
			cout << 2 << " ";	
	}
	else
		cout << 0 << " ";	
		
	//for king---
	if(r1 > r2) {
		int temp=r1,temp2=c1;
		r1 = r2;
		c1 = c2;
		r2 = temp;
		c2 = temp2;
	}
	if(r1==r2 && c1==c2)
		cout << 0 << endl;
	else{
		int move = abs(r1-r2) + abs(c1-c2);
		if(r1 == r2 || c1 ==c2)
			cout << abs(r1-r2) + abs(c1-c2) << endl;
		else if(move) {
			cout << move - abs(r1-r2);
		}
		else
			cout << 0;
	}
}


