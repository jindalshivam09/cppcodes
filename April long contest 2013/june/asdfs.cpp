#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
main() {
	ofstream out("test.txt");
	
	for(int i=0;i<8924;i++) {
		if(rand()%2)
		out << rand()-100000000 << " ";
		else 
		out << rand()+100 << " ";
		
	} 
}
