#include<iostream>
#include<cstring>
#define MAX 26
using namespace std;
bool match(int *parent,int *children){
	for(int i=0;i<MAX;i++){
		if(parent[i]>=children[i])
		continue;
		//cout<<parent[i]<<" ";
		else{
		//		cout<<parent[i]<<" "<<children[i]<<" ";			
				return false;
		}
	}
	return true;
}
main(){
	int parent[MAX],children[MAX];
	int t,n;
	char ch;
	cin>>t;
	cin.get();
	
	while(t--){
		memset(parent,0,sizeof(parent));
		memset(children,0,sizeof(children));
		ch=cin.get();
		do{
		//	cout<<ch<<" g ";
			parent[ch-97]++;
		}while((ch=cin.get())!='\n');
		
	/*0	ch=cin.get();
		do{
			cout<<ch<<" g ";
			parent[ch-97]++;
		}while((ch=cin.get())!='\n');
	*/	
		cin>>n;
		//cout<<n;
		cin.get();

		while(n--){
			ch=cin.get();
			do{
		//		cout<<ch<<" g ";
				children[ch-97]++;
			}while((ch=cin.get())!='\n');
		}
		if(match(parent,children))
		cout<<"YES";
		else
		cout<<"NO";
		cout<<endl;
	}
}
