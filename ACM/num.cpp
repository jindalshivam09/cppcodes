#include<iostream>
#include<cstring>
#define MAX 1000000
using namespace std;

bool arr[MAX];

void sieve () {
    for(int j=2;j<=1000;j++) {
        if(!arr[j]) {
            for(int i=2*j;i<MAX;i+=j)
            arr[i] = true;
        }
    }
    /*for(int i=2;i<MAX;i++)
    if(!arr[i])
    cout << i << " ";*/
}
int prime[MAX];

void factors(int *prime,int m) {
    while(m>1) {
        for(int i=2;i<=m;i++)
        if(!arr[i] && !(m%i) ) {
            prime[i]++ ;
            m/=i;
            break;
        }
    }
}

main() {
    sieve();
    int t;
    cin >> t;
    while(t--) {
        int n;
        memset(prime,0,sizeof(prime));
        cin >> n;
        int m,q=0;
        for(int i=0;i<n;i++)
        {
            cin >> m;
            if(q < m)
            q = m;
            factors(prime,m);
        }
    long long ans=1;
    for(int i=2;i<=q;i++)
    ans*=prime[i]+1;
    cout << ans << endl;
    }
}
