#include<bits/stdc++.h>
using namespace std;

int d ;
vector<int> arr ;

struct number {
	int val, diff, sz ;
	number(int val = 0, int diff = 0,int sz = 0) {
		this->val = val, this->diff = diff, this->sz = sz;
	}
	bool operator () (const struct number &a, const struct number &b) {
		if(a.val == b.val) 
			return a.sz == b.sz ? a.diff < b.diff : a.sz < b.sz ;
		return a.val < b.val ;
	}
	bool operator < (const struct number &b) const{
		if(this->val == b.val) 
			return this->sz == b.sz ? this->diff < b.diff : this->sz < b.sz ;
		return this->val < b.val ;
	}
};

int modifiedLIS() {
	set<number> len ;
	set<number>::iterator itr ;
	int till = 1 ;
	struct number temp ;
	temp.val = arr[0] , temp.diff = INT_MIN, temp.sz = till;
	len.insert(temp) ;
	for(int i=1;i<arr.size();i++) {
		int tempVal = arr[i] ;
		itr = lower_bound(len.begin(),len.end(),number(tempVal)) ;
		if(itr == len.end()) {
			itr -- ;
			int diff = tempVal-itr->val ;
			if(diff <= d) {
				till ++ ;
				temp.sz = till, temp.val = tempVal, temp.diff = diff ;			
				len.insert(temp) ;
			}
		}
		else {
			int val = itr->val ;
			int diff = itr->diff ;
			int sz = itr->sz ;
				len.erase(itr) ;
				temp.val = tempVal, temp.diff = diff-val+tempVal , temp.sz = sz ;
				len.insert(temp) ;
		}
	}
	int ans = INT_MIN ;
	for(itr = len.begin() ; itr != len.end() ; itr ++) {
		cout << itr->val << " " ;
		ans = max(ans, itr->sz) ;
	}
	cout << endl;
	return ans ;
}

int main() {
	int n ;
	cin >> n >> d ;
	arr.resize(n) ;
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	cout << modifiedLIS() << endl;
}
