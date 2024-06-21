/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:47:00 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/18 13:47:04 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void    setup_hooks(t_data *data)
{
    mlx_key_hook(data->mlx_win, key_pressed, data);
    mlx_hook(data->mlx_win, 17, 0, close_window, data);
 //   mlx_mouse_hook(data->mlx_win, mouse_win1, data);

}

void original_value(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < data->size.lines)
	{
		j = 0;
		while (j < data->size.cols)
		{	
			data->matrix[i][j].n = data->matrix[i][j].org_val;		
			j++;
		}
		i++;
	}
	display_map(data);
}

void key_plus(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < data->size.lines)
	{
		j = 0;
		while (j < data->size.cols)
		{
			if (data->matrix[i][j].wall == 1)
			{
				if (data->matrix[i][j].org_val > 0)
					data->matrix[i][j].n += 5;
				if (data->matrix[i][j].org_val < 0)
					data->matrix[i][j].n -= 5;
			}
			j++;
		}
		i++;
	}
	display_map(data);
}

void key_minus(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < data->size.lines)
	{
		j = 0;
		while (j < data->size.cols)
		{
			if (data->matrix[i][j].wall == 1 && data->matrix[i][j].n != 0)
			{
				if (data->matrix[i][j].org_val > 0)
					data->matrix[i][j].n -= 5;
				if (data->matrix[i][j].org_val < 0)
					data->matrix[i][j].n += 5;
			}
			j++;
		}
		i++;
	}
	display_map(data);
}

/*ou xk_Escape  #include <X11/keysym.h> 
   	if (keycode == 65307) */


 /*close window apaga o data,se apagar matrix depois da erro pq ja nao exist*/
int key_pressed(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
    if (keycode == XK_Escape)
    	key_esc(data);  
    else if (keycode == 108) // Tecla L para limpar
    	key_l(data);
     else if (keycode == 65451 || keycode == XK_equal)
        key_plus(data);
     else if (keycode == 65453)
        key_minus(data);
     else if (keycode == 111)
     	original_value(data);
    return (0);
}
