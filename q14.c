#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<signal.h>

void callback(int val)
{
printf("Singnal received");
(void)signal(SIGINT,SIG_DFL);


}

int main()
{
int i=0,ch;
printf("ENter your choice :");
scanf("%d",&ch);

switch(ch)
{
case 1: (void)signal(SIGINT,callback);
break;

case 3:(void)signal(SIGINT,SIG_IGN);
break;
}

while(1)
{
printf("Dont press ctrl+c \n");
sleep(1);
i++;
if(i==10&&ch==2)
(void)signal(SIGINT,SIG_DFL);

}

return 0;

}
