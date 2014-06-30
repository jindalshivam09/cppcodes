#include<iostream>
//         Real Time Median
#define MAX 100
#define END -32768
using namespace std;
inline void insertSort(int *arr,int i) //use insertion sort as all previous elements r already sorted
{
         int k=i-1,key=arr[i],m=i;
         while((k>=0)&&key<arr[k])
         {
             arr[i]=arr[i-1];
             i--;
             k-- ;
         }
        // cout<<"("<<key<<arr[++k]<<")";
         key^=arr[++k]^=key^=arr[k];
         //cout<<"("<<arr[k]<<")";
         /*while(m>=0)
         cout<<arr[m--];
         cout<<endl;*/
}
using namespace std;
main()
{
        int i=-1,k=-1,arr[MAX];
        float median[MAX];
        while(1)
        {

            cin>>arr[++i];
            if(arr[i]==END)
            break;
            insertSort(arr,i);
          /*  for(int r=0;r<=i;r++)
            cout<<arr[r];
            cout<<endl;*/
            !(i%2)?(median[++k]=arr[i/2]):(median[++k]=((arr[i/2]+arr[i/2+1])/2.0));

        }
        for(int r=0;r<=k;r++)
        cout<<median[r]<<endl;
}
