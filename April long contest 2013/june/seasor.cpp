#include<iostream>
#include<algorithm>
#define MAX 1000000
using namespace std;
int tot;
int ans[MAX];
int stack[MAX][2];
int top;
int pre[MAX];
int w;
int partition(int *arr,int p,int q,int k) {
	int key = arr[p];
	int last=p,i;
	//cout << key << " " << p << " " << q << " ";
	w=0;
	for(i=p+1;i<=q;i++) {
		if(key > arr[i]) {
			last = i;
			pre[w++] = i;
	}
	
	return last;
}

void qs(int *arr , int p ,int q,int k,int n) {
		
	stack[++top][0] = p;
	stack[top][1] = q;
			
	while(top >= 0)	{	
		int i = stack[top][0];
		int j = stack[top--][1];
		if(i<=n && j<=n) {
			int r = partition(arr,i,j,k);
	//		cout << r << endl;	
			if(i<j) {
				stack[++top][0] = r+1;
				stack[top][1] = j;
				stack[++top][0] = i;
				stack[top][1] = r-1;
			}
			for(int q=i;q<r && q<n;q += k-1) {
				ans[tot++] = q;
		//		cout << q << " " << tot << " " << ans[tot-2] << " " << ans[tot-1] << endl;
				if(tot>1 && ans[tot-2]+k>n && q+k>n)
				tot--;
				if(q+k<=n+1)
				sort(arr+q,arr+q+k);
				else sort(arr+q,arr+n+1);
			}	
			for(int q=r+k;q<j && q<n;q += k-1) {
				ans[tot++] = q;
		//		cout << q << " " << tot << " " << ans[tot-2] << " " << ans[tot-1]<< endl;
				if(tot>1 && ans[tot-2]+k>n && q+k>n)
				tot--;
				if(q+k<=n+1)
				sort(arr+q,arr+q+k);
				else sort(arr+q,arr+n+1);
			}
			
	//		for(int q=1;q<=n;q++)
	//		cout << arr[q] << " ";
	//		cout << endl;
		}
	}
}

main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		int arr[n];
		for(int i=1;i<=n;i++)
		cin >> arr[i];
		tot = 0;
		top=-1;
		qs(arr,1,n,k,n);
		cout << tot << endl;
		for(int i=0;i<tot ;i++)
		cout << ans[i] << " ";
		cout << endl;
	}
}
