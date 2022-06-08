/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:01 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/08 14:22:13 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->h = 1;
	fdf->w = 0;
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
		i++;
	}
	free(fdf->map);
	free(fdf);
	fdf = NULL;
}

void	get_map(char *file, t_fdf *fdf)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**map_num;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	fdf->map = (int **)malloc(sizeof(int *) * fdf->h);
	i = 0;
	while (line)
	{
		fdf->map[i] = (int *)malloc(sizeof(int) * fdf->w);
		map_num = ft_split(line, ' ');
		free(line);
		j = -1;
		while (++j < fdf->w)
			fdf->map[i][j] = ft_atoi(map_num[j]);
		free_split(map_num);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	get_dimension(char *file, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i++] != ' ')
			fdf->w++;
	}
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		fdf->h++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_map(file, fdf);
}

void	parse_map(char *file)
{
	t_fdf	*fdf;
	int		i;
	int		j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf_init(fdf);
	get_dimension(file, fdf);
	printf("width = %d\theight = %d\n", fdf->w, fdf->h);
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
	free_st(fdf);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		parse_map(av[1]);
	}
	else
	{
		printf("Usage: ./fdf <file name.fdf>\n");
	}
}
