#include<algorithm>
#include<iostream>
#include<vector>
#include<set>

#define MAX 100000

using namespace std;
typedef long long ll;
void print(ll n) {
	cout << n << " ";
}

bool challenge(ll d,vector<ll> diff,vector<ll> totDiff) {
	
	bool flag = false;
	vector<ll>::reverse_iterator pD = diff.rbegin() , tD = totDiff.rbegin();
	//vector<int>::iterator tD = t.base();
	tD ++;
	
	for( ; pD != diff.rend() && tD != totDiff.rend() ;pD ++) {
//			cout << d << " " << *pD <<" " << *tD << endl;
			if( d+*pD > *tD && d!=*pD) 
			flag=true;
			else if(d+*pD == *(pD+1))
			flag=false;
			d+=*pD ;
			tD ++;
	}
	if(flag)  return true ; return false ;
}

main() {
	
	int n;
	ll t;
	set<ll> num;
	vector<ll> ans,diff,totDiff;
	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> t;
		num.insert(t);
	}


	set<ll>::iterator i = num.begin();
	
	ll d=0 ,totD =0 , q;
	ll last=*i;
	ans.push_back(*i);
	diff.push_back(*i);   	
	totDiff.push_back(*i);
	i++;
	int count =1;
	for( ; i!=num.end() ; i++) {
	
		q = *i - last;	
		if(  q > totD ) {
	 		last = *i;
	 		totD += q;
	   		ans.push_back(*i);	
			diff.push_back(q);   	
			totDiff.push_back( totD );
			count++;
		}
		else if( q < d ) {
	//		cout << *i << "  ";
			bool is = challenge(q,diff,totDiff);
			if (is) {
				last = *i;
		 		totD += q;
		   		ans.push_back(*i);	
				diff.push_back(q);		
				totDiff.push_back( totD );
				count++;
			}
	 }
		
			d = q;		
	}
	cout << count << endl;
	for_each(ans.begin(),ans.end(),print);

}
