#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>
using namespace std;
typedef long long ll;
long long cal_min(const vector<int> &arr,int n) {
	
//	cout << i << endl;
		queue<long long> q;
		q.push(arr[0]);
		int p=1;
		long long ans = numeric_limits<int>::max();
		int t=1,w;
		for(int i=0;i<n-1;i++) {
			
			ans  = numeric_limits<int>::max();
			if(!i)	w = 1;
			else 	w = 2;
			for(int j=0;j<w ;j++) {
		
				long long temp = q.front();
				q.pop ();
				
				long long a = temp + arr[p];
				long long b = temp - arr[p];
				long long c = temp * arr[p];
//				cout << temp << " " << a << " " << b << " " << c << endl;
				
				long long t1 = min(a,min(b,c));
				long long t2 = max(a,max(b,c));
				
				cout << t1 << " " << t2 << endl;
				ans = min(ans,min(t1,t2));
				q.push(t1);
				q.push(t2);
			}
			p++;
			t *= 3;
		}
		return ans;
}
int cal_min2(const vector<int> &arr,int n,int i) {
	
//	cout << i << endl;
	if(i==0)
		return arr[i];
	
	else {
		
		int sum = 0;
		int a = cal_min2(arr,n,i-1) + arr[i];
		int b = cal_min2(arr,n,i-1) - arr[i];
		int c = cal_min2(arr,n,i-1) * arr[i];
//		cout << i << " " << a << " " << b  << " " << c << endl;
		return min(a,min(b,c));
	}
}
int main() {
	
	int t;
	cin >> t;
	
	while(t--) {
		
		int n;
		cin >> n;
		vector<int> arr(n);
		
		int neg = 0 , pos = 0;
		
		for(int i=0;i<n;i++ ) {
			cin >> arr[i];
			if(arr[i]>=0) pos++;
			else neg++;
		} 
		if(n==1) cout << arr[0] << endl;
		else if(pos==n)		{
			
				cout << cal_min2(arr,n,n-1) << endl;	
		}
		else
		cout << cal_min(arr,n) << endl;
	}
}
