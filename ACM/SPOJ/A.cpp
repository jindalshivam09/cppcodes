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

	string str;
	cin >> str;
	
	ll left = 0 , right = 0;
	
	int i=0;
	int pivot;
	while(str[i]) {
		if(str[i]=='^') {
			pivot = i;
			break;
		}
		i++;
	}
//	cout << pivot << endl;
	i=0;
	while(str[i] != '^') {
		if(str[i]>='1' && str[i]<='9') 
			left += (pivot-i)*(str[i]-'0');
		i++;
	}
	while(str[i]) {
		if(str[i]>='1' && str[i]<='9') 
			right += (i-pivot)*(str[i]-'0');
		i++;
	}
	if(left == right)		cout << "balance";
	else if(left < right)	cout << "right";
	else					cout << "left";
}


