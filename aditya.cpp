#include<iostream>

using namespace std;

int t[500][500],b[500][500],l[500][500],r[500][500];

int min_cal(int &t,int &b,int &l,int &r) { 
	int min; 
	if(t>=b) 	min=b; 
	else 		min=t; 
	if(min>r) 	min=r; 
	if(min>l) 	min=l; 
	return min; 
}

int primes[95]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};

int get_monsters(int &n) { 
	int l=0; 
	int r=94; 
	int mid; 
	if(n<2) return 0; 
	while(l<r) { 
		mid =(l+r)/2; 
		if(n == primes[mid]) 		return mid+1; 
		else if( n > primes[mid]) 	l=mid+1; 
		else 						r=mid-1; 
	}
	return l+1; 
}

void cal_top_bottom(char a[][500],int row,int col) { 
	/*for(int i=0;i<col;i++) { t[0][i]=0; b[row-1][i]=0; }*/ 
	for(int i=1;i<row;i++) { 
		for(int j=0;j<col;j++) { 
			if(a[i-1][j]=='^' && a[i][j]=='^') 				t[i][j]=t[i-1][j]+1; 
			else 											t[i][j]=0; 
			if(a[row-i][j]=='^' && a[row-i-1][j]=='^') 		b[row-i-1][j]=b[row-i][j]+1; 
			else 											b[row-i-1][j]=0; //cout<<"top "<<i<<" "<<j<<" "<<t[i][j]<<endl; //cout<<"Bottom "<<row-1-i<<" "<<j<<" "<<b[row-1-i][j]<<endl; //getch(); 
		}
	} 
}

void cal_left_right(char a[][500],int row,int col) { 
	/*for(int i=0;i<row;i++) { l[i][0]=0; r[i][col-1]=0; }*/ 
	for(int j=0;j<row;j++) { 
		for(int i=1;i<col;i++) { 
			if(a[j][i-1]=='^' && a[j][i]=='^') 				l[j][i]=l[j][i-1]+1; 
			else 											l[j][i]=0; 
			if(a[j][col-i]=='^' && a[j][col-i-1]=='^') 		r[j][col-i-1]=r[j][col-i]+1; 
			else 											r[j][col-i-1]=0; // cout<<"left "<<j<<" "<<i<<" "<<l[j][i]<<endl; // cout<<"right "<<j<<" "<<col-i-1<<" "<<r[j][col-i-1]<<endl; //getch(); 
		} 
	} 
}

int main() { 

	 int row,col,min,cases; 
	 long count; 
	 char a[500][500]; 
	 cin>>cases; 
	 while(cases) { 
	 	cin>>row>>col; 
		count=0; 
		for(int i=0;i<row;i++) { 
			for(int j=0;j<col;j++) { 
				cin>>a[i][j]; 
			}
		 } 
		 if(row>=5 && col>=5) { 	
		 	cal_top_bottom(a,row,col); 
			cal_left_right(a,row,col); 
			count=0; 
			for(int i=2;i<row-2;i++) { 
				for(int j=2;j<col-2;j++) { 
					min = min_cal(t[i][j],b[i][j],l[i][j],r[i][j]); 
					if(min>=2) 		count+=get_monsters(min); 
				}
			}
		} 
		cout<<count<<"\n"; 
		cases--; 
	}
	return 0;
}
