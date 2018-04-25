#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
struct dirent* dir;
struct stat s;
DIR *dp;
int fd1;
dp=opendir(".");
if(dp)
{
while(dir=readdir(dp))
{
stat(dir->d_name,&s);

fd1=open(dir->d_name,O_RDWR,0777);

if(!lseek(fd1,0,SEEK_END))
{
printf("DELETED %s \n\n",dir->d_name);
unlink(dir->d_name);
}

}
} 
return 0;

}
