#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
typedef long long ll;
#define MAX 100009
typedef struct  {
	int frequency;
	int bottles;
	int total_capacity;
	int max_cap;
	int bottle_cap[MAX];
} 	data;
////////////////////////////////////////////////////////////////////////////////



void reset (data *room , int n) {
	for(int i = 0 ; i < n ; i++) {
		room[i].frequency = 0;
	//	memset(room[i].is_avail ,0 , sizeof(room[i].is_avail));
	}
}

void input_path (data *room,int m) {
	int c;
	for(int i = 0 ; i < m ; i ++) {
		cin >> c;
		room[c].frequency++;
	}
}
void input_lemonade (data *room , int n) {
	int c,v;
	ll sum = 0;
	int maxm ;
	for(int i = 0 ; i < n ; i ++) {
		cin >> c;
		room[i].bottles = c;
		sum = 0;
		maxm = -1;
		for(int j = 0 ; j < c ; j ++) {
			cin >> v;
			sum += v;
			if(maxm < v)
			maxm = v;
			room[i].bottle_cap[j] = v;;
		}	
		room[i].max_cap = maxm;
		room[i].total_capacity = sum;
	}
}

void sort_bottle_cap(data *room,int n) {
	for(int i = 0 ; i <  n ; i++)
	sort(room[i].bottle_cap, room[i].bottle_cap + room[i].bottles);
}
ll total_drunk(data *room,int n) {
	ll sum = 0;
	for(int i = 0 ; i < n ; i++) {
//		cout << room[i].bottles << " " << room[i].frequency << endl; 
		if(room[i].bottles <= room[i].frequency)
		sum += room[i].total_capacity;
		else {
			for(int j = room[i].bottles-1 ; j >= 0 && room[i].frequency && room[i].bottles ; j --) {
//				cout << room[i].is_avail[j] << endl;
//					cout << "else";
//		cout << room[i].is_avail[j] << endl;
//					cout << j << " ";
					sum += room[i].bottle_cap[j] ;
					room[i].bottles--;
					room[i].frequency--;
				
			}
//			cout << endl;
		}
//		cout << sum << endl;
	}
	return sum;
}

data room[109];
		
int main () {
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		
		reset(room,n);
		input_path(room,m);
		input_lemonade(room,n);
		sort_bottle_cap(room,n);
		cout << total_drunk(room,n) << endl;

	}
}
