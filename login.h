#include<stdio.h>
#include<string.h>
#include "cos.h"
#include "admin.h"
void login(){
    char a[50],x[50],y[50],y1[50],z[50],s[50];
    int test,g=0,f=0;
    FILE *fp;
    printf("\n\t\t\t\t===========WELCOME TO BOOMERANG DEPARTMANTAL STORE==============\n");
    printf("\n\t\t\t\t=========================Login==================================");
    printf("\n\n\t\t\t\tEnter the mail id : ");
    scanf("%s",a);
    fp= fopen("mailid.txt", "r");
   while (fscanf(fp,"%s",x) != EOF) {
    //printf("%s",x);
   // printf("\n%s",a);
    test = strcmp(a,x);
    if(test==0)
         {
            printf("\n\t\t\t\t~~~~~~~YOU ARE AN ADMIN");
            printf("\n\t\t\t\t~~~~~~~~~~~~~~PASSWORD : ");
            scanf("%s",y);
            rewind(fp);
            g=1;
                   while(fscanf(fp,"%s %s %s\n",z,y1,s)!= EOF){
                        if(strcmp(y,y1)==0 && strcmp(z,a)==0){
                            printf("\n\t\t\t\t                 ACCESS GRANTED\n\t\t\t\t                  Hi %s\n",s);
                             admin();
                            f=1;
                            }
                    }  
                  if(f==0)
                  printf("\t\t\t\t               ACCESS DENIED\n");  
                  break;
         
      }
      }
      if(g==0)
        {
         printf("\n\t\t\t\tYOU ARE A CUSTOMER\n");
        costumer();
        }
    fclose(fp);
}
