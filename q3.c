#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
int fd1;

struct stat filestat;

if(stat("./foo.txt",&filestat)<0)
return 1;

printf("FILE SIZE : %d \n",(int)filestat.st_size);

printf("GROUP ID : %d \n",(int)filestat.st_gid);
printf("USER ID : %d \n",(int)filestat.st_uid);
printf("NUMBER OF LINKS : %d \n",(int)filestat.st_nlink);
printf("INODE NO : %d \n",(int)filestat.st_ino);
printf("MODE : %c  \n",(char)filestat.st_mode);
/*printf((filestat.st_mode&&S_IRUSR||filestat.st_mode&&S_IRGRP||filestat.st_mode&&S_IROTH)?"r":"-");
printf((filestat.st_mode&&S_IWUSR||filestat.st_mode&&S_IWGRP||filestat.st_mode&&S_IWOTH)?"w":"-");
printf((filestat.st_mode&&S_IXUSR||filestat.st_mode&&S_IXGRP||filestat.st_mode&&S_IXOTH)?"x":"-");
printf("\n\n");*/

printf("IS DIR : %s \n",(S_ISDIR(filestat.st_mode)?"yes":"no"));
printf("IS SYMBOLIC LINK : %s \n",(S_ISLNK(filestat.st_mode)?"yes":"no"));

return 0;
}
