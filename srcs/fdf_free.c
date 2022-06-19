/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfa_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:54:58 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/17 20:51:13 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

// void	data_init(t_data *data)
// {
// 	data->h = 1;
// 	data->w = 0;
// 	data->zoom = 20;
// 	data->w_check = 0;
// 	data->m_status = 1;
// 	data->map = NULL;
// }

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_st(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h)
	{
		free(data->map[i]);
		free(data->color[i]);
		i++;
	}
	free(data->map);
	free(data->color);
	free(data);
}
