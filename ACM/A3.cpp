#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long       ll;
typedef vector<int>     vi;
typedef pair<int,int>   pii;

#define rep(n)          for(int i=0;i<n;i++)
#define repi(k,n)       for(int i=k;i<n;i++)
#define mp              make_pair
#define pb              push_back
#define all(a)          a.begin(),a.end()
#define imax            numeric_limits<int>::max()
#define imin            numeric_limits<int>::min()

bool super_flag;
int cou;
void brute(vector<vector<char> > &board, int i,int j,vector<vector<bool> > &pos,int m=0,int n=0,int count =0) {
    
//  cout << "d";
//  cout << i << " " << j << endl;
    if ( m > 7 || m < 0 || n > 7 || n < 0)
    return;
    if (pos[m][n])
    return;
    
   // pos[m][n] = true;
    cou ++;
    if(cou>=100000) return ;
    if(i==m&&j==n&&board[i][j]!='+')
        super_flag=true;
    if(super_flag) return;
    brute(board,i+2,j+2,pos,m+2,n+2,count);
    brute(board,i+2,j-2,pos,m+2,n+2,count);
    brute(board,i-2,j+2,pos,m+2,n+2,count);
    brute(board,i-2,j-2,pos,m+2,n+2,count);
    
    brute(board,i+2,j+2,pos,m+2,n-2,count);
    brute(board,i+2,j-2,pos,m+2,n-2,count);
    brute(board,i-2,j+2,pos,m+2,n-2,count);
    brute(board,i-2,j-2,pos,m+2,n-2,count);
    
    brute(board,i+2,j+2,pos,m-2,n+2,count);
    brute(board,i+2,j-2,pos,m-2,n+2,count);
    brute(board,i-2,j+2,pos,m-2,n+2,count);
    brute(board,i-2,j-2,pos,m-2,n+2,count);
    
    brute(board,i+2,j+2,pos,m-2,n-2,count);
    brute(board,i+2,j-2,pos,m-2,n-2,count);
    brute(board,i-2,j+2,pos,m-2,n-2,count);
    brute(board,i-2,j-2,pos,m-2,n-2,count);
}


int main() {

    int t;
    cin >> t;	
    while(t--) {
        
        vector<vector<char> > board(8,vector<char>(8));
        vector<pair<int,int> > knight(2);
        super_flag=false;
        int q=0;
        cou=0;
        for(int i=0;i<8;i++) {
            
            for(int j=0;j<8;j++) {
            
                cin >> board[i][j];
                if (board[i][j] == 'K') {
                    
                    knight[q++] = mp(i,j);
                }

                
            }
        }
        
        vector<vector<bool> > pos1(8,vector<bool>(8)) , pos2(8,vector<bool>(8)) ;
        
        brute(board,knight[0].first,knight[0].second,pos1,knight[1].first,knight[1].second);
        //brute(board,knight[1].first,knight[1].second,pos2,knight[1].first,knight[1].second);
        
//      cout << "F";

        /*
        for(int i=0;i<8;i++) {
        
                for(int j=0;j<8;j++) {
                    cout << pos1[i][j] << " ";
                }
                cout << endl;
        }
        cout << endl;
        for(int i=0;i<8;i++) {
        
                for(int j=0;j<8;j++) {
                    cout << pos2[i][j] << " ";
                }
                cout << endl;
        }
        */          
    
        bool flag = false;
        /*
        for(int i=0;i<8;i++) {
            
            for(int j=0;j<8;j++) {
                
                if(board[i][j]!='#'&&pos1[knight[1].first][knight[1].second]){
                    
                    cout << "YES" << endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
            break;
        }
        if(!flag)           cout << "NO" << endl;*/
        if(super_flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
