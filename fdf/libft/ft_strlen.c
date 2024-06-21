/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:45:00 by luis-fif          #+#    #+#             */
/*   Updated: 2024/02/28 14:24:14 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int main() {
   char *frase = "Esta é uma frase de exemplo.";

    size_t tamanho = ft_strlen(frase);

   printf("A frase \"%s\" tem tamanho: %zu\n", frase, tamanho);
	
   for (size_t i = 0; i < tamanho; i++)
   {
	   printf("&frase[%zu] = %p, frase[%zu] = %c\n", i, &frase[i], i, frase[i]);
   }



    return (0);
}
*/
