/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:48:19 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/26 13:03:17 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(size_t *count, unsigned long long val, char c)
{
	char			hex[20];
	int				i;
	unsigned int	num;
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	num = (unsigned int) val;
	if (num == 0)
		ft_char(count, '0');
	i = 0;
	while (num > 0)
	{
		hex[i++] = base[num % 16];
		num /= 16;
	}
	i--;
	while (i >= 0)
	{
		ft_char(count, hex[i]);
		i--;
	}
}
