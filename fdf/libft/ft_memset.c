/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:51:27 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/11 15:48:27 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	char	ch;

	p = s;
	ch = c;
	while (n > 0)
	{
		*p++ = ch;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

// aloca 1 byte por espaco de memoria
int main() {
    char str[10];
	int n;

	n = 10;

    // Preenche os primeiros 5 bytes de str com 'X'
	ft_memset(str, 'K', n);

    // Imprime o resultado
    printf("%s\n", str);
	for (int i = 0; i < n; i++)
	{
		printf("&str[%d] = %p, str[%d] = %c\n", i, &str[i], i, str[i]);
	}

    return 0;
}
*/
