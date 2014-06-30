/*
	Name: Stable Marriage Algorithm
	Copyright: no rights
	Author: Shivam Jindal
	Date: 30/07/13 22:27
	Description: using gayle-shapley algo in which each free man (that is who has not engaged yet) has assigned a woman if she is
				 free else if she is engaged then it is checked if she makes a more preffered match with him free woman is found.  
				This is continued until all men are engaged.	
*/

#include<iostream>
#include<vector>
#include<list>
#include<cstring>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define free 0
#define engaged 1
typedef vector < vector < int >  >  preferences;
typedef list < int >	free_men;
typedef bool free_women;
typedef vector < int > match;
////////////////////////////////////////////////////////////////////////////////

void input (preferences &list , int n) {
	int a;
	for (auto i = list.begin() ; i != list.end() ; i++) {
		for(auto j = i->begin() ; j != i->end() ; j ++) {
			cin >> a;
			*j = a-1;
//			cout << *j << " ";
		}
//		cout << endl;
	}
/*	for(int i = 0 ; i < n ; i ++)
	for(int j = 0 ; j < n ; j ++)
	cout << list[i][j] << " ";
	cout << "inputting";
*/	
}

void output (match mp ) {
	for (int i = 0 ; i < mp.size() ; i ++) {
		cout << i+1 << " " << mp[i]+1 << endl;
	}
}
////////////////////////////////////////////////////////////////////////////////

void stable_marriage (preferences men , preferences women , int n , match &mp) {
	free_men m ;
	free_women w[n];
	memset (w , 0 ,sizeof(w));
	
	int woman_to_be_married;
	match  wp(n);
	
	for(int i = 0 ; i < n ; i ++)
	m.push_back(i);
	
	int man_to_be_married ;
	while(m.size()) {
//		cout << "while";
//		cout << m.front();
		man_to_be_married = m.front() ;
//		cout << men[man_to_be_married][0];
		for ( int i = 0 ; i < n ; i ++) {
//			cout << "for" << men[man_to_be_married][i];		// here coming the error
			woman_to_be_married = men[man_to_be_married][i]; 
//			cout << woman_to_be_married << " ";
			if( w[woman_to_be_married] == free) {
				mp [man_to_be_married] = woman_to_be_married;
				wp [woman_to_be_married] = man_to_be_married;
				w[woman_to_be_married] = engaged;
				m.pop_front(); 
//				cout << "if";
				break;
			}
			else {
				if ( women [man_to_be_married] > women [ wp[woman_to_be_married] ]){
//					cout << "elseif";
					mp [man_to_be_married] = woman_to_be_married;
					wp [woman_to_be_married] = man_to_be_married;
					w[woman_to_be_married] = engaged;
					m.pop_front();
					break; 
				}
//				cout << "else";
				
			}
//			cout << endl;
//			cin.get();
		}	
//		cout << endl;
	}
	
	
}

////////////////////////////////////////////////////////////////////////////////
main () {

	int n;
	cin >> n;
	
	preferences men(n, match(n));
	preferences women(n, match(n));
	
	match mp(n);
//	cout << "hi";
	input(men,n);
	input(women,n);
	
	stable_marriage (men , women , n, mp) ;
	cout << "Stable Marriage Pairs :" << endl;
	output (mp);

}
