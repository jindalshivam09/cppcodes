#include<iostream>
#define MAX 100
using namespace std;
inline void  sub(int *arr,int *arrsub,int n)
{
         for(int i=1;i<n;i++)
         {

             arrsub[i]=arr[i]-arr[i-1];
             //cout<<"g"<<arr[i];
             if(arrsub[i-1]<0&&arrsub[i]>0)  //no. is zero point if 2 consecutive diff is of opposite sign i.e - n +
             cout<<i<<endl;
         }

}
main()
{
     int n,arr[MAX],arrsub[MAX];
     cin>>n;
     for(int i=0;i<n;i++)
     cin>>arr[i];
     arrsub[0]=arr[0];
     sub(arr,arrsub,n);     //to take diff of elements
     /*for(int i=1;i<n;i++)
     {
           if(arr[i-1]<0&&arr[i]>0)
           cout<<(i);
     }*/

}
