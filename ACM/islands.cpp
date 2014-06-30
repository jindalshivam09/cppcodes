#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool is_safe(int i,int j,int r,int c,const vector<vector<bool> > &is_visited,const vector<vector<int> > &islands) {
	
//	cout << "safe";
//	cout << i << " " << j << endl;
	return (i >= 0 && i < r && j >= 0 && j < c && !is_visited[i][j] && islands[i][j] );
}

void dfs (int i,int j, vector<vector<bool> > &is_visited ,const vector<vector<int> > &islands , int r,int c) {

//	cout << "dfs";
	is_visited[i][j] = true;
	
	if(is_safe(i-1,j-1,r,c,is_visited,islands)) 		dfs(i-1,j-1,is_visited,islands,r,c);
	if(is_safe(i-1,j,r,c,is_visited,islands))			dfs(i-1,j,is_visited,islands,r,c);
	if(is_safe(i-1,j+1,r,c,is_visited,islands)) 		dfs(i-1,j+1,is_visited,islands,r,c);
	if(is_safe(i,j-1,r,c,is_visited,islands)) 			dfs(i,j-1,is_visited,islands,r,c);
	if(is_safe(i,j+1,r,c,is_visited,islands))			dfs(i,j+1,is_visited,islands,r,c);
	if(is_safe(i+1,j-1,r,c,is_visited,islands)) 		dfs(i+1,j-1,is_visited,islands,r,c);
	if(is_safe(i+1,j,r,c,is_visited,islands)) 			dfs(i+1,j,is_visited,islands,r,c);
	if(is_safe(i+1,j+1,r,c,is_visited,islands)) 		dfs(i+1,j+1,is_visited,islands,r,c);
}


int count_islands(const vector<vector<int> > &islands , int r,int c) {

	vector<vector<bool > > is_visited(r,vector<bool>(c,false));
	int count = 0;
	for(int i=0; i<r ; i++) {
	
		for(int j=0 ; j<c ; j++) {
		
			if(!is_visited[i][j] && islands[i][j])	{
				
				dfs(i,j,is_visited,islands,r,c);
				count++;
			}
		}
	}
	return count;
}

int main() {

	int r,c;
	cin >> r >> c;
	
	vector<vector<int> > islands(r,vector<int>(c));
	for(int i=0 ; i<r ; i++) {
	
		for(int j=0 ; j<c ; j++) {
		
			cin >> islands[i][j];
		}	
	}
	
	cout << count_islands(islands,r,c) << endl;

}
