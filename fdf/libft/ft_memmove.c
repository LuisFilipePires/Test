/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:11:01 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/04 11:45:23 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_char(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src || dest >= (src + n))
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*c_dest;
	const char	*c_src;

	c_dest = dest;
	c_src = src;
	if (dest == NULL || src == NULL)
		return (NULL);
	copy_char(c_dest, c_src, n);
	return (dest);
}
