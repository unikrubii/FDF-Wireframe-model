/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:35 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/17 20:53:25 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif

# define SUCCESS 0
# define MAP_INVALID 1
# define MALLOC_ERR 10

# define SC_WIDTH 1500
# define SC_HEIGHT 800

typedef struct s_coor
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
	int		slope;
	long	color;
}	t_coor;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_mot
{
	int				shift_x;
	int				shift_y;
	int				parr;
	float			slope;
	float			moom;
	float			x_rot;
	float			y_rot;
	float			z_rot;
}	t_mot;

typedef struct s_data
{
	int		w;
	int		h;
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		w_check;
	int		m_status;
	int		zoom;
	float	slope;
	float	x_rot;
	int		**map;
	long	**color;
	long	clrs;
	void	*mlx;
	void	*win;
	char	*ln;
	t_img	*img;
	t_mot	mot;
}	t_data;

void	data_init(t_data *data);
void	free_split(char **str);
void	free_st(t_data *data);
void	init_sc(char *file);
t_data	*parse_map(char *file);

long	ft_atoi_hex(char *s);
float	abso(int n);
int		max_i(float a, float b);

void	draw(t_img *img, int x, int y, unsigned int color);
void	coor_init(t_coor *coor, t_data *data);

void	error_msg(char *msg);
void	mal_err(t_data *data);

void	init_sc(char *file);
void	render(t_data *data, t_img *img);
void	add_3d(t_coor *coor, t_data *data);
void	rotate(t_coor *coor, t_data *data);

int		hook_key(int key, t_data *data);
int		close_win(t_data *data);
int		test_m(t_data *data);

#endif