#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#define MAX 100005
using namespace std;

main() {
	int t;
	cin >> t;
	int arr[MAX];
	int ans[MAX];
	bool put[MAX];
	memset(ans,false,sizeof(ans));
	
	for(int i=0;i<t ;i++)
	cin >> arr[i];
	
	sort(arr,arr+t);
	
	put[arr[0]]=true;
	put[arr[1]]=true;
	
	ans[0] = arr[0];
	ans[1] = arr[1];
	
	int tot=2;
	int c;
	bool flag;
	for(int i=2;i<t;i+=2) {
		c = arr[i];
		flag = false;
		for(int j=tot;j>=0;j--) {
			if(put[(c+ans[j])/2]&&!((c+ans[j])%2)) {
				flag = true;
				break;
			} 
		}
 		if(!flag) {
		 	put[c] = true;
		 	ans[tot++] = c;
		 }
	}
	
	for(int i=3;i<t;i+=2) {
		c = arr[i];
		flag = false;
		for(int j=tot;j>=0;j--) {
			if(put[(c+ans[j])/2]&&!((c+ans[j])%2)) {
				flag = true;
				break;
			} 
		}
 		if(!flag) {
		 	put[c] = true;
		 	ans[tot++] = c;
		 }
	}
	cout << tot << endl;
	for(int i=0;i<tot;i++)
	cout << ans[i] << " ";
}
