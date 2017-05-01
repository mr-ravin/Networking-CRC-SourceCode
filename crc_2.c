#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int i,datalen,divlen,res1[7],j,fin[7],net[7],dmp[1],rem[7];
int comp(int i,int j)
{
    if(i==j){return 0;}
    else{
            return 1;
    }
}

void crc(int data[],int div[])
{
    int p;
for(i=0;i<datalen-divlen+1;i++)
{
   if(i==0)
   {
       for(p=0;p<divlen;p++)
       {
           res1[p]=data[p];
       }
   }
   if(res1[0]!=0)
    {
        for(p=0;p<divlen;p++)
        {
            net[p]=comp(res1[p],div[p]);
        }
   }
   if(res1[0]==0)
   {
        for(p=0;p<divlen;p++)
        {
            net[p]=comp(res1[p],dmp[0]);
        }
   }
   fin[i]=res1[0];
   for(p=0;p<divlen-1;p++)
   {
       rem[p]=net[p+1];
   }
   if(i!=datalen+divlen-2)
   {
       for(p=0;p<divlen-1;p++)
        {
            res1[p]=rem[p];
        }
        res1[divlen-1]=data[divlen+i];
   }
}
   printf("\nquotient is :\n");
   for(p=0;p<datalen-divlen+1;p++)
   {
      printf("%d",fin[p]);
   }
   printf("\nThe remainder is :\n");
   for(p=0;p<divlen-1;p++)
   {
      printf("%d",rem[p]);
   }
}
void main()
{   int data[21],datatemp[30],e,div[7],get=0,templen;
    dmp[0]=0;
    printf("Enter length of Data: \n");
    scanf("%d",&datalen);
    templen=datalen;
    for(e=0;e<templen;e++)
    {
        scanf("%d",&data[e]);
        datatemp[e]=data[e];
    }
    printf("\nEnter divisor length :\n");
    scanf("%d",&divlen);
    datalen+=divlen-1;
    for(e=0;e<divlen;e++)
    {
        scanf("%d",&div[e]);
    }
    for(e=0;e<divlen-1;e++)
    {
        datatemp[templen+e]=0;
    }
    printf("\nCRC GENERATOR\n");
    crc(datatemp,div);
    for(e=0;e<divlen-1;e++)
    {
        datatemp[templen+e]=rem[e];
    }
    printf("\nCRC CHECKER\n");
    crc(datatemp,div);
    for(e=0;e<divlen-1;e++)
    {
        get+=rem[e];
    }
    if(get==0)
    {
        printf("\nData is Correct !!!\n");
    }
    else{
        printf("\nError in Data\n");
    }
    getch();
}

