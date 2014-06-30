#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>

typedef long long ll;
typedef vector<int> vi;
typedef vi vector_1d;
typedef vector<vi> vector_2d;
typedef vector<vector_2d> vector_3d;
typedef vi::iterator vit;
typedef vi::reverse_iterator rit;

#define sz(x) ((int)((x).size()))
#define _for(i,a,b) for( int i=a;i<b;++i)
#define AND &&
#define OR ||
#define all(c) (c).begin(),(c).end()
#define pb push_back





//-----------------------gobal declarations------------------------------------
#define MAX 1002
int arr[MAX][MAX];           // 1 based indexing
int height[MAX][MAX];         // height is upward max val at n , 1 at 1 
int width[MAX][MAX];          // width
int ans[MAX][MAX];            // final answer
int base_height[MAX][MAX];    //  store area at base and given height
int latest_width[MAX][MAX];   //  lw[i][j] = at base i , height j has max widht of lw[i][j]
//------------------------/global declarations--------------------------------


//----------------initialising height-----------------------------------------

void initialise_height(int r , int c )
{
	_for(i,1,c+1)
	{	if( arr[1][i] == 1 )
		 height[1][i] = 0 ;
		 
		 else 
		  height[1][i] = 1;
	}
	
	_for(i,1,c+1)
	{
		for(int j = 2; j<=r ; ++j )
		{
			if( arr[j][i] == 0 ) height[j][i] = 1+height[j-1][i];
			else height[j][i] = 0 ;
		}
	}
}
//---------------/initialising height-----------------------------------------
//--------------------------widht initialiser ----------------------------------
void initialise_width( int r , int c ) 
{

	vi left(c+1);
	vi right(c+1);
	
	stack< pair<int,int> > stackva;
	
	
	_for( j , 1, r+1)
	{
	
//---------FIRST THE LEFT ONE-----------------------------------
		_for(i,1,c+1)
		{
			if( stackva.empty() ) stackva.push( make_pair(height[j][i],i) );
			
			else if ( stackva.top().first <= height[j][i] ) stackva.push(make_pair(height[j][i],i));
			
			else
			{
				while( !stackva.empty() && stackva.top().first > height[j][i] )
				{
					left[stackva.top().second] = i-1;
					stackva.pop();
				}
				stackva.push( make_pair(height[j][i],i) );
			}
		}

		while( !stackva.empty() ) 
		{
			left[stackva.top().second] = c;
			stackva.pop();
		}
	

//--------NOW THE RIGHT ONE------------------------------
		for(int i=c;i>=1;--i)
		{
			if( stackva.empty() ) stackva.push( make_pair(height[j][i],i) );
			
			else if ( stackva.top().first <= height[j][i] ) stackva.push(make_pair(height[j][i],i));
			
			else
			{
				while( !stackva.empty() &&  stackva.top().first > height[j][i] )
				{
					right[stackva.top().second] = i+1;
					stackva.pop();
				}
				stackva.push( make_pair(height[j][i],i) );
			}
		}
		
		while( !stackva.empty() ) 
		{
			right[stackva.top().second] = 1;
			stackva.pop();
		}
		
		_for(i,1,c+1)
		{
			width[j][i] = left[i]-right[i]+1;
			latest_width[j][height[j][i]] = max( latest_width[j][height[j][i]] , width[j][i] );
		}
		
	}
}
//----------/widht initialiser ------------------------------------

//-----------preprocess---------------------------------------
void preprocess(int r )
{
	for( int r1= 1 ;r1 <= r; ++r1)
	ans[r1][r1] = base_height[r1][1];
	
	for( int r1= 1 ;r1 <= r; ++r1)
	{
		for(int r2=r1+1;r2<=r; ++r2)
		{
			ans[r1][r2] = max( base_height[r2][r2-r1+1], ans[r1][r2-1]  ) ; 
		}
	}

}
//-------------/preprocess-----------------------------------
//---------------base_height--------------------------------

void initialise_base_height(int r,int c)
{
	 _for(i,1,r+1)
		_for(j,1,r+1)
		{
			base_height[i][j] = max( latest_width[i][j]*j ,  base_height[i][j-1] ) ; 
		}
		
		
}
//---------------/base_height--------------------------------

//-----------------set_latest_width-------------------------------
void set_latest_width(int r, int c)
{
	_for(i,1,r+1)
	{
		for(int j = r-1 ; j >=1 ; --j ) 
		latest_width[i][j] = max( latest_width[i][j],latest_width[i][j+1] );
	}
	
}
//----------------------main---------------------------------
int main()
{	

	freopen("input.txt","r",stdin) ;
	freopen("output_meteorak_baba.txt","w",stdout) ;

int n , m , n_bad;
	scanf("%d%d%d",&m,&n,&n_bad) ;
	
	int x , y ;
	_for(i,0,n_bad)
		{
//				x = read_int();
//				y = read_int();

		scanf("%d%d",&x,&y) ;
			arr[x][y] = 1 ;
		}
		
	initialise_height(n,m);
	initialise_width(n,m);
	set_latest_width(n,m);     
	initialise_base_height(n,m);	
	preprocess(n);	

		
	int q;
	scanf("%d",&q);
	while(q--)
	{

		scanf("%d%d",&x,&y) ;
		//		x = read_int();
//		y = read_int();
		printf("%d\n",ans[x][y]);
	}
		
	return 0;
}
//-------------------/main-------------------------------
