/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fil <fil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:58:40 by fil               #+#    #+#             */
/*   Updated: 2024/06/15 23:27:47 by fil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

/*get_next_line*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*Essas linhas são diretivas de pré-processador e não variáveis globais.
 Elas definem macros que são substituídas pelo valor especificado
 durante a fase de pré-processamento do compilador. 
*/

# define WIDTH 1800
# define HEIGHT 1000

typedef struct s_vars
{
	int i;
	int	nb;
	int	count;
	int	negative;
}	t_vars;

typedef struct s_map_size
{
    int cols;
    int lines;
}t_map_size;

typedef struct s_map_array
{
    int n;
    int	org_val;
    int	wall;
    int iso_x;
    int iso_y;
    int color;
}   t_map_array;

/* s_data its to write pixels into image*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int     win_width;
    int     win_height;
    int		scale_factor;
    int		pos_x;
    int		pos_y;
	//t_click click;
	char	*msg;
	t_map_array	**matrix;
	t_map_size	size;
}			t_data;

typedef struct s_line {
    int x0;
    int y0;
    int x1;
    int y1;
    int color;
}           t_line;

typedef struct s_bresenham {
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
}           t_bresenham;

/*get_next_line*/
char	*gnl_remake(char *str);
char	*gnl_get_line(char *str);
char	*gnl_last_row(char **str);
char	*gnl_check_buffer(int fd, char *res, ssize_t *bytes);
char	*get_next_line(int fd);
size_t	gnl_ft_strlen(const char *str);
char	*gnl_ft_strcpy_index(char *dst, const char *src,
			size_t ind_dst, size_t ind_src);
char	*gnl_ft_strjoin_nfree(char *src1, char *src2);
char	*gnl_ft_strjoin(char *src1, char *src2, int *eof);


/*creat map *** read_map.c*/
void    free_array(t_data *data);
void	free_line_error(t_data *data, int index);
//t_map_array** create_array(const char *map);
void	create_array(const char *map, t_data *data);
void fill_org_val(t_data *data);


/*size.c*/

void map_size(const char *map, t_data *data);
int counter(const char *s, int last_count);

/*fill_array.c*/
//void	fill_n(int nb, t_map_array ***array, int line, int col);
//void	array_data(t_map_array ***array, int array_line, const char *line);
//t_map_array** fill_array(t_map_array ***array, t_map_size *size, const char *map);
void fill_wall(t_data *data);
void	fill_n(int nb, t_data *data, int line, int col);
void fill_array(t_data *data, const char *map);
void	array_data(t_data *data, int array_line, const char *line);

/*x_y_calcul.c*/
void	isometric(int *x, int *y, int z);
//void	isometric(int *x, int *y, t_data *data);
void	init_data_2(t_data *data);
void  x_y_iso_calcul(t_data *data);

/*init.c*/
void	init_data(t_data *data);
void	init_data_2(t_data *data);
void	init_data_3(t_data *data);

/*hook.c*/

void key_esc(t_data *data);
void key_l(t_data *data);

void original_value(t_data *data);
void    setup_hooks(t_data *data);
//int key_pressed(int keycode, void *param);
int key_pressed(int keycode, t_data *data);
void key_plus(t_data *data);
void key_minus(t_data *data);

void	display_map(t_data *data);

/*window_img.c*/
void display_message(t_data *img);
void	update_window(t_data *data);
int close_window(void *param);
void clear_window(t_data *img, int color);

int	ft_abs(int nb);
void calculate_bresenham(t_line *line, t_bresenham *bres);
void draw_line_bresenham(t_data *img, t_line *line, t_bresenham *bres);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/*projection.c*/
void	project(t_data *data);
void	project2(t_data *data);

#endif
