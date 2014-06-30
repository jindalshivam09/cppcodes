#include<iostream>
using namespace std;

#define MAX 100008

int arr[MAX];

void sieve () {
    for(int j=2;j<=MAX;j++) {
        if(!arr[j]) {
            for(int i=2*j;i<=MAX;i+=j)
            arr[i]++;
        }
    }
    //int k=0;
    //prime[k++] = 2;
   // for(int i=3;i<MAX;i+=2)
    //if(!arr[i])
    //prime[k++] = i;

   // for(int i=0;i<30;i++)
 //   cout << i << " " << arr[i] << endl;
}

main() {
    sieve();
    int t;
    cin >> t;
    while(t--) {
        int a,b,k,count=0;
        cin >> a >> b >> k;
        for(int i=a;i<=b;i++) {
            if(arr[i] == k )
            count++;
            if(k==1 && !arr[i])
            count++;
        }
        cout << count << endl;
    }
}
