#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10000000


	int ballon_req[MAX];
	int distance_A[MAX];
	int distance_B[MAX];
	int aux[MAX];   // auxilliary array for sorting
	int saving[MAX];   // how much we save on selecting A 


bool cmp (int a,int b) 
{

	return saving[a]<saving[b];
}

	
int main()
{
	
	int n_teams,nA,nB,total_ballon=0,total_distance=0,i,j,k;

	cin>>n_teams>>nA>>nB;
	
	while(n_teams) {
		
		for(i=0;i<n_teams;++i)
		{
			
			cin>>ballon_req[i]>>distance_A[i]>>distance_B[i];
		//	total_ballon += ballon_req[i];
			saving[i]=distance_B[i]-distance_A[i];
			aux[i]=i;
		
		}
		
		i=0;
		j=n_teams-1;
		
		sort(aux,aux+n_teams,cmp);
		for (int i=0;i<n_teams;i++)
		cout << aux[i] << " ";
		
		while(i <= j )
		{
		
		if( abs(saving[aux[i]]) > abs(saving[aux[j]]))
			k=i++;
			
		else
			k=j--;
		
		if( saving[aux[k]] > 0 && nA >= ballon_req[aux[k]]  )
			{
			nA -= ballon_req[aux[k]];
		    total_distance +=  (distance_A[aux[k]] * ballon_req[aux[k]]);
			//cout<<endl<<ballon_req[aux[k]]<<" given to "<<aux[k]<<" from A and saved "<<saving[aux[k]];
			}
			
			else if( saving[aux[i]] <= 0 && nB >= ballon_req[aux[k]]  )
			{
			nB -= ballon_req[aux[k]];
		    total_distance +=  (distance_B[aux[k]] * ballon_req[aux[k]]);
			//cout<<endl<<ballon_req[aux[k]]<<" given to "<<aux[k]<<" from B and saved "<<saving[aux[k]];
			}		
			
		else if( saving[aux[k]] > 0 )
			{
			ballon_req[aux[k]] -= nA;
			total_distance += distance_A[aux[k] ]*nA;
			//cout<<endl<<nA<<" given to "<<aux[k]<<" from A and saved "<<saving[aux[k]];
			nA=0;
			
			
			total_distance += distance_B[aux[k]]*ballon_req[aux[k]];
			//cout<<endl<<ballon_req[aux[k]]<<" given to "<<aux[k]<<" from B and saved "<<saving[aux[k]];
			}
			
			else
				{
				ballon_req[aux[k]] -= nB;
				total_distance += distance_B[aux[k] ]*nB;
				//cout<<endl<<nA<<" given to "<<aux[k]<<" from B  and saved "<<saving[aux[k]];
				nA=0;
			
			
				total_distance += distance_A[aux[k]]*ballon_req[aux[k]];
				//cout<<endl<<ballon_req[aux[k]]<<" given to "<<aux[k]<<" from A and saved "<<saving[aux[k]];
				}
				
			
		}
			cout<<total_distance << endl;
			cin>>n_teams>>nA>>nB;
	}
	return 0;	
}

/*
3 15 35
10 20 10
10 10 30
10 40 10
*/
