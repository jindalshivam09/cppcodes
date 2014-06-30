#include<iostream>
#include<algorithm>
using namespace std;

main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int arr[n +1];
        arr[0] = 0;
        for(int i=1;i<=n;i++)
        cin >> arr[i];
        int l=1;
        int count=0;
        //ans[count++] = l;
        int loop = n*n/k + 1000;
        int ans[loop];
       // cout << loop;
        if(n<k)
        cout << 0 << endl;
        else {
            bool flag = false;
            int last;
            while(count<loop && !flag) {
                last = 1;
                while(last<n && !flag) {
                    for(int i=1;i<=n;i++) {
                        if(arr[i]>=arr[i-1])
                        flag = true;
                        else {
                            last = i-1;
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) {
                        cout << "s";
                        ans[count++] = last;
                        //cin.get();
                        int end = last+k;
                        if(last+k > n)
                        end = n;
                        sort(arr+last ,arr+end);
                    }
                }
                while(last>0 && !flag) {
                    for(int i=n-k;i>0;i--) {
                        if(arr[i]>=arr[i-1])
                        flag = true;
                        else {
                            last = i-1;
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) {
                        cout << "f";
                        ans[count++] = last;
                        //cin.get();
                        int end = last+k;
                        if(last+k > n)
                        end = n;
                        sort(arr+last ,arr+end);
                    }
                }
            }
            cout << count << endl;
            for(int i=0;i<count;i++)
            cout << ans[i] << " ";
            cout << endl;
        }
    }
}
