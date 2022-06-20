/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:21:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/21 00:38:22 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	coor_init(t_coor *coor, t_data *data)
{
	coor->x = data->x;
	coor->y = data->y;
	coor->x1 = data->x1;
	coor->y1 = data->y1;
	coor->z = data->map[(int)data->y][(int)data->x];
	coor->z1 = data->map[(int)data->y1][(int)data->x1];
}

static void	mot_init(t_data *data)
{
	t_mot	*mot;

	mot = &data->mot;
	mot->slope = 1;
	mot->shift_x = 0;
	mot->shift_x = 0;
	mot->parr = 0;
	mot->moom = M_PI_4;
	mot->x_rot = 0.3;
	mot->y_rot = 0;
	mot->z_rot = 0;
}

void	data_init(t_data *data)
{
	mot_init(data);
	data->h = 1;
	data->w = 0;
	data->zoom = 20;
	data->w_check = 0;
	data->m_status = 1;
	data->map = NULL;
	data->c_shift = 0;
}

void	reset(t_data *data)
{
	t_mot	*mot;

	mot = &data->mot;
	mot->x_rot = 0.3;
	mot->y_rot = 0;
	mot->z_rot = 0;
	mot->slope = 1;
	data->c_shift = 0;
}
