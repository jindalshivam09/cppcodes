#include<stdio.h>
#include <bits/stdc++.h>
#include<string.h>
#define MAX 4000005
const int N = 4000000;
typedef long long LL;
int fun[MAX];
LL input[MAX];
using namespace std ;
void preprocess()
{
    memset(input, 0, sizeof(input));
    for(int i = 1; i <= N; i ++) fun[i] = i;
    for(int i = 2; i <= N; i ++)
    {
        if(fun[i] == i)
        {
            for(int j = i; j <= N; j += i)
                fun[j] = fun[j] / i * (i - 1);
        }
        for(int j = 1; j * i <= N; j ++)
            input[j * i] += j * fun[i];
    }
    for(int i = 1; i <= N; i ++) input[i] += input[i - 1];
}
int main()
{
    preprocess();
    int test ;
    cin >> test;
    while(  test-- ) {
    	int n;
    	cin >> n ;
	cout << input[n] << endl ;
    }
    return 0;
}
