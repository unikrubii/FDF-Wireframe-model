/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:56:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/14 23:47:28 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	draw(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_sc(char *file)
{
	t_fdf	fdf;
	t_data	img;
	int		grid;
	int		i;
	int		j;

	// fdf = (t_fdf *)malloc(sizeof(t_fdf));
	parse_map(file, &fdf);
	grid = SC_WIDTH / fdf.w;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, SC_WIDTH, SC_HEIGHT, "WTFDF");
	img.img = mlx_new_image(fdf.mlx, SC_WIDTH, SC_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("%d\t%d\n", img.line_length, img.bits_per_pixel);
	i = 0;
	j = 0;
	while (i < 800)
	{
		j = 0;
		while (j < 800)
		{
			if (i % grid == 0 || j % grid == 0)
			{
				// printf("%d\n", fdf.map[i / grid][j / grid]);
				draw(&img, i, j, 0xFFFF);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.win, img.img, 0, 0);
	mlx_loop(fdf.mlx);
	free_st(&fdf);
}
