    #include<stdio.h>
    #include<iostream>
    using namespace std;
    #define MOD 1000000007
   // #define GETCHAR getchar//_unlocked

    long long fact[501],ifact[501];
    long long pow(int m,int n)
    {
    if(n==0) return 1;
    long long x=pow(m, n/2);

    if(n%2) return(((x*x)%MOD)*m)%MOD;
    else return (x*x)%MOD;
    }
    void initfact()
    {
    fact[0]=1;
    for(int i=1;i<=500;i++)
    fact[i]=(fact[i-1]*i)%MOD;
    ifact[500]=pow(fact[500],MOD-2);
    for(int i=499;i>=0;i--)
    ifact[i]=(ifact[i+1]*(i+1))%MOD;
    }
    int main()
    {
    initfact();
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int hashmap[200]={0};
    char c;
    int count=0;
    while((c=getchar())!='\n')
    {
    count++;
    hashmap[c]++;
    }
    long long ans=fact[count];
    //cout<<"ans="<<ans;
    for(int i=0;i<200;i++)
    {
    // cout<<"hashmap[i]="<<hashmap[i]<<" ifact="<<ifact[hashmap[i]]<<endl;
    ans=(ans*ifact[hashmap[i]])%MOD;
    }
    cout<<ans<<endl;
    }
    return 0;
    }
