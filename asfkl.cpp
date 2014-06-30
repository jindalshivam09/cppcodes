#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class String {
	char arr[100];
	public :
		String() {}
		String (char *arr) {
			strcpy(this->arr,arr);
		}
		void leftcat (String ob) {
			String temp;
			strcpy(temp.arr,arr);
			strcpy(arr,ob.arr);
			strcat(arr,temp.arr);
		}
		void rightcat (String ob) {
			strcat(arr,ob.arr);		
		}
		void display() {
			cout<<arr<<endl;
		}
		
};
main() {
	String ob("shivam");
	String ob2("saksham");
	String ob3("jindal");
	ob.leftcat(ob2);
	ob.display();
	ob2.rightcat(ob3);
	ob2.display();
}
