#include<iostream>
using namespace std;
template<typename t>
t func(t a){
	return a;
}
main(){
	cout<<func(4)<<endl;
	cout<<func(4.6);
	
}
