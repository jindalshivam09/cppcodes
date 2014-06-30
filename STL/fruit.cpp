#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std; 

void print(string s) {
	cout << s << " ";
}

class fruits {
	vector<string> f;
	public:
		fruits() {
			f.reserve(MAX);
		}
		~fruits() {}
		void enterFruits(int n) {
			string fruit;
			for(int i=0;i<n;i++) {
				cin >> fruit;
				f.insert(f.begin(),fruit);
			}
		}
		void display() {
			for_each(f.begin(),f.end(),print);
		}
		void sortFruits() {
			sort(f.begin(),f.end());
		}
		void eraseFruits(char a) {
			sort(f.begin(),f.end());
			vector<string>::iterator p1;      //=find_if(f.begin(),f.end(),initial(a));
			vector<string>::iterator p2;      //=find_if(f.begin(),f.end(),initial_not(a));
			for(vector<string>::iterator i=f.begin();i!=f.end();i++) {
				if((*i)[0]==a) {
					p1 = i;
					break;
				}
			}
			for(vector<string>::reverse_iterator i=f.rbegin();i!=f.rend();i++) {
				if((*i)[0]==a) {
					p2 = i.base();
					break;
				}
			}
			f.erase(p1,p2);
		}
};
main() {
	fruits ob;
	int n;
	char c;
	cout << "Enter total number of fruits : ";
	cin >> n;
	cout << "Enter fruits :\n" ;
	ob.enterFruits(n);
	//ob.sortFruits();
	cout << "Enter the first letter of fruit you want to remove : "  ;
	cin >> c;
	ob.eraseFruits(c);
	ob.display();
}	
