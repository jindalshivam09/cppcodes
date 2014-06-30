#include<iostream>
#include<type_traits>
template<typename T> void foo (T t,true_type) {
	cout << t << "integer" << endl;
}
template<typename T> void foo (T t,false_type) {
	cout << t << "float" << endl;
}

template<typename T> void bar (T t) {
	foo(t,typename is_integral<T>::type());
}

main() {
	bar(3);
	bar(1.3);
}
