#include<iostream>
using namespace std;

float result[10];
float cal_prob(int *flags,float *prob,float *mul , int sum , int n,int index = 0,int cal_sum=0) {
	
	cout << sum << " " <<  cal_sum << " " << index<< endl;	
	if(index < n) {
		if(cal_sum + flags[index] > sum )	 {
			return mul[index];
		}
		else {
				 cout << cal_prob(flags,prob,mul,sum,n,index+1, cal_sum + flags[index]) << endl;
					
				 cout << cal_prob(flags,prob,mul,sum,n,index+1,cal_sum) << endl;
		}
	}		
	return 1;
	
}



int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		float prob[n];

		int flags[n] , sum=0;


		for(int i = 0 ; i < n ; i ++) {
			cin >> flags[i];
			sum += flags[i];
		}
		
		
		int a;
		
		for(int i = 0 ; i < n ; i ++) {
			cin >> a;
			prob[i] = (double)a/100;
//			cout << prob[i] << " ";
		}

		float mul[n];
		mul[n-1] = prob[n-1];
		
		for(int i = n-2 ; i >= 0 ; i--) {
			mul[i] = mul[i+1]*prob[i];
//			cout << mul[i] << " ";
		}
		

		cout << cal_prob(flags,prob,mul,sum/2,n);

	}
}
