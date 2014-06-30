#include<iostream>
#include<algorithm>
using namespace std;

main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int arr[n];
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
            int last = 1;
            int end;
            while(count<loop && !flag) {
                for(int i=1;i<=n;i++) {
                    if(arr[i] < arr[i-1]){
                        flag = false;
                        last = i-1;
                        break;
                    }
                    else flag= true;
                }
                if(!flag){
                    end = last+k;
                    if(last+k >n)
                    end = n;
                    sort(arr+last,arr+end);
                    if(last <n && last > n-k+1)
                    ans[count++] = n-k+1;
                    else if(last <= n-k+1)
                    ans[count++] = last;
                }
            }
        }
            cout << count << endl;
            for(int i=0;i<count;i++)
            cout << ans[i] << " ";
            cout << endl;
        }
    }

