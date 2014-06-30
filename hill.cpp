#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#define MAX 100009
#define MOD 1000000009
using namespace std;
int hd[205][MAX];
main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int height[MAX],heightDiff[MAX],pos[205]={0};
        long long count = 0;
        int cmp=0;
        int unused[MAX],uq=0;
        int hdp[205]={0};
        int mid = 100;
        for(int i=0;i<n;i++)
        cin >> height[i];

        for(int i=1;i<n;i++) {
            heightDiff[i-1] = height[i] - height[i-1];
             if((!pos[mid + heightDiff[i-1]] && heightDiff[i-1] != heightDiff[0])  || i==1) {
                    pos[mid + heightDiff[i-1]] = i-1;
                    hd[mid+heightDiff[i-1]][hdp[mid+heightDiff[i-1]]++] = i-1;
                    count = (count%MOD + (n-i)%MOD)%MOD;
            }
            else {
                hd[mid+heightDiff[i-1]][hdp[mid+heightDiff[i-1]]++] = i-1;
                unused[uq++]=(i-1);
            }
       }
        bool flag = false;
        int q=0,k;
        int i;
        for(int t = 0; t<uq ;t++) {
            i = unused[t];
            q=0;
                for(k=0;i!=hd[mid+heightDiff[i]][k];k++){
             //       cout << "d";
                    flag = false;
                    cmp = hd[mid+heightDiff[i]][k];
                   // cout << cmp << " ";
                    for(int j=0;j<n-1 && j+i<n-1;j++){
                 //       cout << "t";
                       // cout << j+*i << " " << cmp+j << " ";
                      //  cout << heightDiff[j+*i] << "  " << heightDiff[cmp+j] << " ";
                        if(heightDiff[j+i] != heightDiff[cmp+j]) {
                          //  count = (count%MOD + (n-2-(i))%MOD)%MOD;
                            flag = true;
                            q++;
                            break;
                        }

                    }
                    if(q<k)
                    break;
                }
                //cout << q << " " << k << " ";
                if(q==k)
                count = (count%MOD + (n-2-(i))%MOD)%MOD;
            }

        cout << count << endl;
    }
}
