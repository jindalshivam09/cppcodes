#include<iostream>
#include<map>
using namespace std;
int arr[100];
map<int,int> countt;
int main()
{
	for(int i=1;i<=97;i++)
	  arr[i] = i*i*i;
	int t;
	cin>>t;
	for(int i=0;i<=97;i++)
	 for(int j=i;j<=97;j++)
	  countt[arr[i]+arr[j]]++;
	while(t--){		
		int n;
		int maxx=0;
		cin>>n;
	 for(map<int,int>::iterator i  = countt.begin();i!= countt.end();i++)
	    if(i->second>=2 && i->first<n && i->first > maxx)
		  maxx = i->first; 
		  if(maxx) 
		cout<<maxx<<endl;
	     else
		  cout<<-1<<endl;		
	}
}
