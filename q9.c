#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
int fd1,fd2,size=0;
char buff[200];
if(argc!=3)
printf("error1\n");

if((fd1=open(argv[1],O_RDONLY))<0)
printf("Cant open file one\n");
else
printf("file 1 opened\n");

if((fd2=open(argv[2],O_RDWR))<0)
printf("Cant open file one\n");
else
printf("file 2 opened\n");

if((size=lseek(fd1,0L,SEEK_END))<0)
printf("no data to copy \n");
else
printf("size is : %d \n",size);

if(lseek(fd1,0L,SEEK_SET)<0)
printf("error traversing back \n");
else
printf("traversing back\n");

if(read(fd1,buff,size)!=size)
printf("read error");

if(write(fd2,buff,size)!=size)
printf("write error");



return 0;
}

