/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:21:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 19:51:11 by sthitiku         ###   ########.fr       */
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

void	mot_init(t_data *data)
{
	t_mot	*mot;

	mot = &data->mot;
	mot->slope = 1;
	mot->shift_x = 0;
	mot->shift_x = 0;
	mot->parr = 0;
	mot->moom = M_PI_4;
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
}
