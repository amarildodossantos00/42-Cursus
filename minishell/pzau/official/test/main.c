/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:50:35 by pzau              #+#    #+#             */
/*   Updated: 2025/01/06 16:16:45 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Para usar strlen

static char *without_qoutes(char *str)
{
    char    *new_str;
    int     n = 0;
    int     i = 0;
    int     j = strlen(str) - 1;

    new_str = malloc(sizeof(char) * (strlen(str) + 1));  // Corrigido o cálculo de memória
    if (!new_str)
        return NULL; 

    while (str[i] == 39)
        i++;

    while (str[j] == 39)
        j--;

    while (i <= j)
    {
        new_str[n] = str[i];
        n++;
        i++;
    }

    new_str[n] = '\0';  // Garantir que a string termine com '\0'
    return new_str;
}

int main(int ac, char **av)
{
    if (ac > 1) {  // Verificar se o argumento foi passado
        char *str = without_qoutes(av[1]);  // Corrigir para usar av[1] (não av[0], que é o nome do programa)
        printf("%s\n", str);
        free(str);  // Lembre-se de liberar a memória alocada
    } else {
        printf("Por favor, forneça um argumento.\n");
    }
    return 0;
}

