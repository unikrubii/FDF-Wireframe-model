/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:19:58 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/20 23:31:36 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

long	ft_atoi_hex(char *s)
{
	long	i;
	long	res;
	long	num;

	i = 0;
	res = 0;
	num = 0;
	while (ft_isdigit(s[i]))
		i++;
	while (s[i] == '0' || s[i] == ',' || s[i] == 'x')
		i++;
	while (s[i] != ' ' && s[i] != '\n' && s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			num = s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'z')
			num = s[i] - 'a' + 10;
		else
			num = s[i] - '0';
		res = res * 16 + num;
		i++;
	}
	if (res == 0)
		res = 3355443L;
	return (res);
}

float	abso(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	max_i(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
