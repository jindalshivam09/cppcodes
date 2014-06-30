#include<iostream>
#define MAX 10009
using namespace std;

int price[MAX][MAX];
int dis[MAX][MAX];
int net[MAX][MAX];

void calNet(int n,int m) {
    for(int i=0;i<n;i++)
    for(int j=1;j<m;j++) {
        net[i][j] = price[i][j] - dis[i][j-1] ;
        if(net[i][j]<0)
            net[i][j] = 0;
     //   cout << net[i][j] << " ";
    }
}

long long calPrice(int n,int m) {

    int cost;
    int last,min=1000000;
    for(int j=0;j<m;j++) {
        if(min > price[0][j] + net[1][j]) {
            min = price[1][j] + net[1][j];
            last = j;
        }
        cost = min;
    }
    for(int j=1;j<n;j++) {
        min = 1000000;
        for(int i=0;i<m;i++) {
                if(last == i) {
                    if(min > net[i][j] + net[i+1][j]) {
                        min = net[i][j] + net[i+1][j];
                        last = j;
                    }
                }
                else {
                    if(min > price[i][j] + net[i][j+1]) {
                        min = price[i][j] + net[i][j+1];
                        last = i;
                    }
                }
        }
        cost += min;
    }
    return cost;
}

main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;

        cin >> n >> m;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> price[i][j];

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> dis[i][j];

        calNet(n,m);

 /*       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cout << net[i][j] << " ";
 */
        cout << calPrice(n,m) << endl;
    }
}
