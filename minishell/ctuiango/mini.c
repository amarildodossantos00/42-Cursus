/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:48:51 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/28 16:03:25 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*rl;
	char	*str;
	int	i = 0;
	
	while(1)
	{
		rl = readline("Cel%");
		if (rl == NULL)
		{
			printf("\nSaindo do mini...\n");
			break ;
		}
		add_history(rl);
		if (i == 0)
		{
			str = rl;
			i = 1;
		}
		printf("%s\n", rl);
		 if (strcmp(str, "pzau") == 0) {
		    printf("cramos\n");
		}
		//sprintf("%s\n", str);
		//free(rl);
	}
	rl_clear_history();
	return (0);
}
