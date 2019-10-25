#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void bill(){
      int n,d,b,c,q=0,sum=0,ch,y,y1,f=0,ot,otp,ph,p;
      float gst,bill;
      FILE *fp;
      char a[10],x[10],nam[20],nam1[20],nam2[20],x1[20];
     
              printf("\n\n\t\t\t\tyour final cart is\n");
              fp=fopen("samplecart.txt","r");
               while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n\t\t\t\t%d %s %d %d",d,a,b,c);
                   sum=sum+c;
                   q=q+b;
            } 
            fclose(fp);  
            gst=0.18*sum;
            bill=gst+sum;
            printf("\n\t\t\t\t-------------TOTAL AMOUNT:%d",sum);
            printf("\n\t\t\t\t-----------TOTAL QUANTITY:%d",q);
            printf("\n\t\t\t\t----------------------GST:%2.f",gst);
            printf("\n\t\t\t\t-------YOUR FINAL BILL IS:%2.f\n",bill);
            printf("\n\t\t\t\tEnter your name:");
            scanf("%s",nam);
            printf("\n\t\t\t\tEnter your contact number");
            scanf("%d",&ph);
            printf("\n\t\t\t\tSELECT YOUR PAYMENT MODE:\n\t\t\t\t\t1.Debit card\n\t\t\t\t\t2.cash");
            scanf("%d",&ch);
            if(ch==2)
                printf("\n\t\t\t\tPay %f to the cashier",bill);
             else if(ch==1)
                 {
                    printf("\n\t\t\t\tEnter card number");
                    scanf("%s",x);
                    printf("\n\t\t\t\tEnter cvv:");
                    scanf("%d",&y);
                    printf("\n\t\t\t\tEnter card holder name: ");
                    scanf("%s",nam2);
                    p=ph%1000;
                    fp=fopen("payment.txt","r");
                     while(fscanf(fp,"%s %d %s %d\n",x1,&y1,nam1,&otp)!=EOF){
                     
                                  if(strcmp(x,x1)==0&& y==y1 && strcmp(nam,nam1)==0)
                                        {   
                                           printf("\n\t\t\t\tEnter the OTP sent to your mobile number *******%d",p);
                                           scanf("%d",&ot);
                                           if(ot==otp){
                                              printf("\n\n\t\t\t\tVERIFIED SUCCESSFULLY...\n\n\t\t\t\tPayment successfull..");
                                              f=1;
                                              }
                                            else
                                              printf("\n\n\t\t\t\tINVALID OTP");
                                           
                                          }
                     }
                     if(f==0)
                        printf("\n\n\t\t\t\tInvalid card number or cvv\n\n\t\t\t\tPay %.2f to the cashier",bill);
                 }
                 printf("\n\n\t\t\t\t%s Thank you for visiting our store",nam);
                 fclose(fp);
        
  }
