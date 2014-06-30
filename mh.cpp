#include<iostream>
#define MOD 1000000009
using namespace std;
long long  p(int q,int n)
{
    long long ans;
    if(n==1)
    return q;
    else {
        ans=p(q,n/2)%MOD;
        ans=(ans*ans)%MOD;
        if(n%2)
        {
        ans=(ans*q)%MOD;
        }
    }
    return ans;

}

main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int h[n],hd[n];
        long long sum[n];
        bool pre[205][205]={false};
        long long f[205]={0};
        for(int i=0;i<n;i++) {
            cin >> h[i];
            if(i) {
                hd[i-1] = h[i]-h[i-1];
            }
        }
        //for(int i=0;i<5;i++) {
          //  for(int j=0;j<5;j++)
        //    cout << pre[100+i][100+j] << " ";
          //  cout << endl;
        //}
   //     for(int i=0;i<n-1;i++)
     //   cout << hd[i] << " ";
       // cout << endl;
        long long count = (((n*(n-1))%MOD)*p(2,MOD-2))%MOD;
        long long d=0;
        int i;
        for(i=0;i<n-1;i++) {
            if(f[100+hd[i]]) {
                if(pre[100+hd[i]][100+hd[i-1]]) {
                    d = ((d+sum[i-1])%MOD+1)%MOD;
                    sum[i] = sum[i-1]+1;
                }
                else {
                    d = (d+1)%MOD;
                    sum[i] = 1;
                }
            }
            else sum[i]=0;

            if(i)
            pre[100+hd[i]][100+hd[i-1]]=true;

         //   cout << d << " ";
            f[100+hd[i]]++;
        }
;     //   cout << count << " " << d << " ";
        cout << (count-d)%MOD << endl;
    }
}
