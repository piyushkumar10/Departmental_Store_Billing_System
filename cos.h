#include<stdio.h>
#include<stdlib.h>
#include "edit.h"
#include "bill.h"
  void costumer(){
      int n,d,b,c1,c,cart,qan,edi,cho,ed,p,sl=1,fl=1;
      FILE *fp,*fp1;
      char a[10];
      
      printf("\n\t\t\t\t===================WELCOME TO OUR STORE===========================\n");
     
      fp1=fopen("samplecart.txt","w");
            	fclose(fp1);
      do{
      
      printf("\n\t\t\t\tEnter the category you want to purchase:\n\t\t\t\t\t1-Electronics\n\t\t\t\t\t2-Sports\n\t\t\t\t\t3-Eatables\n\t\t\t\t\t4-EXIT");
       scanf("%d",&n);
       if(n==4){
         printf("\t\t\t\tThank you for visiting our departmental store");
         exit(0);
         }
      switch(n){
           case 1:fp=fopen("electronics.txt","r");
                break;
           case 2:fp=fopen("sports.txt","r");
                break;
           case 3:fp=fopen("food.txt","r");
                break;
           default:printf("Invalid input");
              
      }
             printf("\n\t\t\t\ts.no---item---qantity--price\n");
            while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n\t\t\t\t%d %s %d %d",d,a,b,c);
            }
            	do{
              		printf("\n\n\t\t\t\tEnter the item to add in to the cart");
            		scanf("%d",&cart);
            		
            		printf("\t\t\t\tEnter the quantity :");
            		scanf("%d",&qan);
            		
            		fp1=fopen("samplecart.txt","a");
            		rewind(fp);
            	while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
            	
                   if(cart==d){
                   fl=0;
                    if(qan<=b){
                fprintf(fp1,"%d %s %d %d\n",sl,a,qan,qan*c);
                printf("\n\t\t\t\tyour %s is added to your cart",a);
                sl++;
                fclose(fp1);
                }
                   else
                     printf("\n\t\t\t\tOut of stock....only %d is remaning",b);
             
            }
            }
            if(fl==1)
               printf("\n\t\t\t\tINVALID ITEM NO PLEASE ENTER VALID ITEM NO");
            printf("\n\t\t\t\tDo want to continue in this catagory[1/0]");
            scanf("%d",&c1);
            }while(c1==1);
             printf("\n\t\t\t\tEnter the choice\n\t\t\t\t\t1-continue shopping\n\t\t\t\t\t2-check out");
             scanf("%d",&p);
              fclose(fp);
           }while(p==1);
           if(p==2)
              printf("\t\t\t\tyour cart is\n");
              fp=fopen("samplecart.txt","r");
               while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n\t\t\t\t%d %s %d %d",d,a,b,c);
            }   
            fclose(fp);
            printf("\n\t\t\t\tDo you want to edit your cart[1/0]");
            scanf("%d",&ed);
             if(ed==1)
                 {do{
                  printf("\n\t\t\t\t\t1-Edit quantity\n\t\t\t\t\t2-Add items");
                     scanf("%d",&edi);
                     if(edi==1)
                         edit();
                        else if(edi==2)
                          add(sl);
                  
                  printf("\n\t\t\t\tDo you want to continue editing your cart[1/0]");
                  scanf("%d",&cho);
              }while(cho==1);
              }   
                  printf("\n\n\t\t\t\t=======================BILLING=================================");
                  bill();
  }
