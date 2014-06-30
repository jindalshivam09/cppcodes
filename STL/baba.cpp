#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
typedef long long ll;
#define MAX 100003
#define MOD 1000000007

vector<ll> arr;
vector<ll> degree;

bool cmp(const ll & a , const ll & b )
{

        return a > b ;
}


ll power(int x,ll pow)
{
    if(pow == 0 )
    return 1;

    ll temp = power(x,pow/2);

    if(pow%2 == 0)
    return (temp*temp)%MOD;

    else
    return (temp*temp*x)%MOD;
}

int main()
{   int n ,x;

    cin>>n>>x;

    arr.resize(n);
    degree.resize(n);

    ll sum =0 ;

    ll ans = 0;
    /////////////////////////////////////////////////////////////////////////////////

//    NOT WORKING
    for(int i = 0;i < n; i++)
    {   cin>>arr[i];
     cout<<arr[i]<<"at"<<i<< endl;
    //sum += arr[i];
    }

    //the code works if the next statement is included in the code
  //cin>>x;
/////////////////////////////////////////////////////////////////////////////////////////
    sort(arr.begin(),arr.begin()+n,cmp);



    for(int i=0;i<n;++i)
    {
        degree[i] = sum - arr[i];
        cout<<degree[i]<<" ";

    }

    ans = degree[0];
    ll newans = ans;
    int count = 0;

    do
    {
        int i = 0 ;
        count = 0 ;

        while( i<degree.size() && degree[i] == degree[0] )
        {
                count++;

        }

        if( count%x == 0  )
        {

            degree.erase(degree.begin(),degree.begin()+count);

            for(int i=0;i<count/x;++i)
                degree.insert(degree.begin(),degree[0]+1);

        }

        else
        break;


    }while( degree[0] <= sum );

    cout<<degree[0];

    return 0;
}
