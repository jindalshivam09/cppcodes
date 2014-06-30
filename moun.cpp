#include<iostream>

#define MAX 100009
#define MOD 1000000009

using namespace std;

main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int height[n];
        int heightDiff[n];
        int pos[2*MAX]={0};
        bool allow[MAX]={false};
        long long count = 0;
        int cmp=0;

        for(int i=0;i<n;i++)
        cin >> height[i] ;

        for(int i=1;i<n;i++) {
            heightDiff[i-1] = height[i] - height[i-1];
            if((!pos[MAX + heightDiff[i-1]] && heightDiff[i-1] != heightDiff[0])  || i==1) {
                    allow[i-1] = true;
                    pos[MAX + heightDiff[i-1]] = i-1;
                    count++;
            }
        }

    /*    for(int i=0;i<n-1;i++) {
            cout << allow[i] << " ";
        }
        cout << endl;
        for(int i=0;i<n-1;i++) {
            cout << heightDiff[i] << " " << pos[heightDiff[i]] << " ";
        }*/

       // cout << count << " ";
        for(int i=1;i<n-1;i++) {
            for(int j=0;(j+i)<=n-2  ;j++) {
                if(allow[j])
                count = (count + 1)%MOD;
                else {
                    cmp = pos[MAX + heightDiff[j]];
                   // cout << "(" << cmp << ")";
                        if(heightDiff[j+i] != heightDiff[cmp+i]) {
                            allow[j] = true;
                            count = (count + 1)%MOD;
                        }

                }
            }
         //   cout << count << " ";
        }
        cout << count << endl;
    }
}
