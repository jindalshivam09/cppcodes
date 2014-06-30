#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define MAX 501

vector<int> count_primes (MAX);
char grid[MAX][MAX];

struct node {
	
	int L,R,T,B;
}cell[MAX][MAX];

void sieve(int n) {
	
	vector<bool> isPrime(n+1);
	int s=sqrt(n);
   	int a;
	for(int i=2;i<=s;i++)
	{
		 a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
     	{
			   isPrime[j]=1;
            //	cout<<j<<" ";
	    }
	}
	//cout<<"2 ";
	count_primes[0] = count_primes[1] = 0;
	count_primes[2] = 1;
	int count = 1;
	for(int i=3;i<=n;i++) {
		
		if (!isPrime[i] && i%2)
		count++;
		count_primes[i] = count;
//		cout << i << " " << count_primes[i] << endl;	
	}
}

int monsters (int m,int n){

	int l,r,t,b,p;
	int count=0;
	
	for (int i = 0 ;i < n ; i ++) {
		
		if(!i) {
			cell[0][i].L = 0;
			cell[0][i].T = 0;
			
			
			cell[m-1][0].L = 0;
			cell[m-1][0].B = 0;
		}
		else {
			
			if (grid[0][i-1] == '^')		cell[0][i].L = cell[0][i-1].L + 1;
			else							cell[0][i].L = 0;
			
			cell[0][i].T = 0;
			
			if (grid[m-1][i-1] == '^')		cell[m-1][i].L = cell[m-1][i-1].L + 1;
			else							cell[m-1][i].L = 0;
			
			cell[m-1][i].B = 0;
		}
	}
	
	for (int i = 0 ;i < m ; i ++) {
		
		if(!i) {
			cell[0][0].L = 0;
			cell[0][0].T = 0;
			
			
			cell[0][n-1].T = 0;
			cell[0][n-1].R = 0;
		}
		else {
			
			if (grid[i-1][0] == '^')		cell[i][0].T = cell[i-1][0].T + 1;
			else							cell[i][0].T = 0;
			
			cell[i][0].L = 0;
			
			if (grid[i-1][n-1] == '^')		cell[i][n-1].T = cell[i-1][n-1].T + 1;
			else							cell[i][n-1].T = 0;
			
			cell[i][n-1].R = 0;
		}
	}
	
	for (int i = 1 ; i < m-1 ; i ++) {
	
		for (int j = 1 ; j < n ; j ++) {
		
			if (grid[i][j-1] == '^')			cell[i][j].L = cell[i][j-1].L + 1;
			else								cell[i][j].L = 0;		
		}
	}
	
	for (int i = 1 ; i < m-1 ; i ++) {
	
		for (int j = n-2 ; j >= 0  ; j --) {
		
			if (grid[i][j+1] == '^')			cell[i][j].R = cell[i][j+1].R + 1;
			else								cell[i][j].R = 0;		
		}
	}
	
	for (int j = 1 ; j < n-1 ; j ++) {
	
		for (int i = 1 ; i < m ; i ++) {
		
			if (grid[i-1][j] == '^')			cell[i][j].T = cell[i-1][j].T + 1;
			else								cell[i][j].T = 0;
		}
	}
	
	for (int j = 1 ; j < n-1 ; j ++) {
	
		for (int i = m-2 ; i >= 0 ; i --) {
		
			if (grid[i+1][j] == '^')			cell[i][j].B = cell[i+1][j].B + 1;
			else								cell[i][j].B = 0;
		}
	}
	
	
	
	for (int i = 0 ; i < m ; i ++ ) {
		
		for (int j = 0 ; j < n ; j ++) {
		
			if (grid[i][j] != '#') {
			
				l = cell[i][j].L;	
				r = cell[i][j].R;
				t = cell[i][j].T;
				b = cell[i][j].B;
				p = min (l,r);
				p = min (t,p);
				p = min (b,p);
				
				count += count_primes[p];
			}
		}
	}
	return count;
}



int main() {

	sieve(50);
	int t;
	cin >> t;
	while(t--) {
	
		int r,c;
		cin >> r >> c;
		
		for (int i = 0 ; i < r ; i ++) {
			
			cin >> grid[i];
		}
		
		cout << monsters(r,c) << endl;
	}
}
