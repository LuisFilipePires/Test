/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:30:51 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/26 13:07:33 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cal_funct(size_t *count, char c, va_list args)
{
	if (c == 'c')
		ft_char(count, va_arg(args, int));
	else if (c == 's')
		ft_string(count, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_number(count, va_arg(args, int));
	else if (c == 'p')
		ft_pnthex(count, (unsigned long long)va_arg(args, void *));
	else if (c == 'u')
		ft_unsigned(count, va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_hexa(count, (unsigned long long)va_arg(args, void *), c);
	else if (c == '%')
		ft_char(count, '%');
}

void	find(size_t *count, const char *format, va_list args)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			cal_funct(count, format[i], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			(*count)++;
			i++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, format);
	find(&count, format, args);
	va_end(args);
	return (count);
}
//__attribute__((unused))
