#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	string str = "shivam jindal";
	
	cout << str << endl;
	str.erase(str.begin(),str.end());
	cout << str;
}
