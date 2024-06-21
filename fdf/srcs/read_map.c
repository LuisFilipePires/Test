/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fil <fil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:13:15 by fil               #+#    #+#             */
/*   Updated: 2024/06/15 23:28:37 by fil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	free_line_error(t_data *data, int index)
{
	int i;
	
	i = 0;
	while (i < index)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void    free_array(t_data *data)
{
  //  puts("entrou");
    int i;

	i = 0;
	while(i < data->size.lines)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}
/*
void fill_wall(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < data->size.lines)
	{
		j = 0;
		while (j < data->size.cols)
		{
		data->matrix[i][j].n = 0;
			data->matrix[i][j].wall = 0;
			data->matrix[i][j].org_val = 0;;
			j++;
		}
		i++;
	}
}
*/
void	create_array(const char *map, t_data *data)
{
    int i;
   // t_map_size      size;
   // t_map_array     **matrix;
    printf("ENTROU");
    i = 0;
    /*size.c*/
    map_size(map, data);
    
    data->matrix = (t_map_array **) malloc(sizeof(t_map_array *) * data->size.lines);
    if (data->matrix == NULL)
	{
		free_line_error(data, i);
		exit(EXIT_FAILURE);
	}
    while (i < data->size.lines)
    {
      //  data->matrix[i] = (t_map_array *) malloc(sizeof(t_map_array) * (data->size.cols));
      data->matrix[i] = (t_map_array *) ft_calloc(sizeof(t_map_array) , (data->size.cols));
        if (data->matrix[i] == NULL)
		{
			free_array(data);
			exit(EXIT_FAILURE);
		}
        i++;
    }
//    fill_wall(data);
	fill_array(data, map);
//	free_array(data);
  //  return (matrix);
}
