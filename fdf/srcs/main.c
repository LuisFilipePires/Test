/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fil <fil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:28:45 by fil               #+#    #+#             */
/*   Updated: 2024/06/19 09:24:11 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data		data;
	if (argc > 1)
	{	
		
		init_data(&data);
		create_array(argv[1], &data);
		
		project(&data);
		display_message(&data);
	//	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	
	
	/*
	for(int i = 0; i < data.size.lines; i++)
	{
		puts("");
		for (int j = 0; j < data.size.cols; j++)
		{
			printf("%d", data.matrix[i][j].wall);
		}
	}
	*/
	/*
	for(int i = 0; i < data.size.lines; i++)
	{
		puts("");
		for (int j = 0; j < data.size.cols; j++)
		{
			printf(" %d  ", data.matrix[i][j].n);
		}
	}*/
		
		setup_hooks(&data);
	//	free_array(&data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
