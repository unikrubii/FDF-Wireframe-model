/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:19:36 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 21:47:59 by sthitiku         ###   ########.fr       */
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
	if (!data->mot.parr)
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

void	rot_x(t_coor *coor, t_data *data)
{
	coor->z = coor->z * cos(data->mot.x_rot);
	coor->x = coor->x * cos(data->mot.x_rot);
	coor->z1 = coor->z1 * cos(data->mot.x_rot);
	coor->x1 = coor->x1 * cos(data->mot.x_rot);
}

void	rot_y(t_coor *coor, t_data *data)
{
	coor->z = coor->z * cos(data->mot.y_rot);
	coor->y = coor->y * cos(data->mot.y_rot);
	coor->z1 = coor->z1 * cos(data->mot.y_rot);
	coor->y1 = coor->y1 * cos(data->mot.y_rot);
}

void	rot_z(t_coor *coor, t_data *data)
{
	coor->x = coor->x * cos(data->mot.z_rot) - \
	coor->y * sin(data->mot.z_rot);
	coor->y = coor->y * cos(data->mot.z_rot) + \
	coor->y * cos(data->mot.z_rot);
	coor->x1 = coor->x1 * cos(data->mot.z_rot) - \
	coor->y1 * sin(data->mot.z_rot);
	coor->y1 = coor->y1 * cos(data->mot.z_rot) + \
	coor->y1 * cos(data->mot.z_rot);
}

void	rotate(t_coor *coor, t_data *data)
{
	// rot_x(coor, data);
	// rot_y(coor, data);
	// rot_z(coor, data);
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