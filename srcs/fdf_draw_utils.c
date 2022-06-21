/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:19:36 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/21 16:00:35 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	add_3d(t_coor *coor, t_data *data)
{
	if (data->zoom < 2)
		data->zoom = 2;
	coor->x *= data->zoom;
	coor->y *= data->zoom;
	coor->x1 *= data->zoom;
	coor->y1 *= data->zoom;
	if (data->mot.parr != 2)
	{
		coor->x = (coor->x - coor->y) * cos(data->mot.moom);
		coor->y = (coor->x + coor->y) * sin(data->mot.moom) - \
		(coor->z * data->mot.slope);
		coor->x1 = (coor->x1 - coor->y1) * cos(data->mot.moom);
		coor->y1 = (coor->x1 + coor->y1) * sin(data->mot.moom) - \
		(coor->z1 * data->mot.slope);
	}
	coor->x += (650 + data->mot.shift_x);
	coor->y += (300 + data->mot.shift_y);
	coor->x1 += (650 + data->mot.shift_x);
	coor->y1 += (300 + data->mot.shift_y);
}

void	rotate(t_coor *coor, t_data *data)
{
	coor->z = coor->z * cos(data->mot.x_rot);
	coor->x = coor->x * cos(data->mot.x_rot);
	coor->z1 = coor->z1 * cos(data->mot.x_rot);
	coor->x1 = coor->x1 * cos(data->mot.x_rot);
	coor->z = coor->z * cos(data->mot.y_rot);
	coor->y = coor->y * cos(data->mot.y_rot);
	coor->z1 = coor->z1 * cos(data->mot.y_rot);
	coor->y1 = coor->y1 * cos(data->mot.y_rot);
	coor->x = coor->x * cos(data->mot.z_rot) - \
	coor->y * sin(data->mot.z_rot);
	coor->y = coor->y * cos(data->mot.z_rot) + \
	coor->y * cos(data->mot.z_rot);
	coor->x1 = coor->x1 * cos(data->mot.z_rot) - \
	coor->y1 * sin(data->mot.z_rot);
	coor->y1 = coor->y1 * cos(data->mot.z_rot) + \
	coor->y1 * cos(data->mot.z_rot);
}

void	instruction(t_data *data)
{
	char	*str;

	str = "UP, DOWN, LEFT, RIGHT: Move Picture";
	mlx_string_put(data->mlx, data->win, 20, 50, 0xfcba03, str);
	str = "-, =: Zoom in/out";
	mlx_string_put(data->mlx, data->win, 20, 65, 0xfcba03, str);
	str = "L, K: Altitude increase/decrease";
	mlx_string_put(data->mlx, data->win, 20, 80, 0xfcba03, str);
	str = "P: Projection <iso/top view/side view>";
	mlx_string_put(data->mlx, data->win, 20, 95, 0xfcba03, str);
	str = "A, D: Rotate around x-axis";
	mlx_string_put(data->mlx, data->win, 20, 110, 0xfcba03, str);
	str = "W, S: Rotate around y-axis";
	mlx_string_put(data->mlx, data->win, 20, 125, 0xfcba03, str);
	str = "Q, E: Rotate around something-axis";
	mlx_string_put(data->mlx, data->win, 20, 140, 0xfcba03, str);
	str = "I, O: Change color <Disco?>";
	mlx_string_put(data->mlx, data->win, 20, 155, 0xfcba03, str);
	str = "R: Reset altitude, rotation, color";
	mlx_string_put(data->mlx, data->win, 20, 170, 0xfcba03, str);
}
