/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_pressed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:25 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/20 11:52:28 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void key_esc(t_data *data)
{
    free_array(data);
    close_window(data); 
}

void key_l(t_data *data)
{
	clear_window(data, 0x000000); // Limpa a janela com a cor preta
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
    display_message(data); // Exibe a mensagem
}
