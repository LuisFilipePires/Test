/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:22:20 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/14 14:22:38 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	gnl_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_strcpy_index(char *dst, const char *src,
		size_t ind_dst, size_t ind_src)
{
	size_t	i;
	size_t	j;

	i = ind_dst;
	j = ind_src;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*gnl_ft_strjoin_nfree(char *src1, char *src2)
{
	char	*temp;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (src1 == NULL && src2 == NULL)
		return (NULL);
	if (src1 != NULL)
		len1 = gnl_ft_strlen(src1);
	if (src2 != NULL)
		len2 = gnl_ft_strlen(src2);
	temp = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	if (src1 != NULL)
		temp = gnl_ft_strcpy_index(temp, src1, 0, 0);
	if (src2 != NULL)
		temp = gnl_ft_strcpy_index(temp, src2, len1, 0);
	free(src1);
	free(src2);
	return (temp);
}
