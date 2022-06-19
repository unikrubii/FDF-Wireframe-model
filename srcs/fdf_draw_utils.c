/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:19:36 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/19 00:48:58 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	add_3d(t_coor *coor, t_data *data)
{
	coor->x = (coor->x - coor->y) * cos(0.8 * 1);
	coor->y = (coor->x + coor->y) * sin(0.8 * 1) - (coor->z * 1);
	coor->x1 = (coor->x1 - coor->y1) * cos(0.8 * 1);
	coor->y1 = (coor->x1 + coor->y1) * sin(0.8 * 1) - (coor->z1 * 1);
}

void	zoom(t_coor *coor, t_data *data)
{
	coor->x *= data->zoom;
	coor->y *= data->zoom;
	coor->x1 *= data->zoom;
	coor->y1 *= data->zoom;
}

void	shift_pos_to_start(t_coor *coor, t_data *data)
{
	coor->x += 400;
	coor->y += 350;
	coor->x1 += 400;
	coor->y1 += 350;
}
