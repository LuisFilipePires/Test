/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:23:51 by luis-fif          #+#    #+#             */
/*   Updated: 2024/02/28 13:19:58 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
/*
#include <stdio.h>

int	main()
{
	int n = 92;
	printf ("%d é alpha? 0 = nao, 1 = sim ====  %d\n", n, ft_isalpha(n));
	printf (" -> %d é = - %c -  no codigo ascii\n", n, n);
	return(0);
}
*/
