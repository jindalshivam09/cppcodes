#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
typedef long long ll;

void lmaxArr(ll *arr,ll *lArr,int n) {
	lArr[0] = arr[0];
	ll sum=arr[0];
	ll max = 0 , min = 0;
	for(int i=1;i<n;i++) {
		sum+=arr[i];
		lArr[i] = sum;
		if(lArr[max] < sum )
		max = i;
		if(lArr[min] > sum)
		min = i;
	}
	cout << max << " " << min << endl;
	cout << abs(lArr[max] - lArr[min] - arr[min]) << endl;
}

void lminArr(ll *arr,ll *lArr,int n) {
	lArr[0] = arr[0];
	ll sum=arr[0];
	for(int i=1;i<n;i++) {
		sum+=arr[i];
		if(sum>arr[i]) {
			lArr[i] = arr[i];
			sum = 0;
		}
		else
		lArr[i] = sum;		
	}
}


void rminArr(ll *arr,ll *rArr,int n) {
	rArr[n-1] = arr[n-1];
	ll sum=arr[n-1];
	for(int i=n-2;i>=0;i--) {
		sum+=arr[i];
		if(sum>arr[i]) {
			rArr[i] = arr[i];
			sum = 0;
		}
		else
		rArr[i] = sum;		
	}
}

ll cal(ll *arr,ll *lArr,int i,int j) {
	if(i==j)
	return arr[i];
	else if(!i)
	return lArr[j];
	return lArr[j]-lArr[i-1];

}

main() {
	int t;
	cin >> t;
	while(t--) {	
		ifstream in("test.txt");

		int n;
		cin >> n;
		ll arr[n];
		ll lArr[n];
		ll lmArr[n],rmArr[n];
		for(int i=0;i<n;i++)
		in >> arr[i];
		lmaxArr(arr,lArr,n);
		lminArr(arr,lmArr,n);
		rminArr(arr,rmArr,n);
		
	/*	for(int i=0;i<n;i++)
		cout << lArr[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << lmArr[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << rmArr[i] << " ";
		cout << endl;
		*/
		ll sum1=0;
		ll MAX=0;
		ll temp;
		ll midMax,lMin,rMin;
		for(int i=0;i<n;i++) {
			for(int j=i;j<n;j++) {
				midMax=cal(arr,lArr,i,j);
		//		if(i>0)
				lMin=lmArr[i-1];
				rMin=rmArr[j+1];
	//			cout << midMax <<" " << lMin << " " << rMin << endl;
				if(i>0&&j<n-1)
				temp = abs(midMax-min(lMin,rMin));
				else if(i==0&&j<n-1)
				temp = abs(midMax-rMin);
				else if(i>0&&j==n-1)
				temp = abs(midMax-lMin);
				else
				temp = -1000000000;
			
				if(MAX < temp) {
					cout << i << " " << j << " " << midMax << " " << lMin << " " << rMin << endl;
				MAX = temp;
			}
			}
		}
		cout << MAX << endl;
	}
}
