#include <bits/stdc++.h>
using namespace std;



#define MAXC 100
#define MAXR 100009
string str ;
struct node {
	int first , second , id ;
} suffixes[MAXR] ;

vector<vector<int> > pos(MAXC,vector<int> (MAXR));
int steps=1;

bool cmp (const struct node &a,const struct node &b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int  suffix_array () {		
	for(int i=0;i<str.size();i++)
	//rep(i,str.size()) 
		pos[0][i] = str[i]-'a';
	for(int cnt = 1 ; cnt >> 1 < str.size() ; steps++ , cnt <<= 1) {
		for(int i=0;i<str.size();i++) {
			suffixes[i].first = pos[steps-1][i];
			suffixes[i].second = i+cnt < str.size() ? pos[steps-1][i+cnt] : -1 ;
			suffixes[i].id = i ;
		}
		sort(suffixes,suffixes+str.size(),cmp);
		for(int i=0;i<str.size();i++) {
			pos[steps][suffixes[i].id] = i > 0 && suffixes[i-1].first == suffixes[i].first && 
										 suffixes[i-1].second == suffixes[i].second ? pos[steps][suffixes[i-1].id] : i ;
		}
	}
	int index = -1;
	int temp = -1 ;
	for(int i=0;i<str.size();i++) {
		if (temp < pos[steps-1][i] ) {
			temp = pos[steps-1][i] ;
			index = i ;
		}
	}
	return index; 
}

string ans; 
int main() {
	int n;
	cin >> n;
	cin >> str ;
	int index = suffix_array() ;
	ans = str.substr(index);
	vector<int> freq(26) ;
		for(int i=0;i<ans.size();i++)
	freq[ans[i]-'a'] ++ ;
	vector<bool> printed(ans.size());
	for(int i=0;i<ans.size();i++)
  {	int temp = ans[i]-'a';
		if(printed[temp]) {
			freq[temp] -- ;
			continue;
		}
		bool flag = false ;
			for(int j=temp+1;j<26;j++) {
			if (freq[j]>0) {
				flag = true; 
				break ;
			}
		}
		if(flag == false) {
			freq[temp] = 0 ;
			printed[temp] = true ;
			cout << ans[i] ;
		}
		freq[temp] --;
	}
}


