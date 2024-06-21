/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:24:24 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/26 09:19:18 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	great(size_t *count, int nb)
{
	int		div;
	char	ch;

	div = 1;
	while (nb / div >= 10)
		div *= 10;
	while (div > 0)
	{
		ch = ((nb / div) % 10) + '0';
		ft_char(count, ch);
		div = div / 10;
	}
}

void	ft_number(size_t *count, int nb)
{	
	char	ch;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	else if (nb < 0 && nb != -2147483648)
	{
		ft_char(count, '-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
	{
		ch = nb + '0';
		ft_char(count, ch);
	}
	else
		great(count, nb);
}
