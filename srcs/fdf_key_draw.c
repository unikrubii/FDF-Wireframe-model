/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:26:32 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 14:34:35 by sthitiku         ###   ########.fr       */
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

int	command(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == K_ESC)
		close_win(data);
	return (0);
}

int	test_m(t_data *data)
{
	render(data, data->img);
	return (0);
}
