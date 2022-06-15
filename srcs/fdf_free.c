/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:54:58 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/14 22:25:11 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->h = 1;
	fdf->w = 0;
	fdf->w_check = 0;
	fdf->m_status = 1;
	fdf->map = NULL;
}

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

void	free_st(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->h)
	{
		free(fdf->map[i]);
		free(fdf->color[i]);
		i++;
	}
	free(fdf->map);
	free(fdf->color);
}
