#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;

#define MAX 100009

vector<int> temp(MAX),till_max(MAX);

void merge(vector<int> &arr,int n,int p,int q,int r) {
	
	int i = q , j = r;
	
	till_max[q+1] = -1;
	
	for(int k=q+2;k<=r;k++) {
		
		till_max[k] = max(arr[k-1],till_max[k-1]);
//		cout << till_max[k] << " ";
	}
	int size = 0;
	
	while(i>=p && j > q) {
		
		if(arr[i] <= arr[j] + 1){
			
			temp[size++] = arr[j--];
		}
		else {
			
			if(till_max[j] + 1 >= arr[i]) {
				
				temp[size++] = arr[j--];
			}
			else {
				
				temp[size++] = arr[i--];
			}
		}
	}
	
	while(i>=p) {
		
		temp[size++] = arr[i--];
	}
	
	while(j > q) {
		
		temp[size++] = arr[j--];
	}
	
	for(int i=0;i<size;i++) {
		
		arr[r-i] = temp[i];
	}
} 

void modified_merge_sort(vector<int> &arr,int n,int p,int r) {
	
	if(p == r)		return;
	if(r-p == 1) {
		
		if(arr[p] > arr[r] + 1) {
			
			swap(arr[p],arr[r]);
		}
		return;
	}
	int q = (p+r)/2;
	modified_merge_sort(arr,n,p,q);
	modified_merge_sort(arr,n,q+1,r);
	merge(arr,n,p,q,r);
}

int main() {
	
	int t;
	scanf("%d",&t);
	while(t--) {
		
		int n;
		scanf("%d",&n);
		vector<int> arr(n);
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
			
		modified_merge_sort(arr,n,0,n-1);
		
		for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
		
		printf("\n");
	}
}
