#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
#define max 2
struct person *insert(struct person *start,int rollnumber,float point);
struct upgrade *insertend(struct upgrade *st,int x,int y,float z);
void upgradesession(struct upgrade *up);
struct upgrade *selection(struct upgrade *start);
void insert_and_delete(struct person *ad,struct person *ac,struct upgrade *k);
void display(struct person *ac);
void display1(struct upgrade *up);
struct person
{
    int roll;
    float pointer;
    struct person *link;
};
struct upgrade
{
    int branch;
    int roll1;
    float pointer1;
    struct upgrade *right;
    struct choice *extra;
};
struct choice
{
    int a;
    struct choice *extra;
};
struct person *it=NULL,*cs=NULL,*mech=NULL,*ece=NULL,*elec=NULL,*civil=NULL;
struct upgrade *up=NULL;
int count[6];
/*for(f=0;f<6;f++)
        {
            count[f]=0;
        }
        */
main()
{
    int i,n,b,f,rollnumber;
    float point;
    for(f=0;f<6;f++)
    {
            count[f]=0;
    }
    for(i=0;i<max;i++)
    {

        printf("enter roll\npointer\n");
        scanf("%d%f",&rollnumber,&point);
        printf("1.computer\n2.ece\n3.mechanical\n4.it\n5.electrical\n6.civil\n");
        printf("enter branch");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                    cs=insert(cs,rollnumber,point);
                    count[0]++;
                    break;
            case 2:
                    ece=insert(ece,rollnumber,point);
                    count[1]++;
                    break;
            case 3:
                    mech=insert(mech,rollnumber,point);
                    count[2]++;
                    break;
            case 4:
                    it=insert(it,rollnumber,point);
                    count[3]++;
                    break;
            case 5:
                    elec=insert(elec,rollnumber,point);
                    count[4]++;
                    break;
            case 6:
                    civil=insert(civil,rollnumber,point);
                    count[5]++;
                    break;

        }
        printf("you want to upgrade\n1.yes\n2.no");
        scanf("%d",&b);
        if(b==1)
        {
            up=insertend(up,n,rollnumber,point);
        }

    }
    if(up)
    selection(up);
    printf("\n\n");/*
    struct upgrade *temp;
		while(up)
		{
			
			temp=up;
			printf("\n%d ",up->roll1);
			struct choice *tp=temp->extra;
			while(tp)
			{
				printf("%d",tp->a);
				tp=tp->extra;
			}
			up=up->right;
		}
*/
    printf("computers students:\n");
    display(cs);
    printf("electronics students:\n");
    display(ece);
    printf("mechanical students:\n");
    display(mech);
    printf("it students:\n");
    display(it);
    printf("electrical students:\n");
    display(elec);
    printf("civil students:\n");
    display(civil);
    if(up)
    {
		printf("shivam");
        upgradesession(up);
    }
    else
    printf("jindal");
    printf("computers students after upgradation:\n");
    display(cs);
    printf("electronics students after upgradation:\n");
    display(ece);
    printf("mechanical students after upgradation:\n");
    display(mech);
    printf("it students after upgradation:\n");
    display(it);
    printf("electrical students after upgradation:\n");
    display(elec);
    printf("civil students after upgradation:\n");
    display(civil);
    getch();
}
struct person *insert(struct person *start,int rollnumber,float point)
{
   struct person *p,*tmp;
   tmp=(struct person *)malloc(sizeof(struct person));
   tmp->roll=rollnumber;
   tmp->pointer=point;
   tmp->link=NULL;
   if(start==NULL)
   {
        start=tmp;
   }
    else
    {
        p=start;
        while(p->link)
        {
            p=p->link;
        }
        p->link=tmp;
    }
    return start;
}
struct upgrade *insertend(struct upgrade *st,int x,int y,float z)
{
    int j,w;
    int k=0;
    struct upgrade *temp,*q;
    struct choice *lu,*lp;
    temp=(struct upgrade *)malloc(sizeof(struct upgrade));
    temp->pointer1=z;
    temp->branch=x;
    temp->roll1=y;
    temp->right=NULL;
    temp->extra=NULL;
    printf("enter no. of choices to fill");
    scanf("%d",&j);
    printf("1.computer\n2.ece\n3.mechanical\n4.it\n5.electrical\n6.civilfor upgrade\n");
    while(k<j)
    {
        printf("enter the %d choice\n",k+1);
        scanf("%d",&w);
        lu=(struct choice *)malloc(sizeof(struct choice));
        lu->a=w;
        lu->extra=NULL;
        if(k==0)
        {
          temp->extra=lu;

        }
        else
        {
            lp=temp->extra;
            while(lp->extra!=NULL)
            {
                lp=lp->extra;
            }
            lp->extra=lu;
        }
        k++;
    }
    if(st==NULL)
    {
        st=temp;
    }
    else
    {
        q=st;
        while(q->right!=NULL)
        {
            q=q->right;
        }
        q->right=temp;
    }
    return st;

}
void upgradesession(struct upgrade *up)
{
    int g,az;
    struct upgrade *k=NULL;
    struct choice *c=NULL;
    up=selection(up);
    printf("after selection sort is\n");
    display1(up);
    while(up)
    {
        k=up;
        up=up->right;
        c=k->extra;
        printf("upgrade choice is \n%d\n",c->a);
        while(c!=NULL)
        {
            g=c->a;
            printf("upgrade choice is \n%d\n",g);
            if((count[g-1])<1)
            {
                count[g-1]++;
                printf("no. of students in upgrade branch is \n%d\n",count[g-1]);
                printf("k branch is \n%d\n",k->branch);

printf("shivam0");
                if(k->branch==1)
                {
                    if(g==2)
                    {
                        insert_and_delete(cs,ece,k);
                    }
                    if(g==3)
                    {
                        insert_and_delete(cs,mech,k);
                    }
                    if(g==4)
                    {
                        insert_and_delete(cs,it,k);
                    }
                    if(g==5)
                    {
                        insert_and_delete(cs,elec,k);
                    }
                    if(g==6)
                    {
                        insert_and_delete(cs,civil,k);
                    }
                }

                if(k->branch==2)
                {
                    if(g==1)
                    {
                        insert_and_delete(ece,cs,k);
                    }
                    if(g==3)
                    {
                        insert_and_delete(ece,mech,k);
                    }
                    if(g==4)
                    {
                        insert_and_delete(ece,it,k);
                    }
                    if(g==5)
                    {
                        insert_and_delete(ece,elec,k);
                    }
                    if(g==6)
                    {
                        insert_and_delete(ece,civil,k);
                    }

                }
                if(k->branch==3)
                {
                    if(g==1)
                    {
                        insert_and_delete(mech,cs,k);
                    }
                    if(g==2)
                    {
                        insert_and_delete(mech,ece,k);
                    }

                    if(g==4)
                    {
                        insert_and_delete(mech,it,k);
                    }
                    if(g==5)
                    {
                        insert_and_delete(mech,elec,k);
                    }
                    if(g==6)
                    {
                        insert_and_delete(mech,civil,k);
                    }

                }
                if(k->branch==4)
                {
                    if(g==1)
                    {
                        insert_and_delete(it,cs,k);
                    }
                    if(g==2)
                    {
                        insert_and_delete(it,ece,k);
                    }
                    if(g==3)
                    {
                        insert_and_delete(it,mech,k);
                    }
                    if(g==5)
                    {
                        insert_and_delete(it,elec,k);
                    }
                    if(g==6)
                    {
                        insert_and_delete(it,civil,k);
                    }
                }
                if(k->branch==5)
                {
                    if(g==1)
                    {
                        insert_and_delete(elec,cs,k);
                    }
                    if(g==2)
                    {
                        insert_and_delete(elec,ece,k);
                    }
                    if(g==3)
                    {
                        insert_and_delete(elec,mech,k);
                    }
                    if(g==4)
                    {
                        insert_and_delete(elec,it,k);
                    }

                    if(g==6)
                    {
                        insert_and_delete(elec,civil,k);
                    }
                }
                if(k->branch==6)
                {
                    if(g==1)
                    {
                        insert_and_delete(civil,cs,k);
                    }
                    if(g==2)
                    {
                        insert_and_delete(civil,ece,k);
                    }
                    if(g==3)
                    {
                        insert_and_delete(civil,mech,k);
                    }
                    if(g==4)
                    {
                        insert_and_delete(civil,it,k);
                    }
                    if(g==5)
                    {
                        insert_and_delete(civil,elec,k);
                    }

                }

                az=k->branch;
                az=az-1;
                count[az]--;
                break;
            }
            else
            {
                c=c->extra;
            }
        }
  /*     qw=k;
        v=qw->extra;
        while(v!=NULL)
        {
            l=v;
            v=v->extra;
            free(l);
        }
            free(qw);
            display1(up);

    }


*/
}
}
struct upgrade *selection(struct upgrade *start)
{
			bool flag=0;
			struct choice *ptr,*ptr1;
			struct upgrade *a,*b,*temp,temp1;
			for(a=start;a;a=a->right)
			{
				int r=a->pointer1;
				for(b=a->right;b;b=b->right)
				{
					if(b->pointer1>r)
					{
						flag=1;
						temp=b;
						r=b->pointer1;
					}
				}
				if(flag)
				{
						temp1=*a;
						ptr=a->extra;
     					a->roll1=temp->roll1;
     					a->pointer1=temp->pointer1;
						a->extra=temp->extra;
						temp->roll1=temp1.roll1;
     					temp->pointer1=temp1.pointer1;
     					temp->extra=ptr;
     					flag=0;
				}
			}
			return start;
}
void display(struct person *ac)
{
    struct person *j;
    j=ac;
    while(j)
    {
        printf("\n%d\n%f\n",j->roll,j->pointer);
        j=j->link;
    }
}

void display1(struct upgrade *up)
{
    struct upgrade *k;
    struct choice *m;
    k=up;
    while(k!=NULL)
    {
        printf("branch of student is \n%d roll no. is%d pointer is %f\n",k->branch,k->roll1,k->pointer1);
        m=k->extra;
        while(m!=NULL)
        {
            printf(" upgrade choices is%d\n",m->a);
            m=m->extra;
        }
        k=k->right;
    }

}


//-------ERROR PRONE FUNCTION---------------------------------------------


void insert_and_delete(struct person *ad,struct person *ac,struct upgrade *k)
{
    struct person *ab,*am,*tmp,*ak;
    printf("jaha pe upgrade karana hai\n");
    display(ac);
    printf("jaha se upgrade hua hai\n");
    display(ad);
    tmp=(struct person *)malloc(sizeof(struct person));
    printf("k ka roll no. is %d\n",k->roll1);
    
    //=======ERROR===============
    if(k->roll1==ad->roll)
    {
		printf("k");
        am=ad;
        ad=ad->link;
    }
    else
    {
		printf("!k");
        ab=ad;
        	printf("!k");

        while(k->roll1!=ab->link->roll)
        {	printf("!k");

            ab=ab->link;
        }
	printf("!k");
           am=ab->link;
        ab->link=ab->link->link;
	printf("!k");

    }
    printf("hi...");

    tmp->roll=am->roll;
    tmp->pointer=am->pointer;
    tmp->link=NULL;
    am->link=NULL;
    printf("\n%d\n%f\n",tmp->roll,tmp->pointer);
    if(ac==NULL)
    {
       ac=tmp;
    }
    else
    {
        ak=ac;
        while(ak->link!=NULL)
        {
            ak=ak->link;
        }
        ak->link=tmp;
    }
    printf("ece ka link\n%d\n%f",ece->roll,ece->pointer);
    display(ac);
    free(am);
    free(ak);
    free(ab);
}
//-----------------------------------------------------------------------------------------
