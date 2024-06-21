/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:31:04 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/18 16:31:06 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


int	ft_abs(int nb)
{
	int n;
	
	n = nb;
	if (n < 0)
		n = -n;
	return (n);
}

void calculate_bresenham(t_line *line, t_bresenham *bres) {
    bres->dx = ft_abs(line->x1 - line->x0);
    bres->dy = ft_abs(line->y1 - line->y0);
    bres->sx = (line->x0 < line->x1) ? 1 : -1;
    bres->sy = (line->y0 < line->y1) ? 1 : -1;
    bres->err = bres->dx - bres->dy;
}

void draw_line_bresenham(t_data *img, t_line *line, t_bresenham *bres)
{
    while (1) {
        my_mlx_pixel_put(img, line->x0, line->y0, line->color);
        if (line->x0 == line->x1 && line->y0 == line->y1)
            break;
        int e2 = 2 * bres->err;
        if (e2 > -bres->dy) {
            bres->err -= bres->dy;
            line->x0 += bres->sx;
        }
        if (e2 < bres->dx) {
            bres->err += bres->dx;
            line->y0 += bres->sy;
        }
    }
}
