/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:41:46 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/18 13:41:48 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




void	project2(t_data *data)
{
	t_line	line;
	t_bresenham	bres;
	int i;
	int j;
	
	j = 0;
	while (j < data->size.cols)
	{
		i = 0;
		while (i < data->size.lines -1)
		{
		//	if(!(matrix[i + 1][j].iso_y))
			//	break;
			line.x0 = data->matrix[i][j].iso_x;
            line.y0 = data->matrix[i][j].iso_y;
            line.x1 = data->matrix[i + 1][j].iso_x;
            line.y1 = data->matrix[i + 1][j].iso_y;
            line.color = 0x000000FF;
            calculate_bresenham(&line, &bres);
            draw_line_bresenham(data, &line, &bres);
            i++;
		}
		j++;
	}
}

void	project(t_data *data)
{
	t_line	line;
	t_bresenham	bres;
	int i;
	int j;
	
	i = 0;
	while (i < data->size.lines)
	{
		j = 0;
		while (j < data->size.cols -1)
		{
		//	if(!(matrix[i][j + 1].iso_x))
			//	break;
			line.x0 = data->matrix[i][j].iso_x;
            line.y0 = data->matrix[i][j].iso_y;
            line.x1 = data->matrix[i][j + 1].iso_x;
            line.y1 = data->matrix[i][j + 1].iso_y;
            line.color = 0x00FF0000;
            calculate_bresenham(&line, &bres);
            draw_line_bresenham(data, &line, &bres);
            j++;
		}
		i++;
	}
	
	project2(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}
