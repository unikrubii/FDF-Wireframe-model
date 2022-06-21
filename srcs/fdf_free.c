/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:30:49 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/21 23:27:48 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

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
