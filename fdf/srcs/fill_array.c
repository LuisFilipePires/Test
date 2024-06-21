/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:40:54 by luis-fif          #+#    #+#             */
/*   Updated: 2024/06/17 14:59:59 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*esta parte serve para ler o mapa e colocar cara numero no grafico
ja criado em struct t_map_array.n*/
void	fill_n(int nb, t_data *data, int line, int col)
{
//	printf("nb: %d,",nb);
	if (nb > 0 || nb < 0)
		data->matrix[line][col].wall = 1;
	data->matrix[line][col].n = nb;
	data->matrix[line][col].org_val = nb;
}

int	is_negative(char c)
{
	if (c == '-')
	{
//		puts("negativo");
		return (1);
	}
	return(0);
}

void	array_data(t_data *data, int array_line, const char *line)
{
	t_vars v;

	v.count = 0;
	v.i = 0;
	while (line[v.i])
	{
		v.negative = is_negative(line[v.i]);
		if (v.negative)
			v.i++;
		if (line[v.i] >= '0' && line[v.i] <= '9')
		{
			v.nb = 0;
			while (line[v.i] >= '0' && line[v.i] <= '9')
			{
				v.nb = v.nb * 10 + (line[v.i] - '0');
				v.i++;
			}
			if (v.negative == 1)
				v.nb = v.nb * -1;			
			fill_n(v.nb, data, array_line, v.count);
			v.count++;
		}
		v.i++;
	}
}

/*
//este codigo original para pegar nos numerod do mapa
void	array_data(t_data *data, int array_line, const char *line)
{
	int i;
	int	nb;
	int	count;
	int	negative;

	count = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == 32)
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			nb = 0;
			while (line[i] >= '0' && line[i] <= '9')
			{
				nb = nb * 10 + (line[i] - '0');
				i++;
			}
				fill_n(nb, data, array_line, count);
				count++;
		}
		i++;
	}
}

*/
/*aqui ex: array_line 2, vai no data.matrix[1] e preenche as colunas*/
/*a cada linha que se encontra preenche as colunas*/
void fill_array(t_data *data, const char *map)
{
	int		fd;
	int		array_line;
	char	*text;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(1);
	text = get_next_line(fd);
	array_line = 0;
	while (text != NULL)
	{
		array_data(data, array_line, text);
		free(text);
		text = get_next_line(fd);		
		array_line++;
	}
	close (fd);
	free(text);
	init_data_3(data);
	x_y_iso_calcul(data);
}
