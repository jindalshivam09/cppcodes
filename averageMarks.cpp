#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void createFile(fstream & file)
{
        srand((unsigned)time(NULL));
		int n=rand()%100;
		cout<<"total subjects: "<<n<<endl;
		for(int i=0;i<n;i++)
		file<<rand()%100<<" ";
}
main()
{
	fstream file;
	file.open("Marks",ios::out|ios::in);
	if(!file)
	perror("");
	/*if(!file)
	{
		throw(5);
	};
	catch(int)
	{
		cout<<"unable to open file";
	}*/
	
	createFile(file);
	int max=-1;
	float avg=0;
	int marks;
	int count=0;
	ios_base::iostate s=file.rdstate();
	while(!(s&ios_base::eofbit))
	{
           file>>marks;
			//cout<<"shivam";
			//file>>marks;
			avg+=marks;
			count++;
			if(max<marks)
			max=marks;
			s=file.rdstate();
	}
	avg=avg/count;
	cout<<fixed<<"Avg: "<<avg;
	cout<<endl<<"Max marks is: "<<max;
	cin.get();
}
