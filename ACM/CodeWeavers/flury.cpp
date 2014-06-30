#include<iostream>
#includevector
#includecmath
#includelimits.h
using namespace std;
typedef long long int ll;
vectorint square_array(500);
vector vectorll  ans(1005,vectorll(50,INT_MAX));
void preprocess()
{
for(int i=1;i=35;i++)
square_array[i]=ii;
for(int i=0;i=35;i++)
ans[0][i]=INT_MAX;
ans[0][40]=0;
ll i,j;
for(i=1;i=1000;i++)
{
for(j=1;j=35;j++)
{
if(i=square_array[j])
ans[i][j]=1+ans[i-square_array[j]][40];
else break;
}
for(j=1;j=35;j++)
{
if(ans[i][j]=ans[i][40])
ans[i][40]=ans[i][j];
else if(ans[i][j]==INT_MAX) break;
}
}
}
 
 
int main()
{
ll t,a;
preprocess();
cint;
while(t--)
{
cina;
ll count=0,val;
cout<<ans[a][40]endl;
}
return 0;
} 
