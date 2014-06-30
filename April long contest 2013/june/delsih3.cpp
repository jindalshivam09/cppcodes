#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
typedef long long ll;
/*
ofstream out("ans.txt");
ofstream ut("ans2.txt");
ofstream qt("ans3.txt");*/
ll ABS(ll a) {
	if(a<0)
	return -1*a;
	return a;
}
ll lmaxArr(ll *arr,ll *lArr,int n, ll *lmArr,ll *rmArr) {
	lArr[0] = arr[0];
	ll sum=arr[0];
	ll max = 0 , min = 0;
	int count=0;
	if(arr[0]<0)
	count++;
	for(int i=1;i<n;i++) {
		sum+=arr[i];
		lArr[i] = sum;
		if(lArr[max] < sum )
		max = i;
		if(lArr[min] > sum)
		min = i;
		if(arr[i] < 0)
		count++;
	}
	int m=min;
	for(int i=min+1;i<n;i++) {
		if(lArr[m] < lArr[i]) {
			m = i;
			//sum = lArr[i];
		}
	}
	cout << count << " " << n << endl;
	cout << max << " " << min << " " << m << endl;
	cout << lArr[max] << " " << lArr[min] << " " << lmArr[min] << endl;
	cout << abs(lArr[max] - lArr[min] - lmArr[min]) << endl;

	ll MAX = -1000000000;
	if(count==n) {
		if(arr[0] > arr[n-1])
		MAX= ABS(sum - 2*arr[0]);
		else
		MAX = ABS(sum - 2*arr[n-1]);	
	} 
	else if(max > min) { 
		MAX =  ABS(lArr[max] - lArr[min] - lmArr[min]) ;
		if(max < n-1 ) {
			if(MAX < ABS(lArr[max] - lArr[min] - rmArr[max+1]))
			MAX = ABS(lArr[max] - lArr[min] - rmArr[max+1]);
		}
	}
	else if(max < min && m!=min){ 
		MAX =  ABS(lArr[m] - lArr[min] - lmArr[min]) ;
		if(m < n-1 ) {
			if(MAX < ABS(lArr[m] - lArr[min] - rmArr[m+1]))
			MAX = ABS(lArr[m] - lArr[min] - rmArr[m+1]);
		}
	}
	else if(max < min && m==min) {
		if(MAX <  ABS(lArr[min] - lArr[max] - arr[max]))
		MAX  =  ABS(lArr[min] - lArr[max] - arr[max]);
		
	}
	else if(max < n-1) {
		ll temp =  ABS(lArr[max]  - rmArr[max+1]) ;
		if(temp > MAX)
		MAX = temp;
	}
	cout << endl << MAX << endl;
	return MAX;
}


int lminArr(ll *arr,ll *lArr,int n) {
	int min = 0;
	lArr[0] = arr[0];
	ll sum=arr[0];
	for(int i=1;i<n;i++) {
		//sum+=arr[i];
		if(sum>sum + arr[i]) {
			lArr[i] = arr[i];
			if(sum <0)
			lArr[i]+=sum;
		//	sum=lArr[i];
		//	sum = arr[i];
		}
		else if(sum<arr[i]){
			lArr[i] = sum ;
			//sum+=arr[i];
		}
		else{
			lArr[i] = arr[i];
		}
		sum = lArr[i];
		//ut << sum << endl;
		if(lArr[min] > lArr[i])
		min = i;
		//cout << lArr[i] << " ";
	}
	return min;
}


int rminArr(ll *arr,ll *rArr,int n) {
	int min = n-1;
	rArr[n-1] = arr[n-1];
	ll sum=arr[n-1];
	for(int i=n-2;i>=0;i--) {
		if(sum>sum + arr[i]) {
			rArr[i] = arr[i];
			if(sum <0)
			rArr[i]+=sum;
		//	sum=rArr[i];
		//	sum = arr[i];
		}
		else if(sum<arr[i]){
			rArr[i] = sum ;
			//sum+=arr[i];
		}
		else 
		rArr[i] = arr[i];
		sum = rArr[i];
		if(rArr[min] > rArr[i])
		min = i;		
	}
	return min;
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
		int n;
ifstream in("test.txt");		
		cin >> n;
		ll arr[10000];
		ll lArr[10000];
		ll lmArr[10000],rmArr[10000];
		for(int i=0;i<n;i++) 
		in >> arr[i] ;
		
		
		int lmin = lminArr(arr,lmArr,n);
		int rmin = rminArr(arr,rmArr,n);
		ll MAX = lmaxArr(arr,lArr,n,lmArr,rmArr);
		
		for(int i=0;i<n;i++)
		cout << lArr[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << lmArr[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << rmArr[i] << " ";
		cout << endl;
		cout << lmin << " " << rmin << endl;

		ll sum=0;
		for(int i=0;i<n-1;i++) {
			if(lmArr[lmin]==lmArr[i]) {
				sum = ABS(lArr[n-1] - lArr[i] - lmArr[i]);
//				out << sum << " ";
				if(sum > MAX)
				 MAX = sum;
			}
		}
		
		
		for(int i=1;i<n;i++) {
			if(rmArr[rmin]==rmArr[i]) {
				sum = ABS(lArr[i-1] -  rmArr[i]);
				if(sum > MAX)
				MAX = sum;
			}
		}
		cout << MAX << endl;
	
	}
}
