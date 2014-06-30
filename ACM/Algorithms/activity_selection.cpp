/*
	Name: Actitvity selection problem  O(nlogn)
	Copyright: no rights
	Author: Shivam Jindal
	Date: 01/09/13 12:33
	Description: using greedy approach (coremen 16.1)
*/

#include<iostream>
#include<vector>
#include<utility>
#include<list>
#include<algorithm>
using namespace std;

#define start first
#define finish second

void cal_max_set (const vector<pair<int,int> > &time , list<pair<int,int> > &max_set) {

	max_set.push_back (make_pair(time[0].start,time[0].finish));
	
	int last = time[0].second;
//	cout << last << endl;
	for (int i = 1 ; i < time.size() ; i ++) {
	
		if (last < time[i].first) {
		
//			cout << time[i].first << endl;
			max_set.push_back (make_pair (time[i].start , time[i].finish));
			last = time[i].second;
		}
		
	}
}

void print (const pair<int,int> &set) {
	
	cout << set.first << " " << set.second << endl;
}

int main() {

	int n;
	cin >> n;
	
	vector<pair<int,int> > time(n);
	
	for (int i = 0 ; i < n ; i ++) {
		
		cin >> time[i].start >> time[i].finish ;
	}
	
	sort(time.begin() , time.end() , [](pair<int,int> a , pair<int,int> b) { return a.second < b.second;}  );

//	for_each (time.begin() , time.end() , print);
	
	list<pair<int,int> > max_set;
	
	cal_max_set(time,max_set);
	
//	for_each (max_set.begin() , max_set.end() , print);
	cout << max_set.size() ;
}

