#include<stdio.h>
#include<math.h>
#include<map>
#include<iostream>
using namespace std;
map <unsigned int, int> num;
long long int partition(unsigned int n)
{
	cout << n << endl;
	if(num.find(n) != num.end())
		return num[n];
	long long int c=1;
	int temp = (int)sqrt(n);
	int i;
	for(i=2;i<=temp;i++)
	{
		if(n%i == 0)
		{
			if(i*i == n)
				c+= partition(i);
			else
				c+= partition(i) + partition(n/i);
		}
	}
	num[n] = c;
	return c;
}
int main()
{
	int test;
	unsigned int n;
	int i;
	num[1] = 1;
	scanf("%d",&test);
	for(i = 0; i< test ; i++)
	{
		scanf("%u",&n);
		long long int ans = partition(n+1);
		printf("%lld\n",ans);
	}
	return 0;
} 
