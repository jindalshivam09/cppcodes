#include<iostream>
using namespace std;
#define MAX 150
#define MOD 1000000007

typedef long long ll;

ll pow(int q,int n)
{
    ll ans;
    if(n==1)
    return q;
    else {
        ans=pow(q,n/2)%MOD;
        ans*=ans;
        ans%=MOD;
        if(n%2){
        ans*=q;
        ans%=MOD;
        }
    }
    return ans;
}
ll fact[MAX];
void init()
{
    fact[0]=1;
    for(int i=1;i<=MAX;i++)    {
    fact[i]=(fact[i-1]*i)%MOD;
    }
}

main() {
    init();
    int t;
    cin >> t;
    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        ll fact1 = fact[n+m-3];
        ll fact2 = fact[n-1];
        ll fact3 = fact[m-2];
        ll fact4 = fact[n-2];
        ll fact5 = fact[m-1];
       // cout << fact1 << fact2 << fact3;
        ll path1 = ((((fact1*pow(fact2,MOD-2))%MOD)*pow(fact3,MOD-2))%MOD);
        ll path2 = ((((fact1*pow(fact4,MOD-2))%MOD)*pow(fact5,MOD-2))%MOD);

        ll path = path1 + path2;
        ll ans1 = (path1*k)/path;
        ll ans2 = (path2*k)/path;
        if(ans1 > ans2){
            if((path1*k)%path)
            cout << ans1+1 << endl;
            else cout << ans1 << endl;
        }
        else {
            if((path2*k)%path)
            cout << ans2+1 << endl;
            else cout << ans2 << endl;

        }
    }
}
