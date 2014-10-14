#include<bits/stdc++.h>
using namespace std;


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
#define MAX 100009
#define VAL 200
char s[MAX],w[MAX] ;
int memo[2][MAX];
int a, b, k, n, m;
int loop ;
int dp() {
	for(int i=0;i<=m;i++)
		memo[0][i] = memo[1][i] = VAL ;
	
	for(int i=0;i<=m;i++) {
		memo[0][i] = i*a ;
	}
	memo[1][0] = a ;

	int row ;
	for(int i=1;i<=n;i++) {
		row = i%2 ;
		memo[row][0] = i*a;
		for(int j=max(i-loop,1);j<=i+loop&&j<=m;j++) {
			int temp = memo[1-row][j-1]  ;
			if(s[i-1] != w[j-1])
				temp += b ;
			int temp2 = min(memo[1-row][j]+a,memo[row][j-1]+a) ;
			memo[row][j] = min(temp,temp2) ;		
		}
		for(int j=max(i-loop-1,1);j<=i+loop&&j<=m;j++) {
			memo[1-row][j] = VAL ;
		}
	}
	return memo[n%2][m] > k ? -1 : memo[n%2][m] ;
}

int main() {
	int t; 
	t = read_int() ;
	while(t--) {
		scanf("%s%s",s,w) ;
		n = strlen(s);
		m = strlen(w);
		a = read_int() ;
		b = read_int() ;
		k = read_int() ;
		if(!a)
			printf("0\n") ;
		else if(!b && n == m )
			printf("0\n") ;
		else {
			loop = k/(min(max(a,1),max(1,b))) + 1;
			printf("%d\n",dp()) ;
		}
	}
}
