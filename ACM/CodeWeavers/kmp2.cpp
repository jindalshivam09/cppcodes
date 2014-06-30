// from geeksforgeeks
// whole code is taken for geeksforgeeks 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);

bool KMPSearch(char *pat, char *txt,int M,int N)
{
int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0; 
 computeLPSArray(pat, M, lps);
bool flag = false;
    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
 //       printf("YES\n");
        flag = true;
        return true;
        j = lps[j-1];
      }    
	  else if(pat[j] != txt[i])
      {
      if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return false;
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           len = lps[len-1];
 }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		int a,b;
		
				vector<int> arr(2*n+1);
				string str;
		int j=0;
		if(n==1) {
			cin >> arr[0];
			cout <<"YES\n";
			continue;
		}
		for(int i=0;i<n;i++) {
			
			cin >> arr[i];
			arr[i+n] = arr[i];

		}	
		n = 2*n;
		for(int i=1;i<n;i++) {
		
			
					if(arr[i]-arr[i-1] > 0 )	{
				str.append("G");  }
			else if (arr[i]-arr[i-1] < 0){
				str.append("L"); }
			else				str.append("E");
		}
	   char txt[str.size()];
		for(int i=0;i<str.size();i++)
		txt[i]=str[i];
	
//		cout << str;
		string str2;
		cin >> str2;
	   char pat[str2.size()];
	   for(int i=0;i<str2.size();i++)
	   pat[i] =  str2[i];
	    if(KMPSearch(pat, txt,str2.size(),n-1)) {
	    	
	    	cout << "YES\n";
	    }
	    else
	    cout << "NO\n";
	
	}
   return 0;
}
