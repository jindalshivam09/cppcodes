#include <stdio.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 200001
#define NSMALL 8000

long long vll[NSMALL + 1], spll[NSMALL + 1];
int v[NMAX], sp[NMAX];
int N, S;

void ReadInput() {
	int i;

	//freopen("y.txt", "r", stdin);
	scanf("%d", &N);

	if (N <= NSMALL) {
		for (i = 1; i <= N; i++)
			scanf("%d", &vll[i]);
	} else {
		for (i = 1; i <= N; i++)
			scanf("%d", &v[i]);
//	}
}

#define SLARGE 6666666

int fpoz[SLARGE];
int exists[SLARGE];
vector<long long> svll;
int answer;

void Solve() {
	int i, j, k;

	if (N <= NSMALL) {
		int count=0;
		spll[0] = 0;
		for (i = 1; i <= N; i++)
			spll[i] = spll[i - 1] + vll[i];
		svll.resize(N * (N + 1) / 2);
		for (i = 1, k = 0; i <= N; i++)
			for (j = i - 1; j >= 0; j--) {
				count++;
				svll[k] = spll[i] - spll[j];
				k++;
			}
		sort(svll.begin(), svll.end());
		answer = 1;
		for (i = 1; i < k; i++)
			if (svll[i] > svll[i - 1])
				answer++;
		cout << count << endl;
	} 
	else {
		exists[sp[0] = 0] = 1;
		for (i = 1; i <= N; i++) {
			exists[sp[i] = sp[i - 1] + v[i]] = 1;
			fpoz[sp[i]] = i;
		}
		
		S = sp[N];
		fprintf(stderr, "N=%d S=%d\n", N, S);

		fpoz[S] = N;
		
			for(i=1 ; i <= sp[N] ; i++) {
		//	if(exists[i])
			cout << exists[i] << " "; 
		}
		cout << endl;
		for(i=1 ; i <= sp[N] ; i++) {
		//	if(fpoz[i])
			cout << fpoz[i] << " "; 
		}
		cout << endl;
	
	
		for (i = S; i > 0; i--)
			if (!fpoz[i])
				fpoz[i] = fpoz[i + 1];
		for(i=1 ; i <= sp[N] ; i++) {
			if(fpoz[i])
			cout << fpoz[i] << " "; 
		}
		int count = 0;
		cout << endl;
		answer = 0;
		for (i = 1; i <= S; i++) {
			for (j = fpoz[i], k = 0; j <= N; j++) {
				while (sp[j] - sp[k] > i){
					count++;
					k++;
				}
				if (sp[j] - sp[k] == i) {
					answer++;
					break;
				}
			}
		}
		cout << count << endl;
	}
}

void WriteOutput() {
	printf("%d\n", answer - 1);
}

int main() {
	int tstart = clock();
	ReadInput();
	Solve();
	WriteOutput();
	fprintf(stderr, "Duration=%.3lf sec\n", (double) (clock() - tstart) / CLOCKS_PER_SEC);
	return 0;
}

