#include<iostream>
#include<map>
using namespace std;

map <long long , long long> memo;

long long cal_money (long long n) {
	
	map<long long , long long>::iterator search = memo.find(n);
	if(search != memo.end())
	return search->second;
	
	if( n <= 4)		return n;
	else {
		
		long long a = cal_money(n/2);
		long long b = cal_money(n/3);
		long long c = cal_money(n/4);
		memo[n/2] = a;
		memo[n/3] = b;
		memo[n/4] = c;
		return max(n,a+b+c);
	}
}

int main() {
	
	int n;
	while(cin >> n) {
				
		cout << cal_money(n) << endl;
	}
}
