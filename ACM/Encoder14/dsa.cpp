#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include<iostream>
#define MID(x,y) ((x+y)/2)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAX = 4000005;
int phi[MAX];
bool noprime[MAX];
vector <int> prime;
void Euler(int n){
    phi[1] = 0;
    for (int i = 2; i <= n; i ++){
        if (!noprime[i]){
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < (int)prime.size() && prime[j] * i <= n; j ++){
            noprime[prime[j]*i] = 1;
            if (i % prime[j] == 0){
                phi[prime[j]*i] = phi[i] * prime[j];
            }
            else{
                phi[prime[j]*i] = phi[i] * phi[prime[j]];
            }
        }
    }
}
long long f[MAX];
int main(){

	Euler(MAX);
	mem(f, 0);
	for (int i = 1; i < MAX; i ++){
        for (int n = i*2; n < MAX; n += i){
            f[n] += i * phi[n/i];
        }
    }
	int n;
	while(scanf("%d", &n), n){
        long long res = 0;
        for (int i = 2; i <= n; i ++){
            res += f[i];
        }
       cout<<res<<endl;
	}
	return 0;
}
