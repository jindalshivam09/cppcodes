/*
	Name: to play a match stick game optimally
	Copyright: no rights 
	Author: Shivam Jindal
	Date: 09/08/13 21:39
	Description: we have 21 matchsticks and we can take either 1 or 2 or 3 matchsticks from them . we are playing against computer . we have to play 
				optimally so that we will win as winner is decided on the basis of one who will pick the last matchstick. 
*/

#include<iostream>

using namespace std;

int moves[] = {1,2,3};

void game (int match_sticks,int i = 0) {
	
	if(match_sticks > 0) {
		cout << match_sticks << " ";
		game(match_sticks - 1);
		game(match_sticks - 2);
		game(match_sticks - 3);
	} 
	else cin.get();

}

int main() {

	game(21);
}

