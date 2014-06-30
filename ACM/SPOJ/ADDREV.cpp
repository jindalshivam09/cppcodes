#include <iostream> 
#include <list>
#include <vector>
#include <algorithm>
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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s1,s2;
		cin >> s1 >> s2;
		reverse(all(s1));
		reverse(all(s2));
		vi n1,n2,ans;
		int count = 0;
		while( count < s1.size() && !(s1[count]-'0'))
			count++;
		for(int i=count;i<s1.size();i++)
			n1.pb(s1[i]);
		
		count = 0;
		while( count < s2.size() && !(s2[count]-'0') )
			count++;
		for(int i=count;i<s2.size();i++)
			n2.pb(s2[i]);
//		cout << "dfs";
		int loop = min(n1.size(),n2.size());
		int carry = 0,a,b,j=n1.size()-1,k=n2.size()-1;
		for(int i=0;i<loop;i++) {
			a = n1[j--]-'0';
			b = n2[k--]-'0';
			ans.pb((a+b+carry)%10);
			carry = (a+b+carry)/10;
		}
		if(n1.size()>n2.size())
			for(int i=loop;i<n1.size();i++) {
				a = n1[j--]-'0';
				ans.pb((a+carry)%10);
				carry = (a+carry)/10;
			}
		else
			for(int i=loop;i<n2.size();i++) {
				a = n2[k--]-'0';
				ans.pb((a+carry)%10);
				carry = (a+carry)/10;
			}
		if(carry)
			ans.pb(carry);
		count=0;
		while(count < ans.size() && !ans[count]  )
			count++;
		bool flag = false;
		for(int i=count;i<ans.size();i++)
			cout << ans[i] , flag = true;;
		if(!flag)
			cout << 0;
		cout << endl;
	}
}
