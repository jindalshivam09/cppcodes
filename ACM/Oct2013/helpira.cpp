#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

int main() {
	
	int n;
	int x1,x2,x3,y1,y2,y3;
	
	cin >> n;
	
	long long maxarea=numeric_limits<int>::min(),minarea=numeric_limits<int>::max(),area;
	int maxi,mini;
	
	for(int i=0;i<n;i++) {
		
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		area = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
		
		if(maxarea <= area) {
			
			maxi = i+1;
			maxarea = area;
		}
		if(minarea >= area) {
			
			mini = i+1;
			minarea = area;
		}
	}
	
	cout << mini << " " << maxi << endl;
}
