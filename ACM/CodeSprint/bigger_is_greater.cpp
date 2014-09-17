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


string str ;
string lexicographic_greater() {
	string ans ;
	ans.resize(str.size());
	bool flag = false ;
	
	for(int i=str.size()-1;i>=0;i--) {
		vi visited(26) ;
		visited[str[i]-'a']++;
		char ch = 'z'+1 ;
		for(int j=i+1;j<str.size();j++) {
			if(str[j] > str[i] && str[j] < ch) {
				ch = str[j] ;
				flag = true ;
			}
			visited[str[j]-'a'] ++ ;
		}
		if(flag) {
			int k;
			for( k=0;k<i;k++)
				ans[k] = str[k] ;
			ans[k++] = ch ;
			visited[ch-'a'] -- ;
			for(int i=0;i<26;i++) {
				while(visited[i]--) {
					ans[k++] = (char)(i+'a') ;
				}
			}
			break;
		}
	}
	
	if(flag)
		return ans ;
	return "no answer" ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> str ;
		cout << lexicographic_greater() << endl;
	}
}


