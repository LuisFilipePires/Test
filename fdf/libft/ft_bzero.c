/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:43:27 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/11 14:33:04 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
int main()
{
	char str[25] = "ola Bom dia tudo bem";


	printf("String antes bzero: \"%s\"\n", str);
    // Preenche os primeiros 5 bytes de str com zeros usando bzero
    ft_bzero(str, 5);

    // Imprime o resultado
	printf("String após bzero: \"%s\"\n", str);
	for (int i = 0; i < 40; i++)
	{
		printf("&str[%d] = %p str[%d] = %d\n", i, &str[i], i, str[i]);
	}

    return (0);
}
*/
