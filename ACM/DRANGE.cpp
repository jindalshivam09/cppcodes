#include<iostream>
#include<limits>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

main () {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,m;
		int w,x,y,z;
		scanf("%d%d",&n,&m);
		vector<int> d;
		d.resize(n+1,1);
		int a[n+1];
		a[1] = 1;
	//	for(int i = 1 ;i <= n ; i++)
	//	cout << d[i] << " ";
		for(int i = 0 ; i < m ; i ++) {
			scanf("%d%d%d%d",&w,&x,&y,&z);
			if (x==1 && w==1)
			a[1] += z;
			else if(x==1 && w==2)
			a[1] -= z;
			if(w==1) {
				d[x-1] += z;
				d[y] -= z; 
			}
			else {
				d[x-1] -= z;
				d[y] += z;	
			}
		}
	//	cout << a[1] << " ";
	//	for (int i = 1 ; i <= n ; i ++)
	//	cout <<  d[i] << " ";
		int maxn = numeric_limits<int>::min();
		int minn = numeric_limits<int>::max();
		for(int i = 2 ; i <= n ; i++) {
			a[i] = a[i-1] + d[i-1];
			maxn = max(maxn,a[i]);
			minn = min(minn,a[i]);
		}
		
	//	for (int i = 1 ; i <= n ; i ++)
	//	cout << a[i] << " ";
		printf("%d\n",maxn-minn);
	}
}
