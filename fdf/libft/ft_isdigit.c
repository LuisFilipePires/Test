/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:08:51 by luis-fif          #+#    #+#             */
/*   Updated: 2024/02/28 13:36:05 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
#include <stdio.h>

int	main()
{
	int n = 50;
//	printf ("%d é digito? 0 = nao, 1 = sim ====  %d\n", n, ft_isdigit(n));
//	printf (" -> %d é = - %c -  no codigo ascii\n", n, n + '0');
	
	for (int i = 0; i < 127; i++)
	{
		if (ft_isdigit(i))
		{
			printf("index %d, %c = %d", i, i, ft_isdigit(i));
			printf(" ---\n");
		}
		else
			printf("index %d, %c = %d\n", i, i, ft_isdigit(i));

	}

	return(0);
}
*/
