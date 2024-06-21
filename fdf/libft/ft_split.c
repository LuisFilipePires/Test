/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:50:53 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/11 14:35:02 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static void	word(char const *s, char c, int *start, int *len)
{
	int	i;

	i = *start;
	while (s[i] == c && s[i] != '\0')
		i++;
	*start = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	*len = i - *start;
}

static int	nb_wrds(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	fill(char **pnt, char const *s, char c, int nb_w)
{
	int	j;
	int	start;
	int	len;
	int	k;

	start = 0;
	j = 0;
	while (j < nb_w)
	{
		word(s, c, &start, &len);
		pnt[j] = (char *)malloc((len + 1) * sizeof(char));
		k = 0;
		while (k < len)
		{
			pnt[j][k] = s[start];
			k++;
			start++;
		}
		pnt[j][k] = '\0';
		j++;
	}
	pnt[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**pnt;
	int		nb_w;

	if (!s || !*s)
	{
		pnt = (char **)malloc(sizeof(char *));
		if (!pnt)
			return (NULL);
		pnt[0] = (NULL);
		return (pnt);
	}
	nb_w = nb_wrds(s, c);
	pnt = (char **)malloc((nb_w + 1) * sizeof(char *));
	if (!pnt)
		return (0);
	fill(pnt, s, c, nb_w);
	return (pnt);
}
/*
#include <stdio.h>

int	main()
{
	//char *word1 = "bom       dia       como esta     ";
	//char *word2 = "  sao  tres     caracteres    ";
	char c = ' ';
	
//	printf("word1 = %d\n", nb_wrds(word1, c));
//	printf("word2 = %d\n", nb_wrds(word2, c));
	char	*ch = "     ola bom dia     kkkkkkk    8   55555";
	ft_split(ch, c);

	return (0);
}
*/
