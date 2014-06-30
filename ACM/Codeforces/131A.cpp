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
	int count = 0;
	for(int i=0;i<str.size();i++)
		if (str[i]>='A' && str[i] <= 'Z')
			count++;
	bool flag = false;
	if(count==str.size())
		flag = true;
	else if (count==str.size()-1 && str[0]>='a' && str[str.size()-1]<='z')
		flag = true;
	
	if(!flag)
		cout << str;
	else {
		if(count == str.size())
			str[0] += 32 , cout << str[0] ;
		else
			str[0] -= 32 , cout << str[0];
			for(int i=1;i<str.size();i++)
				str[i] = str[i]+32 , cout << str[i];
		
	}
		
}


