#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#define MAX 100004

using namespace std;
bool isAllow[MAX];
bool isPut[MAX];

int num[MAX];		
main() {
	int n,t;
	cin >> n;
	//int ans[n];
	//int indexAns=0;
	//bool isAllow[MAX];
	memset(isAllow,false,sizeof(isAllow));
	//bool isPut[MAX];
	memset(isPut,false,sizeof(isPut));
	int tot=0;
	for(int i=0;i<n;i++)  {
		cin >>t; 
		
		if(!isAllow[t]) {
			
			num[tot++]=t;
		}
		isAllow[t] = true;
	}
//	int last = *iter;
//	ans[indexAns++] = num[0];
//	iter++;
//	ans[indexAns++] = num[1];
//	iter++;
	sort(num,num+tot);
	
	/*for(int i=0;i<n;i++)
	cout << num[i] << " " ;
	cout << endl;
	*/
	int a,b,c;
	n=tot;
	for(int i=0;i<n;i++) {
		a = num[i];
		if(isAllow[a]) {
			if(!isPut[a]) {
			//	cout << a << " ";
		 		//ans[indexAns++] = a;
		 		isPut[a] = true;
		 	}
			for(int j=i+1;j<n;j++) {
				b = num[j];
				c = (2*b-a); 
				if(isAllow[b]){
					if(isAllow[c])
					tot--;
					isAllow[c] = false;
				}
				
	//-			cout <<a << " " << b << " " << c << endl;
			}
		}
	}
	cout << tot << endl;
	for(int i=0;i<=num[n-1];i++)
	if(isAllow[i])
	cout << i << " ";
}
