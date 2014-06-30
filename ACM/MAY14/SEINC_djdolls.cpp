#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace::std;

int get_val(vector<int> &A)
{
	vector<int> B;
	B.reserve(A.size());

	// init
	int prev = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == prev)
			continue;

		B.push_back(A[i] - prev);
		prev = A[i];
	}

	if (prev)
		B.push_back(-prev);

	// improve
	vector<int> three;

	for (int i = B.size() - 1; i >= 0; i--)
	{
		if (B[i] == 3)
		{
			three.push_back(i);
			continue;
		}

		if (B[i] == -3)
		{
			if (!three.empty())
			{
				int x = three.back();
				three.pop_back();

				B[x] = -1;
				B[i] = 1;
			}

			continue;
		}

		if (B[i] == -2)
		{
			if (!three.empty())
			{
				int x = three.back();
				three.pop_back();

				B[x] = -1;
				B[i] = 2;
			}
		}
	}

	vector<int> two;
	for (int i = B.size() - 1; i >= 0; i--)
	{
		if (B[i] == 2)
		{
			two.push_back(i);
			continue;
		}

		if (B[i] == -3)
		{
			if (!two.empty())
			{
				int x = two.back();
				two.pop_back();

				B[x] = -2;
				B[i] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < B.size(); i++)
		if (B[i] > 0)
			ans += B[i];

	return ans;
}

int main()
{
	freopen("test_SEINC.txt","r",stdin) ;
	freopen("SEINC2.txt","w",stdout) ;

	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int N;
		scanf("%d", &N);

		vector<int> A(N, 0);
		for (int i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);

			A[i] = x;
		}

		for (int i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);

			A[i] = (x + 4 - A[i]) % 4;
		}

		printf("%d\n", get_val(A));
	}

	return 0;
}
