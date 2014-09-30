#include<bits/stdc++.h>
using namespace std;

int main() {
	int n ;
	cin >> n ;
	vector<pair<int,int> > arr(n) ;
	map<int,int> freq ;
	bool possible = false;
	int cnt = 0 ;
	for(int i=0;i<n;i++) {
		cin >> arr[i].first ;
		freq[arr[i].first] ++ ;
		if(freq[arr[i].first] >= 3)
			possible = true;
		if(freq[arr[i].first] == 2)
			cnt ++ ;
		if(cnt >= 2)
			possible = true ;
		arr[i].second = i+1;
	}
	sort(arr.begin(),arr.end()) ;
	if(possible == false)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		vector<int> one,two,three ;
		bool done = false;
		cnt = 0;
		for(int i=0;i<n;) {
			int temp = arr[i].first ;
			int val = arr[i].second ;
			if(freq[temp] == 1 || done) {
				one.push_back(val) ;
				two.push_back(val) ;
				three.push_back(val) ;
				i ++ ;
			} 
			else if(freq[temp] == 2) {
				cnt ++ ;
				int val2 = arr[i+1].second ;
				if(cnt >= 2)	done = true ;
				if(cnt == 1) {
					one.push_back(val);
					one.push_back(val2);
					two.push_back(val);
					two.push_back(val2);
					three.push_back(val2);
					three.push_back(val);
				}
				else {
					one.push_back(val);
					one.push_back(val2);
					two.push_back(val2);
					two.push_back(val);
					three.push_back(val2);
					three.push_back(val);
				}
				i += 2 ;
			}
			else {
				done = true ;
				int val2 = arr[i+1].second ;
				int val3 = arr[i+2].second ;
					one.push_back(val);
					one.push_back(val2);
					two.push_back(val2);
					two.push_back(val);
					three.push_back(val3);
					three.push_back(val);
					one.push_back(val3) ;
					two.push_back(val3) ;
					three.push_back(val2) ;
				i += 3 ;				
			}
		}
			for(int i=0;i<n;i++)
				cout << one[i] << " ";
			cout << endl;
			for(int i=0;i<n;i++)
				cout << two[i] << " ";
			cout << endl;
			for(int i=0;i<n;i++)
				cout << three[i] << " ";
			cout << endl;
	}
}
