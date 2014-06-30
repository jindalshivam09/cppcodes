#include<bits/stdc++.h>
using namespace std;
int n,m;
#define MAX 10000
vector<string> orig(MAX);
class Unblur {
	public:
		bool check (int i,int j ){
			if (i>=0&&i<=n&&j>=0&&j<=m)
				return true;
			return false;
		}
		int calhashes (vector<string> blurred,int i,int j) {
			int count = 0;
			if(check(i-1,j-1) && blurred[i-1][j-1] == '#') count++; 			
			if(check(i-1,j) && blurred[i-1][j] == '#') count++; 
			if(check(i-1,j+1) && blurred[i-1][j+1] == '#') count++; 
			if(check(i,j-1) && blurred[i][j-1] == '#') count++; 
			if(check(i,j) && blurred[i][j] == '#') count++; 
			if(check(i,j+1) && blurred[i][j+1] == '#') count++; 
			if(check(i+1,j-1) && blurred[i+1][j-1] == '#') count++; 
			if(check(i+1,j) && blurred[i+1][j] == '#') count++; 
			if(check(i+1,j+1) && blurred[i+1][j+1] == '#') count++;
			return count; 
		}
		void puthash (int i,int j) {
			if(check(i-1,j-1) && orig[i-1][j-1] != '#' && orig[i-1][j-1] != '.')  orig[i-1][j-1] = '#' 			;
			if(check(i-1,j) && orig[i-1][j] != '#' && orig[i-1][j] != '.' )  orig[i-1][j] = '#' ;
			if(check(i-1,j+1) && orig[i-1][j+1] != '#'&& orig[i-1][j+1] != '.') orig[i-1][j+1] = '#'; 
			if(check(i,j-1) && orig[i][j-1] != '#' && orig[i][j-1] != '.')  orig[i][j-1] = '#';
			if(check(i,j) && orig[i][j] != '#' && orig[i][j] != '.')  orig[i][j] = '#';
			if(check(i,j+1) && orig[i][j+1] != '#' && orig[i][j+1] != '.') orig[i][j+1] = '#';
			if(check(i+1,j-1) && orig[i+1][j-1] != '#' && orig[i+1][j-1] != '.') orig[i+1][j-1] = '#';
			if(check(i+1,j) && orig[i+1][j] != '#' && orig[i+1][j] != '.') orig[i+1][j] = '#';
			if(check(i+1,j+1) && orig[i+1][j+1] != '#' && orig[i+1][j+1] != '.') orig[i+1][j+1] = '#';
		}
		vector<string> original (vector<string> blurred) {
			n = blurred.size();
			m = blurred[0].size();
			for(int i=0;i<n;i++)
				orig[i].resize(m);
			char dot = '.' , hash = '#';
			for(int i=0;i<n;i++)
				orig[i][0] = dot;
			
			for(int i=0;i<n;i++)
				orig[i][m-1] = dot;
				
			for(int i=0;i<m;i++)
				orig[0][i] = hash;
				
			for(int i=0;i<m;i++)
				orig[n-1][i] = hash;	
			int temp,count;	
			for(int i=1;i<n-1;i++) {
				for(int j=1;j<m-1;j++) {
					count = calhashes(blurred,i,j);
					temp = blurred[i][j] - '0';
					count = temp - count;
					if(count)
						puthash(i,j);
				}
			}
			return orig;
		}
};

