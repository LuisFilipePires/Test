/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:46:11 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/04 15:50:43 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	src = (unsigned char *)s;
	ch = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (*src == ch)
			return (src);
		src++;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    char search_char = 'W';

    // Procurar 'W' na string
    const char *result = (char *)ft_memchr(str, search_char, strlen(str));

    if (result != NULL) {
        printf("'%c' encontrado na posição %ld.\n", search_char, result - str);
    } else {
        printf("'%c' não encontrado na string.\n", search_char);
    }

    return 0;
}
*/
