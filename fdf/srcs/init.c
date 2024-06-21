/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:21:29 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/18 13:21:31 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_data_3(t_data *data)
{
    int screen_width = WIDTH;
    int screen_height = HEIGHT;
    int map_width = data->size.cols;
    int map_height = data->size.lines;

    // Calcular o fator de escala
    if (map_width > 0 && map_height > 0) {
        data->scale_factor = ((data->size.lines + data->size.cols) / 5);
    } else {
        data->scale_factor = 1; // Valor padrão se o mapa for inválido
    }

    // Ajustar o scale_factor para que o mapa caiba na tela
//    data->scale_factor = (data->scale_factor < 1) ? 1 : data->scale_factor;

    // Calcular a posição para centralizar o mapa
 //   data->pos_x = (screen_width - (map_width * data->scale_factor)) / 2;
 //   data->pos_y = (screen_height - (map_height * data->scale_factor)) / 2;
}

void	init_data_2(t_data *data)
{
	data->size.lines = 0;
	data->size.cols = 0;
	data->scale_factor = 4;
	//data->pos_x =  20;
  //  data->pos_y =  20;
	data->pos_x =  WIDTH / 2;
    data->pos_y =  HEIGHT / 4;

	//data->pos_x = 900;
   // data->pos_y =  100;


    printf("data->pos_x : %d\n", data->pos_x);
//	printf("data->pos_y : %d\n", data->pos_y);
}



void	init_data(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
        exit(1);
    data->win_width = WIDTH;
    data->win_height = HEIGHT;
    data->mlx_win = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "FDF");
    if (data->mlx_win == NULL)
    {
        free(data->mlx_ptr);
        exit(1); // Adicione verificação de erro
    }
    data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
    if (data->img == NULL)
    {
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
        free(data->mlx_ptr);
        exit(1); // Adicione verificação de erro
    }
   	init_data_2(data);
   
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
  //  data->click.is_first_click = 0;
     data->msg = "Clear: L";
    //data->msg2 = "Clear: p";
}
