/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:19:58 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/14 21:20:46 by sthitiku         ###   ########.fr       */
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
	while (ft_isdigit(s[i]) || s[i] == ',' || s[i] == 'x')
		i++;
	while(s[i] != ' ' && s[i] != '\n' && s[i])
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
	return (res);
}

char	*ft_itoa_hex(long n)
{
	int		i;
	char	*hex;
	
	hex = (char *)malloc(sizeof(char) * 11);
	hex[0] = '0';
	hex[1] = 'x';
	hex[10] = '\0';
	i = 9;
	while (i > 1)
	{
		hex[i] = "0123456789abfdef"[n % 16];
		n /= 16;
		i--;
	}
	return (hex);
}
