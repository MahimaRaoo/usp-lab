#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void charatatime(char * st)
{
char *ptr;
int c;
setbuf(stdout,NULL);
for(ptr=st;(c=*ptr++)!=0;)
putc(c,stdout);

}
int main(){
int pid;

if((pid=fork())<0)
printf("error");

else if(pid==0)
{

charatatime("c c c c");

return 0;
}

else
{
charatatime("p p p p ");

return 0;
}}
