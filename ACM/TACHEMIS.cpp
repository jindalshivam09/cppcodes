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
/*
static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

*/
#define MAX 10000

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
ll longest_pallindrome (string temp) {
	string str = preprocess(temp);
	vi pallin(str.size());
	int c = 0 , r = 0;
	for(int i=0;i<str.size();i++) {
		int i_mirror = c - (i-c) ;
		pallin[i] = r > i ? min ( r - i , pallin[i_mirror]) : 0;	
		while ( i-1-pallin[i] >= 0 && i+1+pallin[i] < str.size() && str[i-1-pallin[i]] == str[i+1+pallin[i]])
			pallin[i]++ ;
		if (r-i < pallin[i]) {
			c = i;
			r = c + pallin[i];
		}
	}
	int n;
//	cout << str << endl;
	ll ans = 0;
	for(int i=0;i<str.size();i++) {
//		cout << pallin[i] ;
		if (pallin[i]>1) {
			if (pallin[i]%2) {
				n = (pallin[i] - 3 ) / 2 + 1;		
				ans += n ;
			}
			else {
				n = (pallin[i] - 2 ) / 2 + 1;		
				ans += n  ;
			}
		}
	}
	return ans + temp.size();
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		char ch;
		int k;
		string str = "";
		rep(i,n) {
			cin >> ch >> k;
			rep(j,k)
				str += ch;
		}
		cout << longest_pallindrome (str) << endl;
	}	
}


