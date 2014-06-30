#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;

main() {
    int t;
    cin >> t;
    while(t--) {
        ll k;
        cin >> k;
        ll leaves[k];
        ll tot=0,allow=1;
        bool flag = false;
        for(ll i=0;i<k-1;i++)
        {
            cin >> leaves[i];
            tot = leaves[i];
            if(tot<allow) {
                allow = 2*(allow-tot);
            }
            else {
                flag = true;
                break;
            }
            cout << tot << " " << allow << endl;
        }

        if(!flag && leaves[k-1]==allow)
        cout << "Yes" << endl;
        else
        cout << "No" << endl;
    }
}
