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


// fast io 
#define getcx getchar_unlocked
#define putcx putchar_unlocked
 
inline void readInt( int &n ) {
    n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ){ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
 
inline void writeInt(int n) {
	int i = 10;
	char buf[11];
	buf[10] = '\n';
	
	while (n) {
		buf[--i] = n % 10 + '0';
		n /= 10;
	}
	
	do {
		putcx(buf[i]);
	} while (buf[i++] != '\n');
}
int main() {

}


