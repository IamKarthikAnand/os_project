#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{

	int n=0,k;
	
	pid_t pid;

		do
		{
			printf("Please enter a number greater than 0 to run the program\n"); 
  			scanf("%d", &k);	
		}while (k <= 0);
		pid = fork();

		if (pid == 0)
		{	printf("Child is working...\n");
			printf("%d\n",k);
			if (k%2 == 0)
			{
			while (k!=0)
			{
					k = k/2;
					printf("%d\n",k);
			}
			}
			else {
			while (k!=0)
			{
			k = (3 * (k) )+ 1;
			printf("%d\n",k);
			}
			}		
			printf("%d\n",k);
			printf("Child process is done.\n");
		}
		else
		{
			printf("Parents is waiting on child process...\n");
			
			printf("Parent process is done.\n");
		}
	return 0; 
}
