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
#define MOD 1000000007
#define MAX 101
long long rev[MAX];

long long calPow(long long a,long long b)
{
  if(!b)
    return 1;
  long long t=calPow(a*a%MOD,b/2);
  if(b&1)
    t=t*a%MOD;
  return t;
}

void init() {
	for(int i=1;i<101;i++) {
		rev[i] = calPow(i,MOD-2);
//		cout << rev[i] << " ";
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int a0,a1,a2,a3,s;
		cin >> a0 >> a1 >> a2 >> a3;
		cin >> s;
		vector<vll> objects(101,vll(101)) ,dp (101,vll(101));		
		for(int i=1;i<=s;i++) {
			ll temp = 0;
			temp = a0;
			temp += (i*a1);
			temp += (i*i*a2);
			temp += (i*i*i*a3);
			objects[i][0] = 1;
			for(int j=1;j<=s;j++) {
				objects[i][j] =  objects[i][j-1]*(temp+j-1)%MOD* rev[j] %MOD;
//				if(i==10)
//				cout << rev[j] << " ";
//				cout << objects[i][j] << endl;				
			}
		}
		for(int i=0;i<101;i++)
			dp[i][0] = 1;
			
		for(int i=1;i<=s;i++) 
			for(int j=1;j<=s;j++)
				for(int k=0;j>=i*k;k++) {
					dp[i][j] += (objects[i][k]*dp[i-1][j-i*k])%MOD;
					dp[i][j] %= MOD ;
//					if(i==10)
//					cout << dp[i][j] << " " << objects[i][k] << endl;
				}
		
  		cout << dp[s][s] << endl;
	}
}


