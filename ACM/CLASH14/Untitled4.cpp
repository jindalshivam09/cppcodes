#include<bits/stdc++.h>
using namespace std;
	
#define A 1
#define B 2	
typedef long long ll;
ll n, a, b ;
vector<ll>  arr, buffer ;
bool possible ;
map<ll,ll> ans , visited ;

void func() {
	sort(arr.begin(),arr.end()) ;
	for(ll i=0;i<n;i++) {
//		cout << i << endl;
		ll temp = arr[i] ;
		if(visited[temp])
			continue ;
		ll index = lower_bound(arr.begin(),arr.end(),a-temp) - arr.begin() ;
		if(index < n && arr[index] == a-temp && visited[arr[index]] == false) {
			ans[temp] = ans[a-temp] = A ;
			visited[temp] = 1 ;
			visited[a-temp] = 1;
		}
		else {
			index = lower_bound(arr.begin(),arr.end(),b-temp) - arr.begin() ;
			if(index < n && arr[index] == b-temp && visited[arr[index]] == false) {
				ans[temp] = ans[b-temp] = B ;
				visited[temp] = 1 ;
				visited[b-temp] = 1;
			}
			else {
				possible = false ;
				return ;
			}
		}
	}
	possible = true;
}


int main() {
	cin >> n >> a >> b  ;
	arr.resize(n) ;
	buffer.resize(n) ;
	for(ll i=0;i<n;i++)  {
 		cin >> arr[i] ;
		buffer[i] = arr[i] ;
	}
		
		
	func() ;
	
	if(possible) {
		cout << "YES" << endl;
		for(ll i=0;i<n;i++)
			if(ans[buffer[i]] == A)
				cout << 0 << " ";
			else
				cout << 1 << " " ;
	}
	else
		cout << "NO" ;
}
