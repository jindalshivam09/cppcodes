//        use of inheritence for getting details of engg student
//       given by::  JKCS


#include<iostream>
#include<cstring>
#include<conio.h>
#define BRANCH 10
#define MAX 10
#define SEM 3
#define mCode1 9000000000
#define mCode2 8000000000
#define mCode3 7000000000
using namespace std;
class student
{
	protected:
		unsigned int roll,dob[3];
		long long unsigned int phone;
		enum {day,month,year};
		char name[MAX],address[MAX];
    public:
		void print()
		{
				   cout<<"base  ";
		}
		void setValues(unsigned int r,char *nam,long long unsigned int ph,unsigned int *db,char *addr)
		{
				  roll=r;
				  for(int i=0;i<3;i++)
				  dob[i]=db[i];
				  phone=ph;
				  strcpy(name,nam);
				  strcpy(address,addr);
		}
		void dis()
		{
			cout<<"base "<<name<<" "<<address<<" "<<phone<<" "<<roll;
		}
};
class enggStudent : public student               // derived from class student
{
	private:
		char branch[BRANCH];
	    float sgpa[SEM];
		float cgpa;
	public:
		/*void print()
		{
			cout<<"derived ";
		}*/
		void setBranchDetails(char *brnch,float *sgp)
		{
				 strcpy(branch,brnch);
				 for(int i=0;i<SEM;i++)
				 sgpa[i]=sgp[i];
		}
		float calCGPA()
		{
			if(!strcmp(branch,"CSE")||!strcmp(branch,"IT"))
		    return ((0.5*sgpa[0])+(0.6*sgpa[1])+(0.7*sgpa[2]))/1.8;
			else
			return (sgpa[0]+sgpa[1]+sgpa[2])/3.0;
		}
		void setCGPA(float a)
		{
			cgpa=a;
		}
		void dispCGPA()
		{
			cout<<"CGPA: "<<cgpa<<endl;
		}
		void mobileOrLandline()
		{
			/*if(((phone&mCode1)==mCode1)||((phone&mCode2)==mCode2)||((phone&mCode3)==mCode3))
			cout<<"Mobile Number\n"<<(phone&mCode1);
			else
			cout<<"Landline\n"<<(phone&mCode1);*/
			int a=phone/(1000000000);
			if(a==9||a==8||a==7)
			cout<<"Mobile Number\n";
			else
			cout<<"Landline\n";
		}
		static int youngestStu(enggStudent *stud,int n);
		void display()
		{
                 cout<<"\nDetails of youngest student :\n";
				 cout<<"Roll No.:  ";
				 cout<<roll<<endl;
				 cout<<"Name: ";
				 cout<<name<<endl;
				 cout<<"Contact No. ";
				 cout<<phone<<endl;
				 cout<<"Date of Birth (ddmmyyyy): ";
				 cout<<dob[0]<<"-"<<dob[1]<<"-"<<dob[2]<<endl;
				 cout<<"Address: ";
				 cout<<address<<endl;
				 cout<<"Branch: ";
			     cout<<branch<<endl;
			     cout<<"SGPAs: ";
			     for(int i=0;i<SEM;i++)
			     cout<<sgpa[i]<<" ";
			     cout<<"\nCGPA: ";
			     cout<<cgpa<<endl;

		}
};
int enggStudent::youngestStu(enggStudent *stud,int n)
{
					int min[3];
					int young=0;
					memset(min,0,sizeof(min));
					for(int i=0;i<n;i++)
					{
									 if(min[2]<stud[i].dob[year])
									 {
											min[2]=stud[i].dob[year];
											young=i;
									 }
									 else if(min[2]==stud[i].dob[year])
									 {
                                             if(min[1]<stud[i].dob[month])
								         	 {
											           min[1]=stud[i].dob[month];
											           young=i;
									         }
									         else if(min[1]==stud[i].dob[month])
          									 {
                                                 if(min[0]<stud[i].dob[day])
			     					         	 {
											           min[0]=stud[i].dob[day];
											           young=i;
					    				         }
					    				         else if(min[0]==stud[i].dob[day])
					    				         {
														if((strcmp(stud[i].branch,stud[young].branch))<0)
														young=i;
					    				         }

        									 }
									 }


					}
					return young;
}

main()
{
    unsigned int r,db[3];
	long long unsigned int ph;
 	char nam[MAX],addr[MAX];
 	char brnch[BRANCH];
	float sgp[SEM];
	int n;
	float a;
	cout<<"Enter total number of the students: ";
	cin>>n;
	enggStudent stud[n];
	stud[1].print();
	for(int i=0;i<n;i++)
	{
            cout<<"\nEnter details of student "<<i+1<<":\n";
			cout<<"Roll No.:  ";
			cin>>r;
			cout<<"Name: ";
			cin>>nam;
			cout<<"Contact No. ";
			cin>>ph;
			cout<<"Date of Birth (ddmmyyyy): ";
			cin>>db[0]>>db[1]>>db[2];
			cout<<"Address: ";
			cin>>addr;
		    cout<<"Branch: ";
			cin>>brnch;
			cout<<"SGPAs: ";
			for(int j=0;j<SEM;j++)
			{
			       cin>>sgp[j];
			       if(sgp[j]>10||sgp[j]<0)
			       {
			              cout<<"Invalid input..\n Enter again: ";
			              j--;
				   }
			}
		         stud[i].setValues(r,nam,ph,db,addr);
		         stud[i].setBranchDetails(brnch,sgp);
		         a=stud[i].calCGPA();
		         stud[i].setCGPA(a);
		         stud[i].dispCGPA();
		         stud[i].mobileOrLandline();
	}
	student s;
	s=stud[0];           //only part which belongs to base class will get intialised
	s.dis();
	int y=enggStudent::youngestStu(stud,n);
	stud[y].display();
	getch();
}
