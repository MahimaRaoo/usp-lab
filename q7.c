#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<utime.h>
#include<time.h>
int main(int argc,char *argv[])
{
struct utimbuf times;
struct stat s1,s2;

if(stat(argv[1],&s1)<0)
printf("ERROR");

if(stat(argv[2],&s2)<0)
printf("ERROR");

printf("BEFORE : %s %s \n\n",ctime(&s1.st_atime),ctime(&s1.st_mtime));

times.actime=s2.st_atime;
times.modtime=s2.st_mtime;

if(utime(argv[1],&times)<0)
printf("ERROR COPYING");

if(stat(argv[1],&s1)<0)
printf("ERROR");

printf("AFTER : %s %s \n\n",ctime(&s1.st_atime),ctime(&s1.st_mtime));

return 0;
}
