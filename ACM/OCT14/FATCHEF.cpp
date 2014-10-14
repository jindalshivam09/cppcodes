#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009
typedef long long ll ;

#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline long long read_int()
{
int flag=1;
long long n = 0;
char c;
int sign=1;
while (1)
{
c=GETCHAR();
if(c=='-')	sign=-1;
else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
 }
return sign*n;
}

int main() {
	int t ;
	t = read_int() ;
	while(t--) {
		int n,m;
		n = read_int() ;
		m = read_int() ;
		vector<pair<int,char> > input(m) ;
		ll ans = 1 ;
		char ch;
		int a ;
		for(int i=0;i<m;i++) {
			scanf("%c",&ch) ;
			a = read_int() ;
			input[i].first = a, input[i].second = ch ;
//			cout << ch << endl ;
		}
		
		sort(input.begin(),input.end()) ;
		for(int i=0;i<m;i++) {
			if(i && input[i].second != input[i-1].second) {
				ans = (ans * (input[i].first - input[i-1].first )) % MOD ;
			}
		}
//		cout << "shivam";
		printf("%lld\n",ans) ;
	}
}
