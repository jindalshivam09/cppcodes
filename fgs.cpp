#include<iostream>
using namespace std;
class matrix {
	int arr[10][10];
	public :
		matrix () {}
		matrix (int arr[][10]) {
		}
};
main() {
	int arr[2][2]={1,2,3,4};
	matrix  mat(arr); 
}
