#include <algorithm>
#include <cstdio>
#include <iostream>
 
using namespace std;
 
struct prtial_sum
{
	long long sum;
	int num;
};
 
bool cmp(prtial_sum a, prtial_sum b)
{
	return a.sum < b.sum;
}
 
prtial_sum a[1000333];
int f[1000333], b[1000333];
int n, i, j, x, k, res;
long long ans;
 
inline int get(int x) 
{
	res = 0;
	while (x >= 0)
	{
		res += f[x];
		x = (x & (x + 1)) - 1;
	}
	return res;
}
 
inline void add(int x, int d)
{
	while (x <= n)
	{
		f[x] += d;
		x = x | (x + 1);
	}
}
 
int main()
{
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		x -= k;
		a[i].sum = a[i - 1].sum + x;
		a[i].num = i;
	}
	n++;
	a[n].num = 0;
	a[n].sum = 0;
	sort(a + 1, a + n + 1, &cmp);
	x = 0;
	a[0].sum = a[1].sum - 1;
	for (i = 1; i <= n; i++)
	{
		if (a[i].sum > a[i - 1].sum) x++;
		b[a[i].num] = x;
	}
	add(b[0], 1);
	cout << b[0] << endl;
	for (i = 1; i <= n; i++)
	{
		ans += get(b[i]);
		add(b[i], 1);
	}
	printf("%lld\n", ans);
} 
