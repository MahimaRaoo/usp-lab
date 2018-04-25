#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>


int main()
{
struct dirent* dir;
struct stat s;
DIR *dp;
dp=opendir(".");
if(dp)
{
while(dir=readdir(dp))
{
stat(dir->d_name,&s);
printf("%d %d %d %d %o %s %s \n\n",(int)s.st_gid,(int)s.st_uid,(int)s.st_ino,(int)s.st_size,s.st_mode,(S_ISDIR(s.st_mode)?"yes":"no"),(S_ISLNK(s.st_mode)?"yes":"no"));

}

}
return 0;
}
