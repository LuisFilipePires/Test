/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:22:00 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/04 15:35:03 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ch;

	i = 0;
	ch = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			ch = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == c)
		ch = (char *) &s[i];
	return (ch);
}
