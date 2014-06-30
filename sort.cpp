#include<iostream>
#include<algorithm>
using namespace std;

main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n+1];
        arr[0] = 0;
        for(int i=1;i<=n;i++)
        cin >> arr[i];

        int last,end,start;
        int loop = n*n/k + 10000;
        int count = 0;
        int ans[loop];
        bool flag = false;

        while(count < loop && !flag) {

            for(int i=1;i<=n;i++) {
                if(arr[i] < arr[i-1]) {
                    last = i-1;
                    flag = false;
                    break;
                }
                else flag = true;
            }
            //cout << "(" << last << ")";
            //cin.get();
            start = last;
            if(last <= 0)
            start = 1;
            if(last > n-k+1)
            start = n-k+1;
            bool f = false;
            if(!flag) {
                while(start < n && !flag) {

                    end = start+k+1;
                    if(start > n-k+1)
                    start = n-k+1;
                    if(start+k > n)
                    end = n+1;
                    sort(arr+start,arr+end);
                    ans[count++] = start;
                    start += k;
            //        cout << "[" << ans[count-1] << "]";
              //      for(int i=1;i<=n;i++)
                //    cout << arr[i] << " ";
                    for(int i=1;i<=n;i++) {
                        if(arr[i] < arr[i-1]) {
                            flag = false;
                            break;
                        }
                        else flag = true;
                    }
                }
            }
        }

        cout << count << endl;
        for(int i=0;i<count;i++)
        cout << ans[i] << " ";


    }
}
