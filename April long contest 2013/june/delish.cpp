#include<iostream>
#include<cstdlib>
#include<set>

using namespace std;

long long maxSubArr(long long *arr,long long sum,long long sum2,long long n,int count) {
//	cout << "hi." << sum ;
	if(((arr[0] < 0 || arr[n-1] < 0)) && (count ==1 || count == n-1)){
		return sum2;
	}
	else {
		long long max=0,subArr=0;
		for(int i=0;i<n;i++) {
			subArr+=arr[i];
	//		cout << subArr << " ";
			if(max < sum - 2*subArr)
			max= sum - 2*subArr;
		}
//		cout << max << " " << sum << endl;
		subArr=0;
		for(int i=n-1;i>=0;i--) {
			subArr+=arr[i];
			if(max < sum - 2*subArr)
			max= sum - 2*subArr;
		}
		return max;
	}
}


main() {
	int t;
	set<int> delish;
	cin >> t;
	while(t--) {
		long long n,d;
		long long arr[100000];
		long long first,last,firstNeg,lastNeg;
		int count=0;
		bool flag=false;
		long long min=1000000000,minNeg=-1000000000;
		long long int sum=0,sumIfNeg=0;
		cin >> n;
		for(int i=0;i<n;i++) {
			cin >> d;
			arr[i]=d;
			if(i==0)
			first=d;
			else if(i==n-1)
			last=d;
			sum+=d;
			if(d < 0) {
				if(i==0)
				firstNeg=d;
				else if(i==n-1)
				lastNeg=d;
				count++;
				flag=true;
				sumIfNeg += -1*d;
			}
			else
			sumIfNeg+=d;
		}
//		cout << firstNeg << " " << sumIfNeg << " " << lastNeg << endl;
//		cout << first << " " << last << " " << sum << endl;;
		if(flag && count==n) 
			firstNeg>lastNeg ? cout << abs(sumIfNeg + 2 * firstNeg) : cout << abs(sumIfNeg + 2 * lastNeg);
		else if(flag) {
			cout << maxSubArr(arr,sum,sumIfNeg,n,count);
		}
		else
			first<last ? cout << abs(sum - 2 * first) : cout << abs(sum - 2 * last);		
		cout << endl;	
	}
}
