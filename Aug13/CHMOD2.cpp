#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int avail[109][30];
int factors[109][109];
int avail_count[109];
int arr[] = {1,2,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
long long int calPow(int q,int n,int MOD) {
	long long int ans;
	if(n==1) 	return q;
	else {
		ans=calPow(q,n/2,MOD)%MOD;
		ans=(ans*ans)%MOD;
		if(n%2)		ans=(ans*q)%MOD;
	}
	return ans%MOD;
}

void init() {
	for(int i = 1 ; i < 101 ; i++) {
			
			factors[i][1] = 1;
			for(int j = 1 ; j < 26 && i/arr[j]; j ++) {
				if(!(i%arr[j])) {
					avail[i][avail_count[i]++] = (arr[j]);
					factors[i][arr[j]] ++;
					factors[i][arr[j]] += factors[i/arr[j]][arr[j]];					
			}
//			for(vector<int>::iterator j = avail[i].begin() ; j != avail[i].end() ; j++) 
//			cout << *j << " ";
//			cin.get();
//			cout << endl;
		}
	}
}

//need to optimise
int temp[100009][30];
int temp_count[100009];

void mul_left(vector<int> in, vector<vector<int> > &left ) {
	left[0][1] = 1;
	for(int i = 0 ; i < avail_count[in[0]] ; i++) {
		left[0][avail[in[0]][i]] = factors[in[0]][avail[in[0]][i]]; 
		temp[0][temp_count[0]++] = avail[in[0]][i];
	}
	int a,l,va,vl;
//	output(temp);	
	for(int i = 1 ; i < in.size() ; i ++) {
		left[i][1] = 1;
		a = 0;
		l = 0;
		while(a < avail_count[in[i]] && l < temp_count[i-1]) {
//			cout << a << " " << l << endl;
			va = avail[in[i]][a];
			vl = temp[i-1][l];
//			cout << va << " " << vl << endl;
			if(va == vl) {
				left[i][va] = factors[in[i]][va] + left[i-1][va];
				temp[i][temp_count[i]++] = va;
				a++;
				l++;
			}
			else if (va < vl) {	
				left[i][va] = factors[in[i]][va];
				temp[i][temp_count[i]++] = va;
				a++;
			}
			else {
				left[i][vl] = left[i-1][vl];
				temp[i][temp_count[i]++] = vl;;
				l++;
			}
		}
		while(a < avail_count[in[i]]) {
				va = avail[in[i]][a];
				left[i][va] = factors[in[i]][va];
				temp[i][temp_count[i]++] = va;
				a++;
		}
		while(l < temp_count[i-1]) {
				vl = temp[i-1][l];
				left[i][vl] = left[i-1][vl];
				temp[i][temp_count[i]++] = vl;;
				l++;
		}
//		for(vector<int>::iterator j = temp[i].begin() ; j != temp[i].end() ; j++) 
//		cout << *j << " ";
//		cout << endl;
	
	}
	
}

int main() {
	init();
	int n;
	scanf("%d",&n);
	vector<int> in(n);
	vector<vector<int> > left(n,vector<int>(109));
	
	for(auto &i : in) {
		scanf("%d",&i);
	}
	mul_left(in,left);
	int t;
	scanf("%d",&t);
	while(t--) {
		int l,r,m;
		scanf("%d%d%d",&l,&r,&m);
		int mul = 1;
		int vl;
		for(int i=0 ; i < temp_count[r-1]; i++) {
			vl = temp[r-1][i];
			if(l>1) {
				if(left[r-1][vl]-left[l-2][vl]) {
					mul = (mul * calPow(vl , left[r-1][vl]-left[l-2][vl] , m  ))%m ;
				}
			}
			else if(left[r-1][vl]) {
				mul = (mul * calPow(vl , left[r-1][vl],m ))%m ;
			}
	   	}
		printf("%d\n",mul);
	}
}
