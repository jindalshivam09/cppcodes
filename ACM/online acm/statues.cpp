#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool all_equal (vector<int> &arr,int n) {
	
	for(int i=1;i<n;i++) {
		
		if(arr[i] != arr[0])
		return false;
	}
	return true;
}

int min_moves (vector<int> &arr,int n) {
	
	sort(arr.begin(),arr.end());
	
	int count = 0;
	while(!all_equal(arr,n)) {
		
		count++;
		arr[0] ++;
		arr[n-1] --;
/*		for(int i=0;i<n;i++)
		cout << arr[i] << " ";
		cout << endl;
*/		sort(arr.begin(),arr.end());
	}
	return count;
}

int main() {
	
	int n;
	int test = 1;
	cin >> n;
	while(n)  {
		
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin >> arr[i];
		
		cout << "Set #" << test << endl; 
		cout <<	"The minimum number of moves is ";
		cout << min_moves(arr,n) << "." << endl;
			
		test++;
		cin >> n;
	}
}
