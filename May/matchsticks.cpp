#include<iostream>
#define MAX 100009
using namespace std;
main() {
	int n,queries;
	int l,r;
	int time[MAX];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>time[i];
	cin>>queries;
	int min,max,max2;
	while(queries--) {
		cin >> l >> r ;
		min=max=time[l];
		max2=0;
		for(int i=l;i<=r;i++) {
			if(min>time[i])
			min=time[i];
			if(max<time[i])
			max=time[i];
		}
		
		for(int i=0;i<l;i++)
		if(max2<time[i])
		max2=time[i];
		for(int i=r+1;i<n;i++)
		if(max2<time[i])
		max2=time[i];
		
		if(max2 > (max-min)/2.0)
		cout<<(max2+min)<<".0";
		else{
		   cout<<min + (max-min)/2.0;
		   if(!((max-min)%2))
		   cout<<".0";
		}
		
	}
	
}
