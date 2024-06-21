/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fil <fil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:29:02 by fil               #+#    #+#             */
/*   Updated: 2024/06/15 14:27:47 by fil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*esta parte do codigo serve para calcular colunas e linhas apenas
para criar o grafico*/
int counter(const char *s, int last_count)
{
	int i;
	int count;
	
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == 32 && s[i] != '\0')
			i++;
		if ((s[i] != 32 && s[i] != '\0') && (s[i] != '\n' && s[i] != '\0'))
			count++;
		while (s[i] != 32 && s[i] != '\0')
			i++;
	}
	if (last_count > count)
		count = last_count;
	return (count);
}

void map_size(const char *map, t_data *data)
{
    int fd;
    char *line;

	//data->size.cols = 0;
//	data->size.lines = 0;
    fd = open(map, O_RDONLY);
    if (fd == -1)
        exit(1);
   line = get_next_line(fd);
   while (line != NULL)
   {
  		data->size.cols = counter(line, data->size.cols);
   		free(line);
   		line = get_next_line(fd);
   		data->size.lines++;
   } 
   close(fd);
  // get_next_line(-1);
    free(line);
}
