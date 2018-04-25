#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
if(argc==3)
{
if(link(argv[1],argv[2])==0)
printf("Hard link created");

else
printf("HARD LINK ERROR");


}

if(argc==4)
{
if(link(argv[1],argv[2])==0)
printf("Soft link created");

else
printf("SOFT LINK ERROR");
}
return 0;
}
