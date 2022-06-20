/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:26:32 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 23:31:04 by sthitiku         ###   ########.fr       */
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

void	hook_3(int key, t_data *data, t_mot *mot)
{
	if (key == K_R)
		reset(data);
	if (key == K_P)
	{
		if (mot->parr == 0)
			mot->parr = 2;
		else if (mot->parr == 2)
		{
			mot->parr = 1;
			mot->moom = 0;
		}
		else
		{
			mot->parr = 0;
			mot->moom = M_PI_4;
		}
	}
}

void	hook_2(int key, t_data *data, t_mot *mot)
{
	if (key == K_A)
		mot->x_rot += 0.1;
	if (key == K_D)
		mot->x_rot -= 0.1;
	if (key == K_W)
		mot->y_rot += 0.1;
	if (key == K_S)
		mot->y_rot -= 0.1;
	if (key == K_I)
		data->c_shift += C_SHIFT;
	if (key == K_O)
		data->c_shift -= C_SHIFT;
	if (key == K_PLUS)
	{
		data->zoom += ZOOM_DIF;
		mot->slope += 0.05;
	}
	if (key == K_MINUS)
	{
		data->zoom -= ZOOM_DIF;
		mot->slope -= 0.05;
	}
	else
		hook_3(key, data, mot);
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
	if (key == K_L)
		mot->slope *= SLOPE_DIF;
	if (key == K_K)
		mot->slope /= SLOPE_DIF;
	if (key == K_Q)
		mot->z_rot += 0.1;
	if (key == K_E)
		mot->z_rot -= 0.1;
	else
		hook_2(key, data, mot);
	render(data, data->img);
	return (0);
}
