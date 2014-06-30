#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

#define MAX 150000

bool cmp (const pii &a,const pii &b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second ;
}

int main() {

	int t;
	cin >> t;
//	cin.get();
	while(t--) {
		
		vi pos(26) ;
		vpii freq(26) ;
		char a;

		string str;
		cin >> str;

		vector<char> input(MAX);
		int i=0;
		cin.get();

		while((a=cin.get()) != '\n') {
			input[i++] = a;
			if(a >= 'a' && a <= 'z') {
				
				freq[a-'a'].first = a - 'a';
				freq[a-'a'].second ++;
			}
			else if(a >= 'A' && a <= 'Z') {
				
				freq[a-'A'].first = a - 'A';
				freq[a-'A'].second ++;
			}
		}
		
		sort(all(freq),cmp);
		vi cypher(26);
		for(int j=0;j<26;j++) {
			cypher[freq[j].first] = j;
		}

		for(int j=0;j<i;j++) {
			if(input[j] >= 'a' && input[j] <= 'z') 
				cout << str[cypher[input[j]-'a']]; 
			else if(input[j] >= 'A' && input[j] <= 'Z') {
				char temp = str[cypher[input[j]-'A']] + 'A' - 'a';
				cout << temp; 
			}
			else
				cout << input[j] ;
		}
		cout << endl;
		
	}
}


