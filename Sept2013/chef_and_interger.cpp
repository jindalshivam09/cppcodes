#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long cal_cost (const vector<long long> &neg , long long x) {

	long long cost=0,ans,c;
	int n = neg.size();
	long long pre = 0;

	for (int i = 0 ; i < n ; i ++)
	cost += neg[i];
	
//	cout << cost;
	ans = min (cost , x*neg[n-1]);
//	cout << ans;
	
	for (int i = 0 ; i < n ; i ++) {
		
		c = neg[i]*x + cost - pre - neg[i]*(n-i);
		pre += neg[i];
		ans = min(c,ans);
	}
	
	return ans;
	
}

int main() {

	int n;
	cin >> n;
	vector<long long >  neg;
	int count = 0;
	long long a;
	
	for (int i = 0 ; i < n ; i ++) {
		
		cin >> a;
		if (a < 0)	{
			neg.push_back(-1LL*a);
//			cout << neg[count];
			count++;
		}
	}
	
	long long x;
	cin >> x;
	
	if(count) {
		sort (neg.begin() , neg.end() );
//		cout << neg[0];	
		cout << cal_cost (neg , x) << endl;
	}
	else cout << 0 << endl;
}
