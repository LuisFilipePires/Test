/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:24:27 by luis-fif          #+#    #+#             */
/*   Updated: 2024/02/28 13:47:07 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122)));
}
/*
#include <stdio.h>

int	main()
{
	for (int i = 0; i < 127; i++)
	{
		if (ft_isalnum(i))
		{
			printf("index %d, na table ascii %c = %d", i, i,ft_isalnum(i));
			printf("  ---\n");
		}
		else
			printf("index %d,na table ascii = %c = %d\n", i, i, ft_isalnum(i));
	}
	return (0);
}
*/
