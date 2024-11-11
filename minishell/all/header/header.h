#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "../libx/libx.h"

typedef struct s_vars
{
        char	*input;
	char	**variables;
}	t_vars;

void	call_prompt(t_vars *vars);

//pzau
void	get_variables(t_vars *vars, char **environ);
void    print_variables(t_vars *vars);
//pzau

#endif
