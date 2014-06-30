#include<iostream>
#include<vector>
using namespace std;
 
int main() {
    
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> forward(n+1),backward(n+1);
    
	for(int i = 1 ; i < arr.size() ; i ++) {
	
		cin >> arr[i];
	}
	
	for(int i = 1 ; i < arr.size() ; i ++) {
		
		if(!forward[arr[i]])
			forward[arr[i]] = i;
	}
	
	for(int i = arr.size()-1 ; i > 0 ; i --) {
		
		if(!backward[arr[i]])
			backward[arr[i]] = i;
	}
	
	vector<pair<int,int> > p;
	int count = 0;
	int size = arr.size() - 1;
	for(int i = 1 ; i < arr.size() ; i ++) {
	
		if (forward[i] + 2*backward[i] > size && forward[i] != backward[i]) {
			p.push_back(make_pair(forward[i],backward[i]));
			size -= 2;
			count++;
			
			int a = forward[i] , b =backward[i];
			for(int j = 1 ; j < arr.size() ; j ++) {
				
				if(forward[j] > a) {
					forward[j]--;
					backward[j]--;
				}
				if(backward[j] > b)
					backward[j] --;
			}	
		}
	}
	
    cout << count + size << endl;
    for(int i=0;i < p.size() ;i++)
    	cout << p[i].first << " " << p[i].second << endl;
    
    int temp  = size;
    for(int i = 0 ; i < size ; i ++) {
		cout << temp << " " << 1 << endl;
		temp--;
	}
	return 0;
}


