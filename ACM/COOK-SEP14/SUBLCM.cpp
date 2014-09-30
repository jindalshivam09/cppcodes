#include<bits/stdc++.h>
using namespace std ;
#define MAX 1000009
vector<vector<int> > primes(MAX);

void init() {
	vector<bool> visited(MAX) ;
	for(int i=2;i*i<MAX;i++) {
		if(visited[i]==false) {
			visited[i] = true ;
			for(int j=i;j<MAX;j+=i) {
				primes[j].push_back(i) ;
				visited[j] = true ;
			}
		}
	}
}

typedef long long ll;
#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline ll read_int()
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


int  n;
vector<int> arr(MAX) ;
vector<int> processed(MAX) , segment(2*MAX) ;

void update(int node,int i, int j) {
	if(i==j) {
//		cout << processed[i] << " ";
		segment[node] = processed[i] ;
		return ;
	}
	if(j<i)
		return ;
	int mid = (i+j)/2 ;
	update(2*node,i,mid) ;
	update(2*node+1,mid+1,j) ;
	segment[node] = min ( segment[2*node], segment[2*node+1] )  ;
	return  ;
}

int query( int node, int i, int j, int a, int b) {
//	cout << i << " " << j << " " << a << " " << b << endl;
//	cin.get() ;
	if(b < i || a > j)
		return n+1;
	if( i >= a && j <= b ) {
//		cout << segment[node] << " ";
		return segment[node] ;
	}
	int mid = (i+j)/2 ; 
	return min ( query(2*node,i,mid,a,b) , query(2*node+1,mid+1,j,a,b) ) ; 
}

void func () {
	vector<int> indexes(MAX) ;
	for(int i=0;i<primes[arr[n-1]].size();i++)
		indexes[primes[arr[n-1]][i]] = n-1;
	processed[n-1] = n;
	
	for(int i=n-2;i>=0;i--) {
		int temp = arr[i] ;
		int min_index = n; 
		for(int j=0;j<primes[temp].size();j++) {
			int val = primes[temp][j] ;
			if(indexes[val])
				min_index = min(indexes[val],min_index) ;
			indexes[val] = i ;
		}
		if(primes[temp].size() == 0) {
			int val = temp ;		
			if(indexes[val])
				min_index = min(indexes[val],min_index) ;
			indexes[val] = i ;
		}
		processed[i] = min_index ;
	}
	
//	for(int i=0;i<n;i++)
//		cout << processed[i] << " ";	
//	return 0;
}

int main() {
	init() ;
	int t; 
//	cin >> t ;
	t = read_int() ;
	while(t--) {
		n = read_int() ; ;
		for(int i=0;i<n;i++)
			 arr[i] = read_int() ;

		func();

//		for(int i=0;i<n;i++)
			update(1,0,n-1) ;
		
		int ans = -1 ;
		for(int i=0;i<n;i++) {
			ans = max ( ans, query(1,0,n-1,i,processed[i]-1) - i ) ;
		}
		if(ans > 1)
			cout << ans << endl; 
		else
			cout << -1 << endl;
	}
}
