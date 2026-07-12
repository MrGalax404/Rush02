/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:17:05 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/12 18:02:37 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_space(int *is_first)
{
	if (*is_first == 0)
		ft_putstr(" ");
	*is_first = 0;
}
