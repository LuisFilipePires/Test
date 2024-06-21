/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:23:16 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/26 11:45:41 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(size_t *count, unsigned long nb)
{
	char	nb_dec[10];
	int		i;

	if (nb == 0)
	{
		ft_char(count, '0');
	}
	i = 0;
	while (nb > 0)
	{
		nb_dec[i++] = "0123456789"[nb % 10];
		nb /= 10;
	}
	i--;
	while (i >= 0)
	{
		ft_char(count, nb_dec[i]);
		i--;
	}
}
