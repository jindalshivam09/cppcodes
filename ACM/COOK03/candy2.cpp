#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_N 15
#define MAX_C 500
#define SIZE (MAX_C*MAX_C*2)

char mark[SIZE];
int N;
int chocolate[MAX_N], caramel[MAX_N], surplus[MAX_N];
int dchoc, dcar;

void readinput(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", chocolate+i, caramel+i);
	}
	scanf("%d %d", &dchoc, &dcar);
}

int solve(){
	int lo=0, hi=0;
	for(int i=0; i<N; i++){
		surplus[i]=chocolate[i]*dcar-caramel[i]*dchoc;
//		cout << surplus[i] << " ";
		lo=min(lo, surplus[i]);
		hi=max(hi, surplus[i]);
	}
	int range=hi-lo+1;
	memset(mark, 0, sizeof mark);
	queue<int> cur, next;
	int iter=0;
	for(cur.push(0); !cur.empty() && !mark[0]; iter++){
		for( ; !cur.empty(); cur.pop()){
			int f=cur.front();
//			cout << f << " ";
			for(int i=0; i<N; i++){
				int n=f+surplus[i];
				if(0<=n && n<range && !mark[n]){
					mark[n]=1;
					next.push(n);
				}
			}
		}
		swap(cur, next);
	}
	return mark[0] ? iter : -1;
}

int main(){
//	readinput();
	ifstream cin("test.txt") ;
//	ofstream cout("1.txt") ;

	cin >> N ;
	for(int i=0;i<N;i++)
		cin >> chocolate[i] >> caramel[i];
	cin >> dchoc >> dcar ;
	cout << solve() ;
//	printf("%d\n", solve());
	return 0;
}
