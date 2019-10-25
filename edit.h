#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void add(int sl){
 int n,d,b,c1,c,cart,qan,edi,cho,ed,p,fl=1;
      FILE *fp,*fp1;
      char a[10];
      
      printf("\n\t\t\t\tEnter the category you want to purchase again:\n\t\t\t\t\t1-Electronics\n\t\t\t\t\t2-Sports\n\t\t\t\t\t3-Eatables\n\t\t\t\t\t4-EXIT=");
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
             printf("\t\t\t\ts.no---item---qantity--price");
            while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n\t\t\t\t%d %s %d %d",d,a,b,c);
            }
            	do{
              		printf("\n\t\t\t\tEnter the item to add in to the cart");
            		scanf("%d",&cart);
            		printf("\t\t\t\tEnter the quantity :");
            		scanf("%d",&qan);
            		fp1=fopen("samplecart.txt","a");
            		rewind(fp);
            		fl=1;
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
       }
struct cusmod
{
    char name[25];
    int p;
    int s;
    int e;
}stu;

void append(int r,int q){

   FILE *fh,*fh1,*fh2,*fp;
fh=fopen("samplecart.txt","r");
fh1=fopen("temp.txt","w");
fh2=fopen("bct.txt","r");

    int n,y;
    int tee;
    n=fscanf(fh,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p);
    do
    {if(stu.s!=r)
         {fprintf(fh1,"%d %s %d %d\n",stu.s,stu.name,stu.e,stu.p);

          n=fscanf(fh,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p);}
        else
            { tee=stu.p/stu.e;
                fprintf(fh1,"%d %s %d %d\n",stu.s,stu.name,q,q*tee);
               n=fscanf(fh,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p);

                }


    }while(n!=EOF );
    fclose(fh);
    fclose(fh1);
    remove("samplecart.txt");
    rename("temp.txt","samplecart.txt");
    fp=fopen("samplecart.txt","r");
    while(fscanf(fp,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p)!=EOF)
    {
        printf("\t\t\t\t%d %s %d %d\n",stu.s,stu.name,stu.e,stu.p);
    }
    fclose(fp);
}
void edit()
{ int q,r;
       printf("\t\t\t\tEnter the s.no of the item to be modified ");
        fflush(stdin);
        scanf("%d",&r);
        printf("\t\t\t\tEnter the updated quantity: ");
        scanf("%d",&q);
        append(r,q);
        fflush(stdin);
    
}
