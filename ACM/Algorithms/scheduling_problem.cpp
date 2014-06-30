/*
	Name: Scheduling problem
	Copyright: no rights
	Author: Shivam Jindal
	Date: 11/08/13 12:41
	Description: we have given a certain jobs with their priority and time of completion and we have a
				single resource to do that job.
				what we have to do is that we have to arrange the jobs in the best possible way
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


#define MAX 10

typedef struct {
	
	int weight;
	int length;
	double ratio ;
} jobs;

void input (jobs *arr ) {
	
	for(int i = 0 ; i < sizeof(arr) ; i ++) {
	
		cin >> arr[i].weight >> arr[i].length ;
		arr[i].ratio = (double)arr[i].weight / arr[i].length ; 
	}
}

void output (const jobs *arr) {

	for (int i = 0 ; i < sizeof(arr) ; i ++) {
	
		cout << arr[i].weight << " " << arr[i].length << endl;
	}
}


int main() {

	int n;
	cin >> n;
	jobs arr[n];
	
	input (arr) ;	
	
	sort (arr,arr+n , [](jobs a , jobs b) {  return a.ratio > b.ratio ;});
	
	output (arr);
}


