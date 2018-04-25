#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
int pid;
if((pid=fork())<0)
printf("first ERROR");

else if(pid==0)
{
if((pid=fork())<0)
printf("second ERROR");

else if(pid>0)
return 0;

sleep(2);
printf("SECOND child's parent : %ld\n",(long)getppid());
return 0;

}

if(waitpid(pid,NULL,0)!=pid)
printf(" waitpid ERROR");


}

