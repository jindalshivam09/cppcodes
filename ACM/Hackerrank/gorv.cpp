#include<iostream>
using namespace std;
long long string_mod(char* a,long long MOD)
{
    long long result=0;
    while((*a)!='\0')
    {
        result=result*10;
        result+=(*a-'0');
        result%=MOD;
        a++;
    }
    return result;
}
long long int mypower(long long int n,long long int m,long long int MOD)
{
if(m==0) return 1%MOD;
long long int x=mypower(n,m/2,MOD);
if(m%2==0)
return (x*x)%MOD;
else
return (((x*x)%MOD)*n)%MOD;
}
int main()
{
    int t;
    cin>>t;
    while(t--){    
    char a[100000];
    char b[100000];
    cin>>a>>b;
    long long n1,n2;
    int MOD=1000000007;
    n1=string_mod(a,MOD);
    cout << n1 << endl;
    n2=string_mod(b,MOD-1);
    cout << n2 << endl;
    cout<<mypower(n1,n2,MOD)<<"\n";
}
}
