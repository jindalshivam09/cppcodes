#include<iostream>
#include<map>
#include<vector>
using namespace std;

main() {
	auto i = 4;
	cout << i << endl;
	bool flag = nullptr;
	cout << flag;
	
		std::map<std::string, std::vector<int>> map;
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		map["one"] = v;
		
		for(const auto kvp : map) 
		{
		  std::cout << kvp.first << std::endl;
		
		  for(auto v : kvp.second)
		  {
		     std::cout << v << std::endl;
		  }
		}
		
		int arr[] = {1,2,3,4,5};
		for(int e : arr) 
		{
		  e = e*e;
	}
}
