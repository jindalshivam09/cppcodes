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
char s[MAX], w[MAX];
int a,b,k;
map<pair<int,int>,int> memo ;
int n,m;

int dp(int i, int j, int cost = 0) {
	if(cost > k)
		return -1 ;
	if(i==n && j==m) 
		return 0;
	if(i==n)
		return (m-j)*a+cost > k ? -1 : (m-j)*a ;
	if(j==m)
		return (n-i)*a+cost > k ? -1 : (n-i)*a ;
	
	if(memo.count(make_pair(i,j)))
		return memo[make_pair(i,j)] ;
 
	int ret = INT_MAX, temp = -1;
	while(i<n && j<m && s[i] == w[j]) i++,j++ ;
	int temp1 = dp(i+1,j+1,cost+b) ;
	int temp2 = dp(i+1,j,cost+a) ;
	int temp3 = dp(i,j+1,cost+a) ;
	if(temp1 != -1)
		ret = min(ret,temp1+b) ;
	if(temp2 != -1)
		ret = min(ret,temp2+a) ;
	if(temp3 != -1)
		ret = min(ret,temp3+a) ;
	if(ret == INT_MAX)
	ret = -1;
	return memo[make_pair(i,j)] = ret;
}


int main() {
	int t ;
	t = read_int() ;
	while(t--) {
//		scanf("%s%s",s,w) ;
		gets(s) , gets(w); 
		n = strlen(s) ;
		m = strlen(w) ;
		a = read_int();
		b = read_int();
		k = read_int();
		if(!a)
			printf("0\n") ;
		else if(!b && n == m )
			printf("0\n") ;
		else
			printf("%d\n",dp(0,0)) ;
		memo.clear() ;
	}
}
