//              Author: Shivam Jindal
 //[-----brute force to electricity cutoff problm[--------
 // need to find the gap for which a house numbr here 13 is safe if we start eliminating houses at particular gap in circular order
 

#include<iostream>
#include<conio.h>
#include<cstring>
#define MAX 200
#define SAVE 13-1
using namespace std;
main()
{
/*	int t;
	cin>>t;
	while(t--)
	{
		//int num;
		//cin>>num;
*/
int num,gap,arr[MAX],i,j,count;
for(int q=13;q<101;q++){
	 num=q;
	 gap=1;
	 arr[num];
	 memset(arr,0,sizeof(arr));
	 i=0;
	 j=1;
	 count=0;
	 arr[0]=1;

	 while(gap<(100000*num+1)){

		while(count!=num-1)
		{
			if(i==gap-1&&!arr[j]){
					arr[j]=1;
					i=0;
					count++;
				//	cout<<j<<" ";
		    }
			if(!arr[j]){
			    i++;
			}
			j++;
			j%=num;
			//if(arr[12])
			//break;
		//  cout<<i<<" "<<j<</*" "<<arr[j]<<*/endl;
		}
		j--;
		//	cout<<"hi";
		if(j==SAVE){
		     cout<<"q="<<q<<" gap="<<gap<<endl;
		     break;
			}
		gap++;
		memset(arr,0,sizeof(arr));
		i=0,j=1;
	    count=0;
		arr[0]=1;
   }

}
getch();
}

