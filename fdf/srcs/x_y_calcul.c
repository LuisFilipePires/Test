/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:31:26 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/17 18:31:29 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/*esta parte pega no valor que esta em t_map_array.n e calcula
a posicao de x e de y relativamente ao valor de .n, para a projecao
isometrica*/
void	isometric(int *x, int *y, int z)
{
	int tmp_x;
	int tmp_y;

	//printf(" z : %d,", z);
	
	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(0.523599);
	*y = (tmp_x + tmp_y) * sin(0.523599) - z;

}
/*esta funcao é apenas para ver as coordenandas*/
/*scale factor esta inicializado em data 
tambem pos_x  para ao alerar no teclado apenas vai la*/
void  x_y_iso_calcul(t_data *data)
{
	int i;
	int	j;
 	int	x;
 	int	y;
 	int z;
 
 	i = 0;
    while (i < data->size.lines)
    {
  	  	j = 0;
    	while (j < data->size.cols)
        {     
     //       x = j * (10 * data->scale_factor);
    //       	y = i * (10 * data->scale_factor);
              x = j * ( data->scale_factor);
           	y = i * ( data->scale_factor);
           	z = data->matrix[i][j].n;
           	isometric(&x, &y, z);
           	data->matrix[i][j].iso_x = x + data->pos_x;
           	data->matrix[i][j].iso_y = y + data->pos_y;
           	j++;
       	}
       	i++;
   	}
}
/*
void project_matrix(t_array_map **matrix, int lines, int cols)
{
	int i;
	int j;
	t_data	img;
	//t_line line;
	t_line line = {0, 0, 100, 100, 0xFFFFFF};//testes  // para desenhar linha********
	t_bresenham bres;				//para desenhar linha************
	//-----ver para libertar pq esta parte da leaks
	  	calculate_bresenham(&line, &bres);  //  para desenhar linha************
    draw_line_bresenham(&img, &line, &bres);	//para desenhar linha/************
	puts("ENTROU");
	printf("line: %d, cols:%d\n", lines, cols);
  
	i = 0;
	*/
/*	while (i < lines)
	{
	puts("entrou 2");
		j = 0;
		while (j < cols - 2)
		{
		    printf("i = %d, j = %d", i, j);
			line.x0 = matrix[i][j].x_iso;
			line.y0 = matrix[i][j].y_iso;
			line.x1 = matrix[i][j + 1].x_iso;
			line.y1 = matrix[i][j + 1].y_iso;
			line.color = 0xFFFFFF;
			t_bresenham bres;
			calculate_bresenham(&line, &bres);
			draw_line_bresenham(&img, &line, &bres);
			j++;
		}
		i++;
	}	
	
*/
//}





