#include<iostream>
#define MAX 1000009
using namespace std;
main() {
 <br>   int t;
    cin >> t;
    char p[MAX];
    while(t--) {
        cin >> p;
        int count=0,max=0,path=0;
        for(int i=1;p[i];i++) {
            if(p[i]=='.') {
                count++;
            }
            else if(p[i]=='#') {
                if(max<count) {
                    max=count;
                    path++;
                }
                count=0;
            }
        }
        cout << path << endl;
    }
}
