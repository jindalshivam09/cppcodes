#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merging (vector<int> &arr,int n,int p,int r,int q) {
	
	int l1 = r-p+1;
	int l2 = q-r;
	vector<int> arrl1(l1) , arrl2(l2);
	cout << p << "  " << r << " " << q << endl;
	
	for(int i=p;i<=r;i++) {
	
		arrl1[i-p] = arr[i];
		cout << arrl1[i-p] << " ";
	}
	cout << endl;
		
	for(int i=r+1;i<=q;i++) {
	
		arrl2[i-r-1] = arr[i];
		cout << arrl2[i-r-1] << " ";
	}
	cout << endl;
		
	int i = l1-1 , j = 0 , k = p; 
	while(i >= 0  && j < l2) {
		
		if(arrl1[i] <= arrl2[j] + 1) {
			
			arr[k] = arrl1[i];
			i--;
			k++;
			
		}
		else {
			
			arr[k] = arrl2[j];
			j++;
			k++;
		}
		cout << arr[k-1] <<   " ";
 	} 
	
	while (i>=0) {
		
		arr[k] = arrl1[i];
		i--;
		k++;
		cout << arr[k-1] <<   " ";
	}
	while(j<l2) {
		
		arr[k] = arrl2[j];
		j++;
		k++;
		cout << arr[k-1] <<   " ";
	}
	cout << endl;
	for(int i=p;i<=q;i++)
	cout << arr[i] << " ";
	cout << endl;
}


void naya_sort(vector<int> &arr,int n,int p,int q) {
	
	if(p < q) {

		int r = (p+q)/2;
		naya_sort(arr,n,p,r);
		naya_sort(arr,n,r+1,q);
		merging(arr,n,p,r,q);	
	}
}

int main() {
	
		int t;
		cin >> t;
		while(t--) {
			
			int n;
			cin >> n;
			vector<int> arr(n);
			
			for(int i=0;i<n;i++)
				cin >> arr[i];
				
			naya_sort(arr,n,0,n-1);
			
			for(int i=0;i<n;i++)
				cout << arr[i] << " ";
				
			cout << endl;
		}
}
