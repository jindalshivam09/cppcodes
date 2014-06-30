#include<iostream>
#include<vector>
using namespace std;

long long int calPow(int q,int n,int MOD)
{
	 //c\out<<"n="<<n<<" ";
	 long long int ans;
	 if(n==1)
	 {
          //   a*=q;
		//	cout<<n<<" "<<ans<<" "<<q<<" ";
			return q;
     }
	else
	{
		ans=calPow(q,n/2,MOD)%MOD;
	//	cout<<"ret ans= "<<ans<<" ";
		ans*=ans;
		ans%=MOD;
		if(n%2)
		{
				  ans*=q;
				  ans%=MOD;
		}
//		cout<<n<<" "<<ans<<" "<<q<<" ";
	}
	return ans;
}

void input(vector<int> &arr) {
	for(auto &i : arr)
	cin >> i;
}

void mul_left(vector<int> arr, vector<long long> &left , int MOD) {
	left[0] = arr[0]%MOD;
	for(int i = 1; i < arr.size() ; i++) {
		left[i] = (arr[i]%MOD * left[i-1])%MOD;
	}
}

void mul_right(vector<int> arr , vector<long long> &right , int MOD) {
	right[arr.size()-1] = arr[arr.size()-1]%MOD;
	for(int i = arr.size()-2; i >= 0 ; i--) {
		right[i] = (arr[i]%MOD * right[i+1])%MOD;
	}
}

void output(vector<long long> arr){
	for(auto i : arr){
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<long long> left(n);
	vector<long long> right(n);
	input(arr);
	int t;
	cin >> t;
	while(t--) {
		int l,r,m;
		cin >> l >> r >> m;
		mul_left(arr,left,m );
		mul_right(arr,right,m );
		output(left);
		output(right);
		if(l>1) {
			cout << left[r-1] << " " << left[l-2] << " ";
			cout << (left[r-1] * left[l-2])%m;
		}
		else 
		cout << left[r-1];
		cout << endl;
	}
}
