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


#define MAX 10000
int k;

string preprocess (string str) {
	string temp;
	if (str.size() == 0)
		return temp = "^$";
	temp = "^";
	for (int i = 0 ; i < str.size() ; i ++) 
		temp += "#" + str.substr(i,1);
	temp += "#$";
	return temp;
}
int longest_pallindrome (string temp) {
	string str = preprocess(temp);
	vi pallin(str.size());
	int c = 0 , r = 0;
	for(int i=0;i<str.size();i++) {
		int i_mirror = c - (i-c) ;
		pallin[i] = r > i ? min ( r - i , pallin[i_mirror] ) : 0                                              ;
		while ( i-1-pallin[i] >= 0 && i+1+pallin[i] < str.size() && str[i-1-pallin[i]] == str[i+1+pallin[i]])
			pallin[i]++;
		
		if (r-i < pallin[i]) {
			c = i;
			r = c + pallin[i];
		}
	}

	ll ans = 0 ;
 	for(int i=0;i<str.size();i++) {
//		cout << pallin[i] << " ";
		if ( k <= pallin[i])	{
			if(k%2 && pallin[i]%2)
				ans ++;
			else if (k%2==0 && pallin[i]%2 == 0)
				ans++;
		}
	}
	return ans ;
}

int main() {
	cin >> k;
	string str;
	cin >> str;
	cout << longest_pallindrome(str);
}



