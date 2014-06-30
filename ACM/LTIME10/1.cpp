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

map<char,int> val ; 
void init () {
	char a = '0';
	for(char i = a ; i <= '9' ; i ++) {
		val[i] = i-'0';
//		cout << i << " " << val[i] << endl;
	}
	for(char i = 'a' ; i <= 'f' ; i++)
		val[i] = i - 'a' + 10 ;
//	val['0'] = 0 , val['0'] = 0 , val['0'] = 0 ,  val['0'] = 0 ,  val['0'] = 0 ,  val['0'] = 0 ,  
}

int main() {
	init () ;
	int n;
	cin >> n ;
	ll count = 0 ,j,a,b,c;
	string str ;
	while(n--) {
		cin >> str ;
		bool flag = false , ok = true ; 
		for(int i=2;i<=16;i++) {
			ok = true ;
			a = 0 , b = 0 , c = 0;
			j = 0;
			while(str[j] != '+') {
				if ( val[str[j]] >= i) {
					ok = false ;
					break;
				}
				a = a*i + val[str[j]] , j ++ ;
			}
			while(str[j] != '=') {				
				if ( val[str[j]] >= i) {
					ok = false ;
					break;
				}
				b = b*i + val[str[j]] , j ++ ;
			}
			while(str[j] != '\0') {
				if ( val[str[j]] >= i) {
					ok = false ;
					break;
				}
				c = c*i + val[str[j]] , j ++ ;
			}
//			cout << a << " " << b << " " << c << endl;
			if (a+b == c && flag == false && ok == true  )
				count ++ , flag = true;

		}
	}
	cout << count << endl;
}


