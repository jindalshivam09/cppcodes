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
	int m1 = 5 , m2 = 2;
	int t;
	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		int temp = 0;
		bool flag = false;
		for(int i=0;i<str.size();i++) {
			if(i<3){
				temp = 2*temp + str[i] - 48;
			}
			else{
				temp -= 4*(str[i-3]-48);
				temp =  2*temp + str[i]-48;
			}
			if((temp==m1 || temp == m2) && i>=2) {
				cout << "Good" << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "Bad" << endl;
		
	}
}


