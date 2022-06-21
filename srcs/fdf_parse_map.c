/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:07:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/21 20:55:27 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	get_map(char *file, t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	**map_num;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < data->h)
	{
		data->ln = get_next_line(fd);
		map_num = ft_split(data->ln, ' ');
		free(data->ln);
		j = -1;
		while (++j < data->w)
		{
			data->map[i][j] = ft_atoi(map_num[j]);
			data->color[i][j] = ft_atoi_hex(map_num[j]);
		}
		free_split(map_num);
		i++;
	}
	data->ln = get_next_line(fd);
	close(fd);
}

void	map_alloc(t_data *data)
{
	int	i;
	int	j;

	data->map = (int **)malloc(sizeof(int *) * data->h);
	data->color = (long **)malloc(sizeof(long *) * data->h);
	i = 0;
	while (i < data->h)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->w);
		data->color[i] = (long *)malloc(sizeof(long) * data->w);
		j = 0;
		while (j < data->w)
		{
			data->map[i][j] = 0;
			data->color[i][j] = 0L;
			j++;
		}	
		i++;
	}
}

static void	get_dimension(char *file, t_data *data)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	data->ln = get_next_line(fd);
	i = 0;
	while (data->ln[i] != '\n')
	{
		while (data->ln[i] == ' ')
			i++;
		while (data->ln[i] != ' ' && data->ln[i] != '\n' && data->ln[i])
			i++;
		data->w++;
		while (data->ln[i] == ' ')
			i++;
	}
	free(data->ln);
	data->ln = get_next_line(fd);
	while (data->ln)
	{
		data->h++;
		free(data->ln);
		data->ln = get_next_line(fd);
	}
	close(fd);
}

static int	map_valid(char *file, t_data *d)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	d->ln = get_next_line(fd);
	while (d->ln)
	{
		i = 0;
		d->w_check = 0;
		while (d->ln[i] != '\n')
		{
			if (d->ln[i++] != ' ')
			{
				while (d->ln[i] != ' ' && d->ln[i] != '\n' && d->ln[i])
					i++;
				d->w_check++;
			}
		}
		if (d->w_check != d->w)
			d->m_status = 0;
		free(d->ln);
		d->ln = get_next_line(fd);
	}
	close(fd);
	return (d->m_status);
}

t_data	*parse_map(char *file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		mal_err(data);
	data_init(data);
	get_dimension(file, data);
	if (!map_valid(file, data))
		error_msg("Invalid Map\n");
	map_alloc(data);
	get_map(file, data);
	return (data);
}
