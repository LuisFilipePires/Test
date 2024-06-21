/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:39:55 by luis-fif          #+#    #+#             */
/*   Updated: 2024/02/28 16:09:17 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*c_dest;
	const unsigned char	*c_src;

	c_dest = dest;
	c_src = src;
	while (n-- > 0)
	{
		*c_dest++ = *c_src++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    // Copia os primeiros 13 bytes de 'source' para 'destination'
    memcpy(destination, source, 13);

    // Adiciona um caractere nulo ao final de 'destination' 
	//para torná-lo uma string válida
    destination[13] = '\0';

    // Imprime o resultado
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
*/
