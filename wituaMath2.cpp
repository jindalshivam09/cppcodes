#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
int arr[2000];
using namespace std;
#define ull unsigned long long
void prime()
{
int test , i, k, j, flag;
arr[0] = 2;
k = 1;
for(i = 3; i<10000; i = i+2)
{
flag = 0;
for(j=0; j<k; j++)
{
if(i%arr[j]==0)
{
flag++;
break;
}
}
if(flag==0)
{
arr[k] = i;
k++;
}
}
}
 
ull mulmod(ull a, ull b, ull c)
{
ull x = 0, y = a%c;
while(b>0)
{
if(b&1) x = (x+y)%c;
y = (y<<1)%c;
b = b>>1;
}
return x;
}
 
ull modulo(ull a, ull b, ull c)
{
ull x = 1, y = a%c;
while(b>0)
{
if(b&1) x = mulmod(x,y,c);
y = mulmod(y,y,c);
b = b>>1;
}
return x;
}
 
bool miller(ull p, int iter)
{
if(p<2) return false;
if(p==2) return true;
if(!(p&1)) return false;
ull s = p-1, a, temp, mod;
while(!(s&1)) s = s>>1;
for(int i=0; i<iter; i++)
{
a = rand()%(p-1)+1;
temp = s;
mod = modulo(a, temp, p);
while(temp!=p-1 && mod!=1 && mod!=p-1)
{
mod = mulmod(mod, mod, p);
temp = temp<<1;
}
if(mod!=p-1 && !(temp&1)) return false;
}
return true;
}
int main()
{
prime();
long long int test, num, flag, flag1;
cin>>test;
for(int i = 0; i< test; i++)
{
cin>>num;
if((num>3)&&(num%2==0))
{
num = num-1;
}
flag1=0;
while(flag1<=0)
{
flag =0;
for(long long int a = 0 ; a <1000; a++)
{
if(num>arr[a]*arr[a])
{
if(num%arr[a]==0)
{flag++;
break;}
}
}
if(flag==0)
{
if(miller(num, 1)==true)
{printf("%lld\n", num);
flag1=1;
}
else
num = num-2;
}
else
num = num-2;
}
}
} 
