#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace::std;

uint64_t mod = 1000000007;

uint64_t inv(uint64_t a, uint64_t p)
{
        a %= p;
        if (a == 1)
                return 1;

        uint64_t q = p / a;
        uint64_t r = p % a;

        uint64_t y = inv(r, p);
        uint64_t x = (q * (p - y)) % p;
        return x;
}

bool has_matching(vector<vector<uint64_t> > &a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		int pivot = -1;
		for (int j = i; j < n; j++)
		{
			if (a[j][i])
			{
				pivot = j;
				break;
			}
		}

		if (pivot == -1)
			return false;

		for (int j = 0; j < n; j++)
		{
			uint64_t tmp = a[i][j];
			a[i][j] = a[pivot][j];
			a[pivot][j] = tmp;
		}

		uint64_t c = inv(a[i][i], mod);
		for (int j = i + 1; j < n; j++)
		{
			if (a[j][i] == 0)
				continue;

			uint64_t d = (c * a[j][i]) % mod;
			d = mod - d;

			for (int k = 0; k < n; k++)
				a[j][k] = (a[j][k] + d * a[i][k]) % mod;
		}
	}

	return true;
}

int main()
{
	srand(time(0));

	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int n, m;
		scanf("%d", &n);
		scanf("%d", &m);

		vector<vector<uint64_t> > a(n, vector<uint64_t>(n, 0));
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);

			x--;
			y--;
			
			uint64_t z = 1 + rand() % (mod - 1);
			a[x][y] = z;
			a[y][x] = mod - z;
		}

		if (n % 2)
			printf("NO\n");
		else
		{
			if (has_matching(a))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}	

	return 0;
}

