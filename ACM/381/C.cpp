#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef list<int>   li;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<long long>   vll;
typedef vector<bool>    vb;
typedef pair<int,int>   pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double>     pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)        for(int i=0;i<n;i++)
#define repi(i,k,n)     for(int i=k;i<n;i++)
#define mp              make_pair
#define pb              push_back
#define all(a)          a.begin(),a.end()
#define imax            numeric_limits<int>::max()
#define imin            numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {
    ll m;
    cin >> m;
    ll t,a,b;
    ll index = 0;
    vll arr;
    map<ll,ll> maped;
    pii tmp;
    for(ll i=0;i<m;i++) {
        cin >> t;
        if(t==1) {
            cin >> a;
            arr.pb(++index);
            maped[index] = a;
        }
        else {
            cin >> a >> b;
            index += a*b; 
            arr.pb(index);
            maped[index] = -1*a;
        }
  //      cout << index << endl;
    }
    ll n;
    cin >> n;
    bool flag = false;
    for(ll i=0;i<n;i++) {
        cin >> a;
        while(!flag) {
            index = lower_bound(all(arr),a) - arr.begin();
            int temp = arr[index];
//          cout << "entering temp " <<  temp << " ";
//          cin >> b;
            if ( a == temp && maped[temp]>=0) {
                cout << maped[temp] << " ";  
                flag = true;
            }
            else {
                temp = arr[index-1];
                a -= temp;   
                ll len = abs(maped[arr[index]]);
//              cout << "(" << len << "," << a << "," << index <<  ")";
                a = a%(len);
                if(!a)
                    a = len;
            }
        }
        flag = false;
    }
}
