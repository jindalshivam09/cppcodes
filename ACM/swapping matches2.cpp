#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 100000000
using namespace std;

#define MAXN 110000

int d[MAXN];
int n;
int prv[MAXN];
int v[MAXN];
int szpm, szv;
void mergesort(int low, int high)
{
	if(low == high)
	{
		return;
	}
	if(high - low == 1)
	{
		if(d[low] > d[high] + 1)
		{
			swap(d[low], d[high]);
		}
		return;
	}
	int mid = (low + high) / 2;
	mergesort(low, mid);
	mergesort(mid + 1, high);
	
	int i, j, k;
	int p1 = mid, p2 = high;
	int pmax = -1;
	szpm = 0;
	for(i = mid + 1; i <= high; i++)
	{
		
		prv[szpm] = pmax;
		pmax = MAX(pmax, d[i]);
//		cout << prev[szpm] <<  " " << pmax << endl;
		szpm++;
	}
	szv = 0;
//	cout << low << " " << mid << endl;
	while(p1 >= low && p2 > mid)
	{
		if(d[p1] <= d[p2] + 1)
		{
			v[szv++] = (d[p2--]);
		}
		else
		{
			if(prv[szpm - 1 -high + p2] + 1 >= d[p1])
			{
				v[szv++] = (d[p2--]);
			}
			else
			{
				v[szv++] = (d[p1--]);
			}
		}
//		cout << v[szv-1] << " " << p1 +1 << " " << p2 + 1 << endl;
	}
	while(p1 >= low)
	{
		v[szv++] = (d[p1--]);
	}
	while(p2 > mid)
	{
		v[szv++] = (d[p2--]);
	}
	int tn = szv;
	for(i = 0; i < tn; i++)
	{
		d[high - i] = v[i];
	}
	return;
}
int main()
{
	int tes;
	scanf("%d", &tes);
	while(tes --)
	{
		scanf("%d", &n);
		int i, j, k;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &d[i]);
		}
		mergesort(0, n - 1);
		for(i = 0; i < n; i++)
		{
			printf("%d ", d[i]);
		}
		printf("\n");
	}
	return 0;
}
