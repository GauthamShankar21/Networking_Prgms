#include<stdio.h>
#include<stdlib.h>
#define RTT 4
#define TOT_FRAMES 7
enum {NO,YES} ACK;
void main()
{ 
int wait_time,i=1;
ACK=YES;
for(i=1;i<=TOT_FRAMES;)
{ 
if(ACK==YES && i!=1)
{
printf("\nSENDER: ACK for frame %d received .\n",i-1);
}
printf("\nSENDER: frame %d sent,waiting for ACK...\n",i);
ACK=NO;
wait_time= rand() %4+2;
printf("%d\n",wait_time);
if(wait_time>RTT)
{
printf("sender ACK not received for frame %d=>TIMEOUT resending frame...",i);
}
else
{
printf("\nRECEIVER: frame %d received,ACK sent\n",i);
printf("------------- --------------");
ACK=YES;
if(i==TOT_FRAMES)
printf("\nSENDER:ACK for frame %d received.\n",i);
i++;
}
}
}
