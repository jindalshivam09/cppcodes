#include<iostream>
using namespace std;
main() {
    char str[10000];
    cin >> str;
    int index=0,till=0;
    bool flag=false;
    if(str[0]<0&&str[0]>9) {
        flag = true;
        str[0]=9;
    }
    int count=0,lastc=0;
    for(int i=1;str[i];i++) {
        if(str[i]>=0&&str[i]<=9)
        count++;
        else if(str[i]<0&&str[i]>9 && flag) {
            str[i]=9;
            if(count>lastc) {
                till=index;
                lastc=count;
            }
            else if(count==lastc) {
                for(int j=0;j<count;j++) {
                    if(str[index]>str[till]) {
                        till=index;
                        lastc=count;
                        break;
                    }
                    else if(str[index]<str[till])
                    break;

                }
            }
            count=0;
        }


    }
}
