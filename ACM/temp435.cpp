#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int a,p;
	scanf("%d%d",&a,&p) ;
	
	int val = 1;
	for(int i=1;i<=p;i++) 
		val *= a ;
	printf("%d",val) ;
}
