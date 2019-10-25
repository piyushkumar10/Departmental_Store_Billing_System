#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "adminfunc.h"
void admin()
{
	int c,r,args,flag=0;
	char choice;
	do{
	printf("\n\n************ ADMIN MENU ***********");
	printf("\n\t1. Add Items \n\t2. Delete Items\n\t3. Restock items\n\t4. Change price\n\t5. Log Out");
	printf("\nEnter your choice : ");
	r=scanf("%d",&c);
	printf("\n");
	if(r==1 && c>=1 && c<=5)
	{
		switch(c)
		{
			case 1: add1();break;
			case 2: del1();break;
			case 3: restock();break;
			case 4: price();break;
			case 5: printf("\nLogged Out");exit(0);
		}
	}
	else if(r!=1)
	printf("\nInvalid Input.Please Input again. ");
	printf("\nDo you want to continue to the Admin Menu? Y/N : ");

		fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y' || choice=='Y' || choice=='n' || choice=='N')
        flag=1;
       	if((choice!='y' || choice!='Y') || (choice!='n' || choice!='N'))
		   {
		   while(flag!=1)
       	{ fflush(stdin);
       		printf("\nInvalid Input.Please Input again");
       		printf("\nDo you want to continue to the Admin Menu? Y/N : ");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y' || choice=='Y' || choice=='n' || choice=='N')
        {flag=1;break;
		}
		   }
		}
	
	}while(choice=='Y' || choice=='y');
	
}

