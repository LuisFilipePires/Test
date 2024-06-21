/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:47:41 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/05 13:48:29 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (set[j] != '\0' && s1[i] != '\0')
	{
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	j;
	int	i;

	i = ft_strlen(s1);
	j = 0;
	while (set[j] != '\0' && i >= 0)
	{
		if (set[j] == s1[i - 1])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*rez;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	rez = ft_substr(s1, start, end - start + 1);
	return (rez);
}
/*
#include <stdio.h>

int	main()
{
	char	*s11 = "abab\tcafilipebab\tca";
	char	*set1 = "abc\t";
	ft_strtrim(s11, set1);
	printf("%s\n", ft_strtrim(s11, set1));


	return (0);
}
*/
