#include<iostream>
#include<map>
#include<vector>
#include<map>
#include<limits>
#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;

inline long long readInt(){
long long number = 0;
char c = getchar_unlocked();
while(c<'0')
c = getchar_unlocked();
while(c>='0' && c<='9'){
number = (number<<3)+(number<<1)+c-'0';
c = getchar_unlocked();
}
return number;
} 


map <long long,long long> ans;

long long dp (map<long long , vector<long long> > &input,int n,long long first,long long last) {
	
	if(ans[first])
			return ans[first];
	if(input[first].empty())
		return 0;	
	if(first >= last)
		return 0;
	
	long long temp = numeric_limits<long long>::min();	
	for(int i =0;i<input[first].size();i++) {

		bool flag = true;
		for(map<long long,vector<long long> >::reverse_iterator j = input.rbegin();j != input.rend()  ; j ++) {
			
//			cout << j->first  ;
			if(j->first > input[first][i]) {
				
				flag = false;
//				cout << j->first << " " << first <<  "  " << input[first][i] << endl ;
				temp = max(temp,input[first][i] - first + 1 + dp(input,n,j->first,last));
			}
			else {
	
				temp = max(temp,input[first][i] - first + 1);
				break;
			}
		}
		//return temp;
	}
//	cout << temp << endl;
	return ans[first] = temp;
}

int main() {
	
	long  long t;
			t = readInt();
	while(t--) {
		
		long long n;
			n = readInt();
		
		map <long long,vector<long long> >  input;
		set<long long> start;
		long long temp , temp2 , first = numeric_limits<long long>::max(), last = numeric_limits<long long>::min();
		for(int i=0;i<n;i++) {
			
			temp = readInt();
			temp2 = readInt();
			start.insert(temp);
			input[temp].push_back(temp2);
			first = min(first,temp);
			last = max(last,temp2);
		}
		
		long long ans = numeric_limits<long long>::min();		
		for(set<long long>::iterator i = start.begin(); i != start.end() ; i++) {

//			cout << (*i) << " ";
			ans = max(ans,dp(input,n,*i,last));
//			cout << ans << endl; 
		}
		
		cout << ans << endl;
	}
}
