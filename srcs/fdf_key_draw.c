/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:26:32 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 15:16:23 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"
#include "../incs/key.h"

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	free_st(data);
	exit (SUCCESS);
}

int	test_m(t_data *data)
{
	render(data, data->img);
	return (0);
}

int	hook_key(int key, t_data *data)
{
	t_mot	*mot;
	
	mot = &data->mot;
	if (key == K_ESC)
		close_win(data);
	if (key == K_LEFT)
		mot->shift_x -= SHIFT_DIF;
	if (key == K_RIGHT)
		mot->shift_x += SHIFT_DIF;
	if (key == K_UP)
		mot->shift_y -= SHIFT_DIF;
	if (key == K_DOWN)
		mot->shift_y += SHIFT_DIF;
	render(data, data->img);
	return (0);
}
