#include<bits/stdc++.h>
using namespace std;

int func(int n)
{
    if(n <= 9 && n >= 1)
    return 0;
    else if(n <= 18 && n >= 9)
    return 1;
    else
    {
        return (1 - func(n/9));
    }
}
int main()
{
//    ifstream cin("input.txt");

  //  ofstream cout("output1.txt");
    int t;
//    scanf("%d",&t);
    cin >> t ;
    while(t--)
    {
        double n;
        char str[1000];
//        scanf("%lf%s",&n,str);
		cin >> n >> str;
        //while(scanf("%lf",&n) == 1)
        {
            int ans = 0;
            while(n > 18)
            {
                n = n/18.0;
            }
            if(n > 9 && n <= 18)
            {
                if(str[0] == 'D')
                {
                //	printf("Rachit\n");
                    cout<<"Rachit"<<endl;
                }
                else
                {
                //	printf("Deepak\n");
                    cout<<"Deepak"<<endl;
                }
            }
            else
           // printf("%s\n",str);
            cout<<str<<endl;
        }
    }
    return 0;
}

