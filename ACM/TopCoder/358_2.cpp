#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
class trie {
	int words , prefixes ;
	map < char , class trie * > edge;

	public :
		trie ( ) {
			words = prefixes = 0;
		}
		void addWord ( class trie * vertex , string word ) {
			if ( word.empty() ) {
				vertex -> words ++;
				return ;
			}
			char k = word[0];
			word.erase ( 0 , 1 );
			vertex -> prefixes ++;
			if ( vertex->edge[k] ) {
				addWord ( vertex->edge[k] , word );
			}
			else {
				class trie * temp = new trie;
				vertex->edge[k] = temp;
				addWord ( temp , word );
			}
			return ;
		}
		
		int countPrefixes ( class trie * vertex , string word ) {
			char k = word[0];
			if ( word.empty() )
				return vertex -> prefixes ;
			if ( !vertex->edge[k] )
				return 0;
			word.erase ( 0 , 1 );
			return countPrefixes ( vertex->edge[k] , word );
		}
		
		int countWords ( class trie * vertex , string word ) {
			char k = word[0];
			if ( word.empty() )
				return vertex -> words ;
			if ( !vertex->edge[k] )
				return 0;
			word.erase ( 0 , 1 );
			return countWords ( vertex->edge[k] , word );
		}
		
};
class trie *root = new trie;
class CyclicWords {
	public:
		int differentCW ( vector<string> words ) {
			int n , temp , index;
			int count = 0;
			rep(i,words.size()) {
				index = 0;
				n = words[i].size();
				repi(j,1,n) {
					temp = index ;
					for ( int k=j ; k < j+n ; k++) {
						if ( words[i][temp%n] > words[i][k%n]) {
							index = j; ;
							break;
						}
						else if ( words[i][temp%n] < words[i][k%n] )
							break;
						temp ++ ;
					}	
				}
				string str ;
				for(int k=index ; k < index+n ; k++) {
					str += words[i][k%n];
				}
	//			cout << str << endl;
				if ( root->countWords(root,str) == 0) {
					root->addWord(root,str);
					count ++;
				}
			}
			return count ;
		}
} ob;
int main() {
	int n;
	cin >> n;
	vector<string> str(n);
	rep(i,n)
		cin >> str[i];
	cout << ob.differentCW ( str );
}


