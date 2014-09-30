#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
int n;
vector<int> arr(MAX) ;

int main() {
	int t; 
	cin >> t ;
	while(t--) {
		cin >> n ;
		for(int i=1;i<=n;i++)
			cin >> arr[i] ;
		if(n<=100)  {
			int m ;
			cin >> m;
			while(m--) {
				int type ,l,r;
				cin >> type >> l >> r ;
				int cnt = 1;
				if(type == 1) {
					for(int i=l+1;i<=r;i++) {
						if(arr[i] != arr[i-1])
							cnt ++;
					}
					cout << cnt << endl; ;
 				}
 				else {
				 	vector<int> temp(n+1) ;
				 	for(int i=l;i<=r;i++)
				 		temp[cnt++] = arr[i] ;
				 	for(int i=1;i<l;i++)
				 		temp[cnt++] = arr[i] ;
				 	for(int j=r+1;j<=n;j++)
				 		temp[cnt++] = arr[j] ;
				 	arr = temp ;
				 }
			}
		}
		else {
			vector<int> func(MAX) ;
			int cnt = 0;
			func[1]= 0;
			for(int i=2;i<=n;i++)  {
				if(arr[i] != arr[i-1])
					cnt++ ;
				func[i] =cnt ;
			}
			int  m;
			cin >> m;
			while(m--) {
				int type ,l,r;
				cin >> type>>l>>r ;
				cout << func[r] - func[l] + 1  << endl;
			}
		}
	}
}


