#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buff;

int main(void)
{
	while (1)
	{
		buff = readline("minishell% ");
		if (strlen(buff) > 0)
			add_history(buff);
		if (!strcmp(buff, "ls"))
			system("ls");
		else if (!strcmp(buff, "clear"))
			system("clear");
		else if (!strcmp(buff, "cat readline01.c"))
			system("cat readline01.c");
		else if (!strcmp(buff, "exit") || !strcmp(buff, "quit") || !strcmp(buff, "q"))
			break ;
		else
			printf("zsh command not found: %s\n", buff);
		free(buff);
	}
	return (0);
}
