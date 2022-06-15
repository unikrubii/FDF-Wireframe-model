/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:01 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/14 23:46:27 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	get_map(char *file, t_fdf *fdf)
{
	int		fd;
	int		i;
	int		j;
	char	**map_num;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < fdf->h)
	{
		fdf->ln = get_next_line(fd);
		map_num = ft_split(fdf->ln, ' ');
		free(fdf->ln);
		j = -1;
		while (++j < fdf->w)
		{
			fdf->map[i][j] = ft_atoi(map_num[j]);
			fdf->color[i][j] = ft_atoi_hex(map_num[j]);
		}
		free_split(map_num);
		i++;
	}
	fdf->ln = get_next_line(fd);
	close(fd);
}

void	map_alloc(t_fdf *fdf)
{
	int	i;

	fdf->map = (int **)malloc(sizeof(int *) * fdf->h);
	fdf->color = (long **)malloc(sizeof(long *) * fdf->h);
	i = 0;
	while (i < fdf->h)
	{
		fdf->map[i] = (int *)malloc(sizeof(int) * fdf->w);
		fdf->color[i] = (long *)malloc(sizeof(long) * fdf->w);
		i++;
	}
}

static void	get_dimension(char *file, t_fdf *fdf)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	fdf->ln = get_next_line(fd);
	i = 0;
	while (fdf->ln[i] != '\n')
	{
		while (fdf->ln[i] != ' ' && fdf->ln[i] != '\n' && fdf->ln[i])
			i++;
		fdf->w++;
		while (fdf->ln[i] == ' ')
			i++;
	}
	free(fdf->ln);
	fdf->ln = get_next_line(fd);
	while (fdf->ln)
	{
		fdf->h++;
		free(fdf->ln);
		fdf->ln = get_next_line(fd);
	}
	close(fd);
}

static int	map_valid(char *file, t_fdf *fdf)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	fdf->ln = get_next_line(fd);
	while (fdf->ln)
	{
		i = 0;
		fdf->w_check = 0;
		while (fdf->ln[i] != '\n')
		{
			if (fdf->ln[i++] != ' ')
			{
				while (fdf->ln[i] != ' ' && fdf->ln[i] != '\n' && fdf->ln[i])
					i++;
				fdf->w_check++;
			}
		}
		if (fdf->w_check != fdf->w)
			fdf->m_status = 0;
		free(fdf->ln);
		fdf->ln = get_next_line(fd);
	}
	close(fd);
	return (fdf->m_status);
}

void	parse_map(char *file, t_fdf *fdf)
{
	int		i;
	int		j;

	fdf_init(fdf);
	get_dimension(file, fdf);
	if (!map_valid(file, fdf))
		error_msg("Invalid Map\n");
	map_alloc(fdf);
	get_map(file, fdf);
	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			printf("%3d", fdf->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		init_sc(av[1]);
	}
	else
	{
		ft_putstr_fd("Usage: ./fdf <file name.fdf>\n", 2);
	}
}
