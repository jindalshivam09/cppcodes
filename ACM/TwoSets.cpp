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
	ans.clear();
    for(ll i=0;i<n;i++) {
//      cout << i << endl;
        ll temp = arr[i] ;
        if(visited[temp])
            continue ;
 //       cout << temp << " " ;
        ll index = lower_bound(arr.begin(),arr.end(),a-temp) - arr.begin() ;
        if(index < n && arr[index] == a-temp && visited[arr[index]] == false) {
   //     	cout << "i";
            ans[temp] = ans[a-temp] = A ;
            visited[temp] = 1 ;
            visited[a-temp] = 1;
        }
        else {
     //   	cout << "(" <<  temp << " " << b-temp << ")" <<endl;
            index = lower_bound(arr.begin(),arr.end(),b-temp) - arr.begin() ;
            if(index < n && arr[index] == b-temp && visited[arr[index]] == false) {
                ans[temp] = ans[b-temp] = B ;
                visited[temp] = 1 ;
                visited[b-temp] = 1;
            }
            else {
			    visited.clear() ;
  //          	cout << "failed\n" ;
                possible = false ;
                return ;
            }
        }
    }
//    cout << endl;
    visited.clear() ;
    possible = true;
    return ;
}


int main() {
    cin >> n >> a >> b  ;
    arr.resize(n) ;
    buffer.resize(n) ;
    for(ll i=0;i<n;i++)  {
        cin >> arr[i] ;
        buffer[i] = arr[i] ;
    }
     
	sort(arr.begin(),arr.end()) ;
    
	int index= lower_bound(arr.begin(),arr.end(),a/2) - arr.begin() ;
	if(index<n && arr[index] == a/2 && a%2 == 0)  {
//		cout << "if 1" << endl;
		func() ;
		if(possible == false) {
//			cout << "if 2" << endl;
			visited[a/2] = true;
			func() ;
		}
	}
	else
		func() ;
	
	if(possible == false) {
		index= lower_bound(arr.begin(),arr.end(),b/2) - arr.begin() ;
		if(index<n && arr[index] == b/2 && b%2 == 0)  {
//			cout << "if 3" << endl;
			func() ;
			if(possible == false) {
//				cout << "if 4" << endl;
				visited[b/2] = true ;
				func() ;
			}
		}
		else
			func() ;
	}
	            
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
