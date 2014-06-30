#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
bool match(string str1,string str2){
	int len2=strlen(str2.c_str()),len1=strlen(str1.c_str());
	int k=0,count=0;
	//cout<<str1<<" "<<str2<<" ";
	//cout<<len1<<" "<<len2<<" ";
	bool flagNoMatch=1;
	for(int i=0;i<len1;i++){
		for(int j=k;j<len2;j++){
			if(str1[i]==str2[j]){
	//			cout<<str1[i]<<" "<<str2[j]<<" ";
	//			count++;
				k=j+1;
				flagNoMatch=0;
				break;
			}
		}
		if(flagNoMatch)
		return false;
		flagNoMatch=1;

	}
	return true;
}
main(){
	string str1,str2;
	int t;
	cin>>t;
	while(t--){
		cin>>str1>>str2;
		if(!match(str1,str2)){
			if(!match(str2,str1))
				cout<<"NO";
			else
			    cout<<"YES";
		}
		else{
			cout<<"YES";
		}
		cout<<endl;
	}
}
