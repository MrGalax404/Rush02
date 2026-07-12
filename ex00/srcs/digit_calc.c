/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:05:41 by nmathys           #+#    #+#             */
/*   Updated: 2026/07/12 18:02:53 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_mag(t_dict *tab, int len_left, int *is_first)
{
	char	mag[40];
	int		i;

	if (len_left < 4)
		return ;
	print_space(is_first);
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

void	print_dict_elem(t_dict *tab, char c1, char c2)
{
	char	str[3];

	str[0] = c1;
	str[1] = c2;
	str[2] = '\0';
	ft_putstr(find_in_dict(tab, str));
}

void	process_tens(t_dict *tab, char b, char c, int *is_first)
{
	if (b == '0' && c == '0')
		return ;
	print_space(is_first);
	if (b == '1')
		print_dict_elem(tab, b, c);
	else
	{
		if (b != '0')
			print_dict_elem(tab, b, '0');
		if (b != '0' && c != '0')
			ft_putstr(" ");
		if (c != '0')
			print_dict_elem(tab, c, '\0');
	}
}

void	process_digits(t_dict *tab, char *str, int *is_first, int i)
{
	char	tmp[2];

	if (str[i] != '0')
	{
		print_space(is_first);
		tmp[0] = str[i];
		tmp[1] = '\0';
		ft_putstr(find_in_dict(tab, tmp));
		ft_putstr(" ");
		ft_putstr(find_in_dict(tab, "100"));
	}
	process_tens(tab, str[i + 1], str[i + 2], is_first);
}

void	parse_left_to_right(t_dict *tab, char *str, int len, int *is_first)
{
	int		i;
	char	c[2];

	i = len % 3;
	if (i == 1 && str[0] != '0')
	{
		c[0] = str[0];
		print_space(is_first);
		ft_putstr(find_in_dict(tab, &c[0]));
		print_mag(tab, len, is_first);
	}
	else if (i == 2 && (str[0] != '0' || str[1] != '0'))
	{
		process_tens(tab, str[0], str[1], is_first);
		print_mag(tab, len - 1, is_first);
	}
	while (i < len)
	{
		if (str[i] != '0' || str[i + 1] != '0' || str[i + 2] != '0')
		{
			process_digits(tab, str, is_first, i);
			print_mag(tab, ((len - i - 1) / 3) * 3 + 1, is_first);
		}
		i = i + 3;
	}
}
