#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

void print(int n) {
	cout << n << " ";
}

main() {
	set <int> s;
	vector<int> v;
	int t,n;
	cin >> t;
	for(int i=0;i<t;i++) {
		cin >> n;
		s.insert(n);
		
	}
	set<int>::iterator i = s.begin();
	int d=0 ,totD=0 , q;
	int last=*i;
	v.push_back(*i);
	//cout << *i << " ";
	i++;
	int count =1;
	for( ; i!=s.end() ; i++) {
		q = *i - last;
		//last = *i;
	//	cout << q << " d= " << d << " tot= " << totD << endl;
		if(  q > totD ) {
			
			//cout << *i << " ";
	 		last = *i;
	   		v.push_back(*i);		
			totD += q;
			count++;
		}
			d = q;		
	}
	cout << count << endl;
	for_each(v.begin(),v.end(),print);
}
