/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:15:18 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 14:38:30 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	put_pix(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bbp / 8));
	if (x >= 0 && x < SC_WIDTH && y >= 0 && y < SC_HEIGHT)
		*(unsigned int *)dst = color;
}

static void	line(t_data *data, t_img *img)
{
	float	x_step;
	float	y_step;
	int		max;
	t_coor	coor;

	coor_init(&coor, data);
	if (coor.z != 0 && data->clrs == 3355443L)
		data->clrs = 0x902020;
	zoom(&coor, data);
	add_3d(&coor, data);
	shift_pos_to_start(&coor, data);
	x_step = coor.x1 - coor.x;
	y_step = coor.y1 - coor.y;
	max = max_i(abso(x_step), abso(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(coor.x - coor.x1) || (int)(coor.y - coor.y1))
	{
		put_pix(img, coor.x, coor.y, data->clrs);
		coor.x += x_step;
		coor.y += y_step;
	}
}

void	render(t_data *data, t_img *img)
{
	t_coor	coor;

	ft_bzero(img->addr, SC_HEIGHT * SC_WIDTH * (img->bbp / 8));
	data->y = 0;
	while (data->y < data->h)
	{
		data->x = 0;
		while (data->x < data->w)
		{
			data->clrs = data->color[(int)data->y][(int)data->x];
			if (data->x < data->w - 1)
			{
				data->x1 = data->x + 1;
				data->y1 = data->y;
				line(data, img);
			}
			if (data->y < data->h - 1)
			{
				data->x1 = data->x;
				data->y1 = data->y + 1;
				line(data, img);
			}
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

void	init_sc(char *file)
{
	t_data	*data;
	t_img	img;
	int		grid;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		mal_err(data);
	parse_map(file, data);
	data->mlx = mlx_init();
	if (!data->mlx)
		mal_err(data);
	data->win = mlx_new_window(data->mlx, SC_WIDTH, SC_HEIGHT, "W T FDF");
	img.img = mlx_new_image(data->mlx, SC_WIDTH, SC_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_l, &img.endian);
	printf("test\n");
	render(data, &img);
	// mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	data->img = &img;
	mlx_hook(data->win, 2, 1L<<0, command, data);
	mlx_hook(data->win, 12, 1L<<15, test_m, data);
	mlx_hook(data->win, 17, 1L<<17, close_win, data);
	mlx_loop(data->mlx);
}
