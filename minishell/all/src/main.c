#include "../header/header.h"

int	main(void)
{
	t_vars vars;
	extern char	**environ;

	//pzau
	get_variables(&vars, environ);
	//pzau
	call_prompt(&vars);
	return (0);
}
