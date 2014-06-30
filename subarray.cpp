#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<cstring>
#define MAX 100000000
using namespace std;
typedef long long ll;
int arr[MAX];

int getchar_unlocked() {return getchar();}
inline void f(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    x = (x<<1) + (x<<3) + c - 48;
    }
}
void print(ll n) {
    cout << n << " ";
}

main() {
    int t;
    f(t);
    for(int i=0;i<t;i++)
    f(arr[i]);
    set<ll> sum;
    ll temp;
    for(int i=0;i<t;i++) {
        temp = 0;
        for(int j=i;j<t;j++) {
            temp += arr[j];
            sum.insert(temp);
        }
    }

 //   for_each(sum.begin() , sum.end() , print);
    cout << sum.size() - 1;
}
