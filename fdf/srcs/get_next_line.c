/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:21:29 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/14 14:22:01 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*gnl_remake(char *str)
{
	char	*temp;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_ft_strlen(str);
	while (str[i] != '\n')
		i++;
	i++;
	if (i == len)
	{
		free(str);
		return (NULL);
	}
	temp = (char *) malloc((len - i + 1) * sizeof(char));
	temp = gnl_ft_strcpy_index(temp, str, 0, i);
	free(str);
	return (temp);
}

char	*gnl_get_line(char *str)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] != '\n')
		return (NULL);
	i++;
	line = (char *) malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_last_row(char **str)
{
	char	*temp;
	size_t	len;

	len = gnl_ft_strlen(*str);
	temp = (char *) malloc((len + 1) * sizeof(char));
	temp = gnl_ft_strcpy_index(temp, *str, 0, 0);
	free(*str);
	*str = NULL;
	return (temp);
}

char	*gnl_check_buffer(int fd, char *res, ssize_t *bytes)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!buffer || bytes_read < 0 || fd < 0 || BUFFER_SIZE <= 0
		|| (bytes_read == 0 && res == NULL))
	{
		free(res);
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	*bytes = bytes_read;
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;
	static char	*res = NULL;

	line = gnl_get_line(res);
	while (line == NULL)
	{
		buffer = gnl_check_buffer(fd, res, &bytes_read);
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		res = gnl_ft_strjoin_nfree(res, buffer);
		if (bytes_read == 0 && res != NULL)
			return (line = gnl_last_row(&res));
		line = gnl_get_line(res);
	}
	res = gnl_remake(res);
	return (line);
}
