/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathys <nmathys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:05:41 by nmathys           #+#    #+#             */
/*   Updated: 2026/07/11 14:36:32 by nmathys          ###   ########.fr       */
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