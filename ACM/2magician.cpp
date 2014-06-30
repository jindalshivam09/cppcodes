#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>

using namespace::std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int N, M, P;
		
		scanf("%d", &N);
		scanf("%d", &M);
		scanf("%d", &P);

		vector<vector<int> > adj(N, vector<int>());
		for (int i = 0; i < M; i++)
		{
			int x, y;

			scanf("%d", &x);
			scanf("%d", &y);

			x--;
			y--;

			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		vector<int> label(N, -1);
		int lv = 0;

		for(int i = 0; i < N; i++)
		{
			if (label[i] != -1)
				continue;

			list<int> q = list<int>();

			q.push_back(i);
			label[i] = lv;

			while(!q.empty())
			{
				int x = q.front();
				q.pop_front();

				for (int j = 0; j < adj[x].size(); j++)
				{
					int y = adj[x][j];
					if (label[y] == -1)
					{
						label[y] = lv;
						q.push_back(y);
					}
				}
			}

			lv++;
		}
		
		if (label[0] == label[1])
		{
			std::cout << "First" << std::endl;
			continue;
		}

		if (N == 2)
		{
			std::cout << "Second" << std::endl;
			continue;
		}

		int required = ((N * (N - 1))/2 - M - 1) % 2;

		if (N % 2)
		{
			if (required == 0)
				std::cout << "First" << std::endl;
			else
				std::cout << "Second" << std::endl;

			continue;	
		}

		vector<int> sizes(lv, 0);
		for (int i = 0; i < N; i++)
			sizes[label[i]]++;

		if (P == 0)
		{
			if (required == 0)
			{
				if ((sizes[label[0]] % 2 == 0) || (sizes[label[1]] % 2 == 0))
					std::cout << "First" << std::endl;
				else
					std::cout << "Second" << std::endl;
			}
			else
			{
				if ((sizes[label[0]] % 2 == 1) || (sizes[label[1]] % 2 == 1))
					std::cout << "First" << std::endl;
				else
					std::cout << "Second" << std::endl;
			}

			continue;
		}

		int even = 0;
		int odd = 0;

		for (int i = 0; i < lv; i++)
		{
			if (sizes[i] % 2)
				odd++;
			else 
				even++;
		}

		if (odd == 0)
		{
			if (required == 0)
				std::cout << "First" << std::endl;
			else
				std::cout << "Second" << std::endl;

			continue;
		}

		if (required == 0)
		{
			if (even == 0)
			{
				if (odd == 2)
					std::cout << "Second" << std::endl;
				else
					std::cout << "First" << std::endl;
			}
			else
				std::cout << "First" << std::endl;
		}
		else
		{
			if (even >= 2)
				std::cout << "Second" << std::endl;
			else
			{
				if (odd == 2)
					std::cout << "First" << std::endl;
				else
					std::cout << "Second" << std::endl;
			}
		}
	}
}

