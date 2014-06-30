#include<iostream>
#include<list>
#define MAX 100009
#define MOD 1000000009

using namespace std;

main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int height[n+1];
        int heightDiff[n+1];
        int pos[2*MAX+2]={0};
        bool allow[MAX]={false};
        long long count = 0;
        int cmp=0;
        int arr[MAX];
        int q=0;
        list<int> unused;

        for(int i=0;i<n;i++)
        cin >> height[i] ;

        for(int i=1;i<n;i++) {
            heightDiff[i-1] = height[i] - height[i-1];
            if((!pos[MAX + heightDiff[i-1]] && heightDiff[i-1] != heightDiff[0])  || i==1) {
                //    allow[i-1] = true;
                    pos[MAX + heightDiff[i-1]] = i-1;
                    count = (count%MOD + (n-i)%MOD)%MOD;
            }
            else unused.push_back(i-1);
        }
       // cout << count << " ";
//cout << "fd";
/*
       for(int i=0;i<n;i++) {
            cout << allow[i] << " ";
        }
        /*
        cout << endl;
        for(int i=0;i<n-1;i++) {
            cout << heightDiff[i] << " " << pos[heightDiff[i]] << " ";
        }*/

       // cout << count << " ";

       // for(list<int>::iterator j = unused.begin() ; j!=unused.end();j++)
       // cout << *j << " ";

        bool flag = true;;
        int i;
        list<int>::iterator last;
        for(list<int>::iterator j = unused.begin() ; j!=unused.end() ;j++) {
            if(!flag)
            j = last;

           // cout << "g";
            //cout << *j << " ";
          //      cin.get();
            flag = true;
             for( i=0;i<n-1 && *j+i<n-1;i++){
                    cmp = pos[MAX + heightDiff[*j]];
            //        cout << "(" << cmp << " "<< *j << ")";
          //              cout << i << " ";
                        if(heightDiff[*j+i] != heightDiff[cmp+i]) {
                            last = j;
                            last++;
                            unused.erase(j);
                       //     cout << "as";
                         //    for(list<int>::iterator q = unused.begin() ; q!=unused.end();q++)
                     //           cout << *q << " ";
                            flag = false;
                            count = (count%MOD + (n-2-(*j))%MOD)%MOD;
                            break;
                        }


         //           cout << count  << " ";
                   // if(!flag)
                   // break;
                //    cout << "uy";
            }

         //   cout << count << " ";
        }

        cout << count << endl;
    }
}
