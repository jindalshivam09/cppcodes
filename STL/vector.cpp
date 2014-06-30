#include <iostream>
#include<vector>
#include<functional>              // to use greater string
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " " ;
}
main() {
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	//v.push_front(2);
	v.pop_back();            // there is no pop_front() & push_front() functions for vector

	vector<int>::iterator i = v.begin()+4;
	i+=4;
	sort(v.begin(),v.end(),greater<int>());                        //greater<int> to sort vector in reverse order
	for(vector<int>::iterator i=v.begin(); i!=v.end(); ++i)
	cout << *i <<endl ;
	cout << endl;
	v.erase(remove(v.begin(),v.end(),2),v.end());
	
	for(vector<int>::reverse_iterator i=v.rbegin(); i!=v.rend(); ++i)	// reverse_iterator is used in opp sense to iterator
	cout << *i <<endl;
	
	for_each(v.rbegin(),v.rend(),print);
	cout << endl;
	int key=2;
	cout << "2 = " << count(v.begin(),v.end(),key);          // this will count numbers of keys in vector v
	
	cout << endl;
	
	vector<int> e;
	e.assign(v.end()-v.begin(),1);							//assign funct work as multi value constructor as of  w in at.cpp 
	for_each(e.rbegin(),e.rend(),print);
	cout << endl;
	
}
