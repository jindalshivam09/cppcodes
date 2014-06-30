//--------------MATRIX---------------------------------

#include<iostream>
#define MAX 10
#define ERROR -9999
using namespace std;

class matrix
{
	int MATRIX[MAX][MAX];
	int row,col;
	public:
		matrix(int array[][MAX]=NULL,int n=0,int m=0)
		{
				row=n;
				col=m;
				for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
				MATRIX[i][j]=array[i][j];
		}
		void init(int array[][MAX],int n=0,int m=0)
		{
                row=n;
				col=m;
				for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
				MATRIX[i][j]=array[i][j];
		}
		int sumTriangularMatrixUpper()
		{
				if(row!=col)                      // this operations are only allowed for square matrix
				{
						cerr<<"Error: Matrix must be a square matrix";
						return ERROR;
				}
				else
				{
						int sum=0;
						for(int i=0;i<row;i++)
						for(int j=i;j<col;j++)
						sum+=MATRIX[i][j];
						return sum;
				}
		}
		int sumTriangularMatrixLower()
		{
                if(row!=col)                        // this operations are only allowed for square matrix
				{
						cerr<<"Error: Matrix must be a square matrix";
						return ERROR;
				}
				else
				{
						int sum=0;
						for(int i=0;i<row;i++)
						for(int j=0;j<=i;j++)
						sum+=MATRIX[i][j];
						return sum;
				}

		}
		int sumDiagonalUpper()
		{
                if(row!=col)                          // this operations are only allowed for square matrix
				{
						cerr<<"Error: Matrix must be a square matrix";
						return ERROR;
				}
				else
				{
						int sum=0;
						for(int i=0;i<row;i++)
						sum+=MATRIX[i][i];
						return sum;
				}
		}
		int sumDiagonalLower()
		{
				if(row!=col)                 // this operations are only allowed for square matrix
				{
						cerr<<"Error: Matrix must be a square matrix";
						return ERROR;
				}
				else
				{
						int sum=0;
						for(int i=0;i<row;i++)
						sum+=MATRIX[row-1-i][i];
						return sum;
				}
		}

};
main()
{
			int n,m;
			int arr[MAX][MAX];
			
			cout<<"Enter the size of the matrix( n X m ): ";
			cin>>n>>m;
			cout<<"Enter elements: \n";
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			cin>>arr[i][j];
			matrix mat(arr,n,m);

			int sum=mat.sumTriangularMatrixUpper();
			if(sum!=ERROR)
			cout<<"Sum of upper triangular matrix="<<sum<<endl;
			
			sum=mat.sumTriangularMatrixLower();
			if(sum!=ERROR)
			cout<<"Sum of lower triangular matrix="<<sum<<endl;

			sum=mat.sumDiagonalUpper();
			if(sum!=ERROR)
			cout<<"Sum of upper diagonal="<<sum<<endl;

			sum=mat.sumDiagonalLower();
			if(sum!=ERROR)
			cout<<"Sum of lower diagonal="<<sum<<endl;

			cin.get();
			cin.get();
}
