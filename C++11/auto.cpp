//---------------use of auto -----------------------
#include<iostream>
using namespace std;

auto func() -> int{			// auto cant be used as return type of a function but if we define function with its trailing return type 
	return 7;				// we can only then use auto
}

int main() {
	cout << func();
}
