#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void	main(void)
{
//	while (1)
//	{
		pid_t idfilho = fork();
		if (idfilho == 0)
		{
			wait(1);
			printf("FPID: %d\n", getpid());
			printf("PPID: %d\n", getppid());
			//execl("/usr/bin/who", "who", NULL);
		}
		else
		{
			printf("PPID %d\n", getpid());
			printf("FPID %d\n", idfilho);
			//char c = getchar();
			//printf("\n%c", c);
		}
/*	}*/	printf("Ambos\n\n");
}

