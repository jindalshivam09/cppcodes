#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0
#define all(C) (C).begin() , (C).end()
#define tr(C , it) for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define present(C , key) ((C).find(key) != (C).end())
#define cpresent(C , key) (find(all(C) , key) != (C).end())
#define sz(a) int((a).size())
#define pb push_back
#define MOD 1000000007


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int , int> PI;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output2.txt","w",stdout) ;

	int _T;
	scanf("%d" , &_T);
	
	int N;
	int i , j , k , cons , sno;
	vector<string> orig(10) , broken , inpt;
	string temps;
	
	orig[0] = "1111110";
	orig[1] = "0110000";
	orig[2] = "1101101";
	orig[3] = "1111001";
	orig[4] = "0110011";
	orig[5] = "1011011";
	orig[6] = "1011111";
	orig[7] = "1110000";
	orig[8] = "1111111";
	orig[9] = "1111011";

	
	int working[7];
	set<string> pa;
	for(int _a = 1 ; _a <= _T ; _a++)
	{
		printf("Case #%d: " , _a);
		scanf("%d" , &N);
		inpt.clear();
		memset(working , 0 , sizeof(working));
		for(i=0 ; i<N ; i++)
		{
			cin >> temps;
			inpt.pb(temps);
			for(j=0 ; j<7 ; j++)
			{
				if(temps[j] == '1')
					working[j] = 1;
			}
		}
		pa.clear();
		for(i=0 ; i<(1 << 7) ; i++)
		{
			broken = orig;
			cons = 1;
			for(j=0 ; j<7 ; j++)
			{
				if( (i & (1 << j)) && working[j])
				{
					cons = 0;
					break;
				}
				if(i & (1 << j))
				{
					for(k=0 ; k<10 ; k++)
					{
						broken[k][j] = '0';
					}
				}
				
			}
			if(!cons)
				continue;
				
			for(j=0 ; j<10 ; j++)
			{
				cons = 1;
				sno = j;
				for(k=0 ; k<N ; k++)
				{
					if(inpt[k] != broken[sno])
					{
						cons = 0;
						break;
					}
					sno = (sno - 1 + 10)%10;
				}
				
				if(cons)
				{
					pa.insert(broken[sno]);
				}
			}
		}
		if(pa.size() == 1)
		{
			cout << *(pa.begin()) << endl;
		}
		else
		{
			//printf("pa.size() = %d\t" , pa.size());
			if(DEBUG)
			{
				tr(pa , it)
				{
					cout << *(it) << " ";
				}
			}
			printf("ERROR!\n");
		}
	}
	return 0;
}
