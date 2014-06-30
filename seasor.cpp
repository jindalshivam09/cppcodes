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
            int last;
            while(count<loop && !flag) {
                last = 1;
                for(int i=2;i<=n;i++) {
                    if(arr[i]>=arr[i-1])
                    flag = true;
                    else {
                        last = i-1;
                        flag = false;
                        break;
                    }
                }
                l = last-k+2;
                if(l<=0)
                l=1;
                //cout << last << " " << l << " ";
                while(l+k-1<=n && count<loop) {
                    //cout << l << " ";
                    ans[count++] = l;
                    sort(arr+l,arr+l+k);
                   /* for(int i=1;i<=n;i++)
                cout << arr[i] << " ";
                cout << endl;*/

                    l ++;
                }
                last = n;
                for(int i=n-1;i>0;i--) {

                    if(arr[i+1]>=arr[i])
                    flag = true;
                    else {
                        last = i;
                        flag = false;
                        break;

                    }
                }
                if(last > 0 && l!=last && last < n-k+1)
                l = last;
                else l -= 2;
                //cout << last << " " << l << endl;
                while(l>0 && count<loop) {
                    sort(arr+l,arr+l+k);
                    ans[count++] = l;
                    l --;
                }
                flag = true;
                for(int i=1;i<=n;i++) {
                    if(arr[i]>=arr[i-1])
                    flag = true;
                    else {
                        flag = false;
                        break;
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
