#include<bits/stdc++.h>
using namespace std;

typedef struct turtle
{
    int w;
    int s;
}book;


bool comp(book a, book b)
{
    return (a.s < b.s);
}

int dp[6000][6000];
int main()
{
    //FILE *fp;
    //fp = fopen("input.txt","r");
    
    
    //ifstream cin("input3.txt");
    //ofstream cout("output3.txt");
    int t;
    cin>>t;
    while(t--)
    {
    	int a,b;
		int n;
	    cin>>n;
	    vector<book> arr;
	    //cout<<n<<endl;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a>>b;
	        book temp;
	        temp.w = a;
	        temp.s = b;
	        arr.push_back(temp);
	    }
	    //cout<<"n: "<<n<<endl;
	    //n = arr.size();
	    //cout<<"n: "<<n<<endl;
	    sort(arr.begin(),arr.end(),comp);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n+1;j++)
	        {
	            if(j == 0)
	            dp[i][j] = 0;
	            else
	            dp[i][j] = 99999999;
	        }
	    }
	    dp[0][1] = arr[0].w;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<n+1;j++)
	        {
	            int temp = dp[i-1][j-1] + arr[i].w;
	            if(temp <= arr[i].s)
	            {
	                dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]+arr[i].w);
	            }
	            else
	            dp[i][j] = dp[i-1][j];
	        }
	    }
	    for(int i=0;i<n;i++) {
	    	for(int j=0;j<=n;j++)
	    		cout << dp[i][j] << " ";
	    	cout << endl;
	    }
	    int flag = 1;
	    
	    for(int j=n;j>=0;j--)
	    {
	        if(dp[n-1][j] != 99999999)
	        {
	        	//cout<<j<<endl;
	            cout<<j<<endl;
	            flag = 0;
	            break;
	        }
	    }
	    if(flag)
	    cout<<"0"<<endl;
	}
    return 0;
}
