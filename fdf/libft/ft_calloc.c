/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:56:54 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/05 08:58:07 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pntr;
	size_t			i;

	i = 0;
	if (nmemb > 0 && size > (-1 / nmemb))
		return (NULL);
	pntr = malloc(nmemb * size);
	if (!pntr)
		return (NULL);
	while (i < (nmemb * size))
	{
		pntr[i] = 0;
		i++;
	}
	return (pntr);
}
