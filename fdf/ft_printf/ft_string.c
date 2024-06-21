/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:31 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/25 17:11:29 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(size_t *count, char *str)
{
	int	i;

	i = 0;
	if (str == NULL || count == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_char(count, str[i]);
		i++;
	}
}
