/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:35 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/09 20:34:46 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define SC_WIDTH 800
# define SC_HEIGHT 800

typedef struct s_fdf
{
	int		w;
	int		h;
	int		**map;
	void	*mlx;
	void	*win;
} t_fdf;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif