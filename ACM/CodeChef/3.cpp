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

bool check(int a,int index) {
	bool ret = false ;
	if(index-2>=0  )	{
		if(str[index-1]-'a'+1 != a&& str[index-2]-'a'+1 != a)
			return true ;
		else
			return false ;
	}
	if(index-1>=0) {
		if(str[index-1]-'a'+1 != a)
			return true ;
		else
			return false ;
	
	}
	if(index==0)
		return true;
/*	if(index+2<str.size()  )	{
		if(str[index+1]-'a'+1 != a&& str[index+2]-'a'+1 != a)
			return true ;
		else
			return false ;
	}
	if(index+1<str.size()) {
		if(str[index+1]-'a'+1 != a)
			return true ;
	}
*/	return false ;
}

int main() {
	int n, p;
	cin >> n >> p ;
	cin >> str ;
	
	bool flag = false ;
	string ans;
	ans.resize(n) ;
	if(n==1) {
		if(str[0]-'a'+1 < p) {
			cout << char(str[0]+1) ;
			return 0;
		}
	}
	for(int i=str.size()-1;i>=0;i--) {
		int temp = str[i] - 'a' + 2 ;
		int a ;
		if(flag==false) {
//			cout << i << endl;
				while(temp <= p && check(temp,i)==false) {
					temp ++ ;
				}
//				cout << temp << endl;
				if(temp <= p ) {
					str[i] = ans[i] = (char)(temp+'a'-1) ;
					a = temp ;
					flag = true ;
				}
				if(flag) {
					for(int j=i+1;j<str.size();j++) {
						temp = str[j] - 'a' + 1 ;
						int temp2 = 1 ;
						while(temp2 <= p && check(temp2,j) == false)
							temp2 ++ ;
						if(temp2<=p)
							str[j] = ans[j] = temp2 + 'a' -1;
						else
							ans[j] = str[j] , flag = false;
					}			
				}
			}
		else
			ans[i] = str[i] ;
	}
	if(flag == false)
		cout << "NO" << endl;
	else {
		for(int i=0;i<str.size() ; i++)
			cout << ans[i] ;
	}
}



