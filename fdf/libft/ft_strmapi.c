/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:33:47 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/07 13:05:30 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ch;

	i = 0;
	len = ft_strlen(s);
	ch = (char *)malloc((len + 1) * sizeof(char));
	if (!ch)
		return (NULL);
	while (i < len)
	{
		ch[i] = f(i, s[i]);
		i++;
	}
	ch[len] = '\0';
	return (ch);
}
/*
int	main()
{
	char	*ch;
	
	ch = "ola bom dia";
	printf("%zu\n", ft_strlen(ch));
	return (0);
}
*/
