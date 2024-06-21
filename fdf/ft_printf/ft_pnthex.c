/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:23:44 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/26 11:04:38 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pnthex(size_t *count, unsigned long long address)
{
	char	hex[16];
	int		i;

	if (address == 0)
	{
		write (1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	i = 0;
	while (address > 0)
	{
		hex[i++] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	write (1, "0x", 2);
	(*count) += 2;
	i--;
	while (i >= 0)
	{
		ft_char(count, hex[i]);
		i--;
	}
}
/*
 printf("Endereço atual: %llu\n", address);
 printf("Dígito hexadecial: %c\n", hex[i - 1]);

	hex = "0123456789abcdef";
	cht = ch;

	if (cht == 'p')
	{
		write (1, "0x", 2);
		cht = 't';
	}

	if (nb > 16)
	{
		ft_puthex_fd(nb / 16, hex, fd, cht);
		ft_puthex_fd(nb % 16, hex, fd, cht);
	}
	else
	{
		c = hex[nb % 16];
		write(fd, &c, 1);
	}
	*/
	/*if (nb == 0 && fd == STDOUT_FILENO) 
	{
		write(fd, "x0", 2);
	}*/
