/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathys <nmathys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:05:41 by nmathys           #+#    #+#             */
/*   Updated: 2026/07/11 15:10:50 by nmathys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_mag(t_number *tab, int len_left)
{
	char	mag[40];
	int	i;

	if (len_left < 4)
		return ;
	mag [0] = '1';
	i = 1;
	while (i < len_left)
	{
		mag[i] = '0';
		i++;
	}
	mag[i] = '\0';
	ft_putstr(find_in_dict(tab, mag));
}

void	process_tens(t_number *tab, char b, char c)
{
	char str[3];
	if (b == '0' && c == '0')
		return ;
	if (b == '1')
	{
		str[0] = b;
		str[1] = c;
		str[2] = '\0';
		ft_putstr(find_in_dict(tab, str));
		ft_putstr(" ");
	}
	else
	{
		if (b != '0')
		{
			str[0] = b;
			str[1] = '0';
			str[2] = '\0';
			ft_putstr(find_in_dict(tab, str));
			ft_putstr(" ");
		}
		if (b != '0' && c != '0')
			ft_putstr(" ");
		if (c != '0')
		{
			str[0] = c;
			str[1] = '\0';
			ft_putstr(find_in_dict(tab, str));
			ft_putstr(" ");
		}
	}
}

void	process_digits(t_number *tab, char a, char b, char c)
{
	char str[2];

	if (a != '0')
	{
		str[0] = a;
		str[1] = '\0';
		ft_putstr(find_in_dict(tab, str));
		ft_putstr(" ");
		ft_putstr(find_in_dict(tab, 100));
	}
	process_tens(tab, b, c);
}

void	parse_left_to_right(t_number *tab, char *str, int len)
{
	int	i;
	int	m;
	char temp[2];

	i = 0;
	m = len % 3;
	if (m == 1 && str[0] != '0')
	{
		temp[0] = str[0]
		temp[1] = '\0';
		ft_putstr(find_in_dict(tab, str));
		print_mag
		i = i + 1;
	}
	else if (m == 2 && (str[0] != '0' || str[1] != '0'))
	{
		process_tens(tab, str[0], str[1]);
		print_mag
		i = i + 2;
	}
	while (i < len)
	{
		if (str[i] != '0' || str[i + 1] != '0' || str[i + 2] != '0')
		{
			process_digits(tab, src[i], src[i + 1], src[i + 2]);
			print_mag
		}
		i = i + 3;
	}
}
