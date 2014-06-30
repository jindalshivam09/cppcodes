#include<stdio.h>
#include<conio.h>
main()
{
        int t;
        float withdraw;
        float balance;
        float diff;
            scanf("%f%f",&withdraw,&balance);
            diff=withdraw-balance;
            int w=withdraw;
          //  printf(" %f ",diff);
            if((diff>-0.5)||(w%5)||(withdraw==balance))
            printf("%0.2f",balance);
            else
            printf("%0.2f",balance-withdraw-0.5);
            printf("\n");
            getch();
            return 0;

}
