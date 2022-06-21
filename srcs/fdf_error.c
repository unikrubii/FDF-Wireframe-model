/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:18:06 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/21 23:28:45 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit (MAP_INVALID);
}

void	mal_err(t_data *data)
{
	ft_putstr_fd("Malloc Error\n", 2);
	if (!data)
		free_st(data);
	close_win(data);
}
