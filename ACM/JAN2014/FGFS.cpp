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
#define MAX 100009

int readint()
    {
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
}
struct customer {
	pii time;
	long c;
} input[MAX];

bool cmp (const struct customer &a,const struct customer &b) {
	return a.c == b.c ? a.time.second < b.time.second : a.c < b.c;
}

int main() {
	int t;
	t = readint();
	while(t--) {
		int n,k;
		n = readint();
		k = readint();
		int a,b,c;
		for(int i=0;i<n;i++) {
			a = readint();;
			b = readint();;
			c = readint();;
			input[i].time = mp(a,b);
			input[i].c = c;
		} 
		sort(input,input+n,cmp);
		long count = 0;
		for(int i=0;i<n;) {
			c = input[i].c;
			int last = input[i].time.first;
			while(c==input[i].c) {
				if (last <= input[i].time.first) {
					count++;
					last = input[i].time.second;
				}
				i++;
			}
		}
		cout << count << endl;
	}
}
