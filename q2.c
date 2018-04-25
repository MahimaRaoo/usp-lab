#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
int fd1,n;
char buf[25];

//a)
if((fd1=open("foo.txt",O_RDONLY))<0)
   return 1;


if(read(fd1,buf,20)!=20)
    return 1;

write(STDOUT_FILENO,buf,20);


//b)

if(lseek(fd1,10,SEEK_SET)<0)
    return 1;

if(read(fd1,buf,20)!=20)
    return 1;
write(STDOUT_FILENO,buf,20);


//c)

if(lseek(fd1,10,SEEK_CUR)<0)
    return 1;

if(read(fd1,buf,20)!=20)
    return 1;
write(STDOUT_FILENO,buf,20);


//d)
if((n=lseek(fd1,0,SEEK_END))<0)
    return 1;
printf("SIZE : %d",n);

close(fd1);
return 0;

}

































