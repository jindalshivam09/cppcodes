#include<iostream>
using namespace std;
class array {
	int arr[4];
	public:
		void set(int index ,int value){
		//	cout << index << " ";
			arr[index]=value;
		}
		int get(int index){
			//cout << "i = " << index << " ";
			return arr[index];
		}
};

class stack : private array {
	private:
		int top ;
	public:	
		stack():top(-1)
		{}
		int pop() {
		//	cout<<top << " ";
			return get(top--);
		}
		void push(int a) {
			++top;
		//	cout<< "t = " << top << " ";
			set(top,a);	
		}
};

main() {
	stack ob;
	ob.push(2);
	ob.push(4);
	ob.push(6);
	int a=3;
//	cout<<ob.pop() << " shivam " << ob.pop() << " " << ob.pop() << " " ;
	cout<<ob.pop()
		<< a << " " << ob.pop();;
	cout<< " " <<ob.pop();
}
