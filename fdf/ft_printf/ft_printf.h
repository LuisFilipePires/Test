/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:55 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/25 17:19:38 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/*este libft esta no diretorio anterior 
este ft_printf nao é igual ao original*/
# include "../libft/libft.h"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_char(size_t *count, int c);
void	ft_string(size_t *count, char *str);
void	ft_number(size_t *count, int nb);
void	ft_pnthex(size_t *count, unsigned long long address);
void	ft_unsigned(size_t *count, unsigned long nb);
void	ft_hexa(size_t *count, unsigned long long val, char c);

#endif
