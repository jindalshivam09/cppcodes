#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

long long cal_r0 (long long d,long long m) {
	
//	r0^2 = -d (mod m)

	long long r;
//	d = 6;
	//if(d>0)	 r = (r-d) % m;
	 r = (-d) % m;
	
	if(-d/m == -1)
		return -1;
		
	long long temp = -1;
	while(temp < m)	{

//		cout << r << endl;
		temp = sqrt(r);
		if(temp*temp == r)
			return temp;
		
		r = r + m;
	}
	
	return -1;
}

pair<long long,long long> cornacchia(long long m,long long d) {
	
//	x^2 + d*y^2 = m;

	long long r = cal_r0(d,m);	
//	cout << r << endl;
	
	if( r == -1)
		return make_pair(-1,-1);
	else {
		
		long long a = m % r;
		while( a*a > m  ) {
			
			m = r;
			r = a;
			a = m % r;
		}
			
		long long s = sqrt( (m - a*a)/d);
		long long left = a*a + d*s*s;
		
		if(left == m)		return make_pair(a,s);
		else				return make_pair(-1,-1); 
	}
}

int main() {
	
	long long t;
	cin >> t;
	
	while(t--) {
		
		long long a;
		cin >> a;
		
		pair<long long,long long> ans = cornacchia(a,1);
		if(ans.first != -1)
		cout << "PERFECT" << endl;
		else 	cout << "IMPERFECT" << endl;
	}
}
