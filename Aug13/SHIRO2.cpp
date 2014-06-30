#include<iostream>
#include<vector>
#include<cstring>

#define COL 10009
#define ROW 109

using namespace std;

struct m {
	bool flag;
	double prob;
} memo[ROW][COL];



double cal(vector<int> &arr , vector<double> &prob, int sum , int cal_sum = 0 , int index = 0) {

	if(memo[index][cal_sum].flag) {	
	
		return 	memo[index][cal_sum].prob;
	}
	
	if(cal_sum >= sum-cal_sum) {
	
		return 1;
	}
	
	else if(cal_sum < sum-cal_sum && index >= prob.size() ) {
	
		return 0;
	}
	
	else {
	
		memo[index][cal_sum].flag = true;
		return  (memo[index][cal_sum].prob = ( prob[index] * cal(arr, prob , sum , cal_sum + arr[index] , index+1 ) ) + 
											 ( (1 - prob[index]) * cal(arr, prob , sum , cal_sum , index+1 ) ) ); 
	}
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
			
				
		int n;
		cin >> n;
		
		vector<int> arr(n);
		vector<double> prob(n);
		
		memset(memo,0,sizeof(memo));		
		
		int sum = 0 ;
		
		for(auto &i : arr) {
			
			cin >> i;
			sum += i;
		}

		int a;
		
		for(auto &i : prob) {
		
			cin >> a;
			i = (double)a/100;
			
		}	
		
		cout << cal(arr,prob,sum) << endl;	
	}
}
