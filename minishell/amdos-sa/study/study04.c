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
		if (!strcmp(buff, "/usr/bin/clear"))
		{
			pid_t idfilho = fork();
			if (idfilho == 0)
			{
				//wait(1);
				args[0] = buff;
				args[1] = NULL;
				execv(args[0], args);
				free(buff);
			}
			buff = readline("minishel% ");
		}
		else
			printf("not\n");
	}
}
