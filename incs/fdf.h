/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:35 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/14 22:57:15 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif

# define SC_WIDTH 800
# define SC_HEIGHT 800
# define MAP_INVALID 1

typedef struct s_fdf
{
	int		w;
	int		h;
	int		w_check;
	int		m_status;
	int		**map;
	long	**color;
	void	*mlx;
	void	*win;
	char	*ln;
} t_fdf;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	fdf_init(t_fdf *fdf);
void	free_split(char **str);
void	free_st(t_fdf *fdf);
void	init_sc(char *file);
void	parse_map(char *file, t_fdf *fdf);
long	ft_atoi_hex(char *s);
char	*ft_itoa_hex(long n);

void	draw(t_data *data, int x, int y, int color);

void	error_msg(char *msg);

#endif