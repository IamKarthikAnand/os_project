#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void *fun1();
void *fun2();
int main()
{
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
}
void *fun1()
{
int pid;
for(int i=0;i<2;i++)
{
 printf("i'm the original process");
 pid = fork();
 if ( pid!= 0 ) 
 {
printf("i'm the parent process");
printf("My child's PID is %d \n", pid ); 
}
 else
 {
 sleep(5); 
 printf("i'm the child process\n");
 }
 printf("PID terminates. \n"); 
}
}
void *fun2()
{
for(int j=0;j<2;j++)

{
pid_t t;
t= fork();
if (t!= 0 ) 
{
 	printf("child");
}
else
{
 sleep(1);
 printf("parent"); 
 }
}
}
