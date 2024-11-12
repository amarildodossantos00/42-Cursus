/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:04:06 by vcatete           #+#    #+#             */
/*   Updated: 2024/11/11 17:04:12 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

void to_uppercase(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		int i = 1;
		while (i < argc)
		{
			to_uppercase(argv[i]);  // Converte o argumento atual para maiúsculas
			std::cout << argv[i];   // Imprime o argumento
			if (i < argc - 1)       // Se não for o último argumento, imprime um espaço
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

