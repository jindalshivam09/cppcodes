#include<iostream>
#include<cstdlib>
#include<fstream>
#define MAX 10000
using namespace std;
typedef long long ll;


void leftMin(ll *arr,ll *lArr,int n) {
	//int min = 0;
	lArr[0] = arr[0];
	ll sum=arr[0];
	bool flag=true;
	ll maxtil =0;;
	ll m=1000000000;
	
	for(int i=0;i<n;i++) {
			if(flag&&arr[i]>0)
    			{
    				if(i!=0)
						lArr[i]=min(lArr[i-1],arr[i]);
					else
						lArr[i]=arr[i];
				}
				else {
					if(arr[i]<0) flag=false;
	            	maxtil+=arr[i];
	            	if(maxtil>0)
	            		maxtil=0;
	            	if(maxtil<m)
	            		m=maxtil;   
	            	lArr[i]=m;
	            }
    }
}

void rightMin(ll *arr,ll *rArr,int n) {
	rArr[n-1] = arr[n-1];
	ll sum = arr[n-1];
	bool flag=true;
	ll maxtil =0;
	ll m=1000000000;
	
	for(int i=n-1;i>=0;i--) {
			if(flag&&arr[i]>0)
    			{
    				if(i!=n-1)
						rArr[i]=min(rArr[i+1],arr[i]);
					else
						rArr[i]=arr[i];
				}
				else {
					if(arr[i]<0) flag=false;
					//else flag = true;
	            	maxtil+=arr[i];
	            	if(maxtil>0)
	            		maxtil=0;
	            	if(maxtil<m)
	            		m=maxtil;   
	            	rArr[i]=m;
	            }
    }
}
void leftMax(ll *arr,ll *lArr,int n) {
	//int min = 0;
	lArr[0] = arr[0];
	ll sum=arr[0];
	bool flag=true;
	ll maxtil =0;;
	ll m=-1000000000;
	
	for(int i=0;i<n;i++) {
			if(flag&&arr[i]<=0)
    			{
    				if(i!=0)
						lArr[i]=max(lArr[i-1],arr[i]);
					else
						lArr[i]=arr[i];
				}
				else {
					if(arr[i]>0) flag=false;
	            	maxtil+=arr[i];
	            	if(maxtil<0)
	            		maxtil=0;
	            	if(maxtil>m)
	            		m=maxtil;   
	            	lArr[i]=m;
	            }
    }
}


void rightMax(ll *arr,ll *rArr,int n) {
//	int min = n-1;
	rArr[n-1] = arr[n-1];
	ll sum = arr[n-1];
	bool flag=true;
	ll maxtil =0;
	ll m=-1000000000;
	
	for(int i=n-1;i>=0;i--) {
			if(flag&&arr[i]<=0)
    			{
    				if(i!=n-1)
						rArr[i]=max(rArr[i+1],arr[i]);
					else
						rArr[i]=arr[i];
				}
				else {
					if(arr[i]>0) flag=false;
					//else flag = true;
	            	maxtil+=arr[i];
	            	if(maxtil<0)
	            		maxtil=0;
	            	if(maxtil>m)
	            		m=maxtil;   
	            	rArr[i]=m;
	            }
    }
}



main() {
	int t;
	cin >> t;
	while(t--) {
		ll arr[MAX],lmax[MAX],rmax[MAX],lmin[MAX],rmin[MAX];
		int n;
		cin >> n;
		int count=0;
		//ifstream in("test.txt");
		for(int i=0;i<n;i++) {
			cin >> arr[i];
			if(arr[i]<0)
			count++;
		}
		
		leftMin(arr,lmin,n);
		rightMin(arr,rmin,n);
		leftMax(arr,lmax,n);
		rightMax(arr,rmax,n);
		
		/*for(int i=0;i<n;i++)
		cout << lmin[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << rmin[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << lmax[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
		cout << rmax[i] << " ";
		cout << endl;*/
		
		ll m = -1000000000;
		for(int i=0;i<n-1;i++) {
			if(m < abs(lmin[i] - rmax[i+1]))
			m = abs(lmin[i] - rmax[i+1]);
		}
		
		for(int i=0;i<n-1;i++) {
			if(m < abs(rmin[i+1] - lmax[i]))
			m = abs(rmin[i+1] - lmax[i]);
		}
		cout << m << endl;
	}
}
