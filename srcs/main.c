/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:55:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/21 22:48:42 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static int	check_file(char *file)
{
	int		fd;
	int		ret;
	int		readf;
	char	buf[10];
	
	ret = 1;
	fd = open(file, O_RDONLY);
	readf = read(fd, buf, 10);
	if (readf < 0)
		ret = 0;
	close(fd);
	return (ret);
}

static int	ext_correct(char *ext, char *fmt, int len)
{
	int	i;

	if (ft_strlen(ext) != 4)
		return (0);
	i = 0;
	while (i < len)
	{
		if (ext[i] == fmt[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*ext;

	if (ac == 2)
	{
		ext = ft_strrchr(av[1], '.');
		if (!ext_correct(ext, ".fdf", 4))
			error_msg("Not .fdf file\n");
		if (!check_file(av[1]))
			error_msg("File not found\n");
		init_sc(av[1]);
	}
	else
	{
		ft_putstr_fd("Usage: ./fdf <file name.fdf>\n", 2);
		return (55);
	}
}
