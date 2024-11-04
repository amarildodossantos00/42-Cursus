# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>


int	main(void)
{
	char	*buff;
	char	*args[2];
	while (1)
	{
		buff = readline("minishel% ");
		if (!buff)
			break;
		if (!strcmp(buff, "clear"))
		{
			pid_t idfilho = fork();
			if (idfilho == 0)
			{
				args[0] = "/usr/bin/clear";
				args[1] = NULL;
				execv(args[0], args);
				perror("execv falhou\n");
				exit(1);
			}
			else if (idfilho > 0)
				wait(NULL);
			else
				perror("Error ao criar o processo filho\n");
		}
		else if (!strcmp(buff, "ls"))
		{
			pid_t idfilho = fork();
			if (idfilho == 0)
			{
				args[0] = "/usr/bin/ls";
				args[1] = NULL;
				execv(args[0], args);
				perror("execv falhou\n");
				exit(1);
			}
			else if (idfilho > 0)
				wait(NULL);
			else
				perror("Error ao criar o processo filho\n");
		}
		else if (!strcmp(buff, "exit"))
		{
				//args[0] = "/usr/bin/exit";
				//args[1] = NULL;
				//execv(args[0], args);
				//perror("execv falhou\n");
				exit(0);
				free(buff);
		}
		else
			printf("not\n");
		free(buff);
	}
}
