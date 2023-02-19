#include<stdio.h>
int main()
{
int bcktsize,pkt[25],i,j,iter,rate,line,total=0;
printf("Enter the bucket size and output rate (both in MB):");
scanf("%d%d",&bcktsize,&rate);
printf("Enter the number of input lines\n");
scanf("%d",&line);
printf("Enter the number of input packets rate of %d lines\n",line);
for(i=0;i<line;i++)
scanf("%d",&pkt[i]);
printf("Enter the number of iterations\n");
scanf("%d",&iter);
for(i=0;i<iter;i++)
{ printf("\niteration %d\n",i+1);
for(j=0;j<line;j++)
{ total+=pkt[j];
if(total<=bcktsize)
printf("\n Input from line %d with rate %d is thrown out of bucket\n Current bucket size(Mb) is %d\n",j+1,pkt[j],total);
else{total-=pkt[j];
printf("\n Input from line %d with rate %d is thrown out of bucket\n Current bucket size(Mb) is %d\n",j+1,pkt[j],total);
}if(total<=rate)
{ printf("packet sent to outputline at rate %d",total);
total=0;
printf("current bucket size is %d",total);
} else
{
total-=rate;
printf("\n-----------------------------------\n");
printf("\n packet sent to output line at rate %d\n Current bucket size(Mb)is %d\n",rate,total);
printf("\n----------------------------------------------\n");
}
}
return 0;
}
}
