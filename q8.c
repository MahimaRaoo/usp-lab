#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<setjmp.h>

static void f1(int i,int j,int k,int l);
static void f2();
static int globval=0;
static jmp_buf jmpbuffer;
int main()
{
register int regval;
static int statval;
volatile int volval;
int autoval;
regval=1;
globval=2;
statval=3;
volval=4;
autoval=5;

printf("BEFORE longjmp \n\n");
printf("%d %d %d %d %d\n\n",globval,statval,volval,regval,autoval);

if(setjmp(jmpbuffer)!=0)
{
printf("AFTER longjmp \n\n");
printf("%d %d %d %d %d\n\n",globval,statval,volval,regval,autoval);
return 0;
}
f1(statval,volval,regval,autoval);


}

static void f1(int i,int j,int k,int l)
{
printf("in f1() \n\n");
globval=10;
i=20;
j=30;
k=40;
l=50;
f2();

}

static void f2()
{
longjmp(jmpbuffer,1);

}


