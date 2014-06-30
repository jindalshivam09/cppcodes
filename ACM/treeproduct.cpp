#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define MOD 1000000007
#define epsilon 1e-9

long long ans;

void product (vector<int> &tree, vector<double long> &temp , int i, int size) {
	
	ans = ( ans * tree[i] ) % MOD ;
	if(i*2 > size)	return ;
	if((i*2 + 1 > size) || abs(temp[i] - temp[i*2+1] - log(tree[i]) > epsilon) )
	 	product(tree,temp,i*2,size);
	else product(tree,temp,i*2+1,size);	
	
}

int main() {

	int h;
	cin >> h;
	while(h) {

		vector<int> tree(1<<h);
		vector<double long> temp(1<<h);
		int n=0; 
		for(int i=1 ; i<(1<<h); i++) {
			cin >> tree[i];
//			temp[i] = log(tree[i]);
//			cout << temp[i];
			n++;
		}
		for(int i=n ; i>=1 ; i --) {
	
			if(i*2 > n)  temp[i] = log(tree[i]);
			else {
				temp[i] = temp[i*2];
				if(i*2+1 <= n && temp[i*2+1] > temp[i] + epsilon)
					temp[i] = temp[2*i+1];
				
				temp[i] += log(tree[i]);	
			}
		}
	
	
		ans = 1;
		product(tree,temp,1,n);
		cout << ans << endl;
	
		cin >> h;
	}
}
