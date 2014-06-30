#include<iostream>
using namespace std;
main() {
    char str[10000];
    cin >> str;
    int index=0,till=0;
    bool flag=false;
    if(str[0]<48||str[0]>57) {
        flag = true;
        str[0]=57;
    }
    int count=1,lastc=1;
    for(int i=1;str[i];i++) {
        if(str[i]>=48&&str[i]<=57)
       // cout << "f";
        count++;
        else if(str[i]<48||str[i]>57 && flag) {
            str[i]=57;
            if(count>lastc) {
                till=index;
                lastc=count;
            }
            else if(count==lastc) {
                int t=till,q=index;
                for(int j=0;j<count;j++) {
                    if(str[q]>str[t]) {
                        till=index;
                        lastc=count;
                        break;
                    }
                    else if(str[q]<str[t])
                    break;
                    else {
                        t++;
                        q++;
                    }
                }
            }
            count++;
            index=till++;
        //    flag=false;
        }


    }
    //cout << count << lastc << till << index;
    if(count>lastc) {
        lastc=count;
        till=index;
    }
    else if(count==lastc) {
                int t=till,q=index;
                for(int j=0;j<count;j++) {
                    if(str[q]>str[t]) {
                        till=index;
                        lastc=count;
                        break;
                    }
                    else if(str[q]<str[t])
                    break;
                    else {
                        t++;
                        q++;
                    }
                }
            }
    if(str[till]==48) {
    till++;
    }
    for(int i=0;i<lastc;i++)
    cout << str[till++];
    if(str[till]&&!flag)
    cout << 9;
}
