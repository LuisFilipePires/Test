/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:44:23 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/18 13:44:25 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void display_message(t_data *img)
{
    mlx_string_put(img->mlx_ptr, img->mlx_win, 10, 30, 0xFFFFFF, " Clear: L");
    mlx_string_put(img->mlx_ptr, img->mlx_win, 10, 50, 0xFFFFFF, " Exit: Esc");
 	mlx_string_put(img->mlx_ptr, img->mlx_win, 10, 80, 0xFFFFFF, "PAD: \" + \"  \" - \"");
    mlx_string_put(img->mlx_ptr, img->mlx_win, 10, 100, 0xFFFFFF, "Press: \" O \" to origin");

   
    // mlx_string_put(img->mlx_ptr, img->mlx_win, 10, 50, 0xFFFFFF, "Clear: P");
}

void	update_window(t_data *data)
{
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

void clear_window(t_data *img, int color)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT) // Supondo que a altura da janela seja 900
    {
        x = 0;
        while (x < WIDTH) // Supondo que a largura da janela seja 1600
        {
            my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
}

int close_window(void *param)
{
    t_data *data = (t_data *)param;

    if (data->img) {
        mlx_destroy_image(data->mlx_ptr, data->img);
        data->img = NULL;
    }
    if (data->mlx_win) {
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
        data->mlx_win = NULL;
    }
    if (data->mlx_ptr) {
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        data->mlx_ptr = NULL;
    }

    // Se tiver um mapa alocado, libere-o aqui
    // free_map(data);
	//free_map(data);
    exit(0);
    return (0);
}


