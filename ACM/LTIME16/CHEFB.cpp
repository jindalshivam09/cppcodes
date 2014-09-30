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
//	for(int i=0;i<primes[5436].size();i++)
//		cout << primes[5436][i] << " ";
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

long long operations() {
	map<int,int> values ;
	
	for(int i=0;i<n;i++) {
		int temp = arr[i] ;
		if(temp == 1)
			continue ;
	//	cout << temp << "-> ";
		for(int j=0;j<primes[arr[i]].size();j++) {
			int div = primes[arr[i]][j] , cnt = 0;
	//		cout << div << "," ;
			while(temp % div == 0)
				temp /= div, cnt ++;
	//		cout << temp << endl;	
			int pre = values[div] ;
			pre = max ( pre, cnt) ;
			values[div] = pre;
		}
	//	cout << arr[i] << " " << temp << endl;
		if(temp > 1) {
			values[temp] = 1;
		}
	}
	
	long long ans = 0;
	for(map<int,int>::iterator itr = values.begin(); itr != values.end() ; itr ++) {
//		cout << itr->first << " " << itr->second << endl;
		ans += itr->second;
	}
	return ans ;
}

int main() {
	init() ;
	int t ;
//	cin >> t ;
	t= read_int();
	while(t--) {
//		cin >> n ;
		n = read_int() ;
		for(int i=0;i<n;i++)
//			cin >> arr[i] ;
			arr[i] =read_int();
			
		cout << operations() << endl;
	}
}
