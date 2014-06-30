
/*
	Name: finding local maximum in an unsorted array in log n
	Copyright: no rights
	Author: jindalshivam09
	Date: 30/01/14 15:17
	Description:
		G:\Algorithms docs\Find local minima in an array _ Data Structures and Algorithm (http://www.dsalgo.com/2013/03/find-local-minima-in-array.html)
	
	 TProblem: Given an array a of N distinct integers, design an O(log N) algorithm 
				to find a local minimum: an index i such that a[i-1] > a[i] < a[i+1].
				If a[0] < a[1] or a[N - 2] > a[N - 1] then a[0] or a[N - 1] is the local minimum, respectively. 
				Pick a[mid] where mid = N / 2. If it's not the answer, we have three cases:
				   1)  If a[mid - 1] < a[mid] < a[mid + 1], lower half will contain the local minimum.
				   2)  If a[mid - 1] > a[mid] > a[mid + 1], upper half will contain the local minimum.
				   3)  If a[mid - 1] < a[mid] > a[mid + 1], either half will contain the local minimum.
				Search on the new interval recursively.
				
				or
				
				If a[1] < a[2], a[1] is an LM.
				Otherwise, if a[n-1] > a[n], a[n] is an LM.
				Otherwise, the array entries start out descending (going from a[1] to a[2]) and ends up ascending 
				(going from a[n-1] to a[n]).  It follows that an LM must exist somewhere in between.  
				Examine a[n/2].  If a[n/2] > a[n/2+1], then by the same reasoning there is an LM in the upper half of the array.  
				Similarly, if a[n/2] < a[n/2+1] there is an LM in the lower half of the array.  Solve recursively in the appropriate half.
*/


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
#define MAX 1000
vi arr(MAX);
int n;

int local_minimum ( int start , int end ) {
	int mid = (start+end)/2;
//	cout << mid << endl;
//	cin.get();
	if ( mid - 1 < 0 || mid + 1 >= n  )
		return -1;
	if ( arr[mid-1] > arr[mid] && arr[mid] < arr[mid+1] )
		return arr[mid];
	else if ( arr[mid] > arr[mid+1] )
		return local_minimum(mid,end);
	else if ( arr[mid-1] < arr[mid] )
		return local_minimum(start,mid);
}

int main() {
	cin >> n;
	rep(i,n)
		cin >> arr[i];
	cout << local_minimum (0,n-1);
}


