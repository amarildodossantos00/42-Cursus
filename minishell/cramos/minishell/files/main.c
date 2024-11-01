/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:06:32 by cramos            #+#    #+#             */
/*   Updated: 2024/11/01 10:20:52 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void handle_sigint(int sig)
{
    rl_on_new_line();

    rl_replace_line("", 0);

    rl_redisplay();
}

int main()
{
	signal(SIGINT, handle_sigint);
    char *input;


    while (1)
    {
        input = readline("cramos% ");
        if (!input)
        	break ;
        printf("zsh: comando não encontrado: %s\n", input);

        add_history(input);

	if (strcmp(input, "clear_history") == 0)
	{
		rl_clear_history();
		printf("Histórico limpo!\n");
	}
	if (strcmp(input, "exit") == 0)
		break ;
        //free(input);
    }
	free(input);

    return 0;
}
