/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:11:30 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/12 16:18:35 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush02.h"

int ft_init_conv(t_conv *conv, char *nbr)
{
    while (*nbr == '0')
        nbr++;
    conv->nb = nbr;
    conv->is_first = 1;
    if (*nbr == '\0')
        return (0);
    conv->len = ft_strlen(nbr);
    conv->i = 0;
    conv->group_len = conv->len % 3;
    if (conv->group_len == 0)
        conv->group_len = 3;
    return (1);
}

int ft_convert_loop(t_dict *tab, t_conv *conv)
{
    char group[4];

    while (conv->i < conv->len)
    {
        ft_fill_group(group, conv->nb + conv->i, conv->group_len);
        if (!ft_group_is_zero(group))
        {
            if (!ft_print_group(tab, group, &conv->is_first))
                return (0);
            if (!ft_print_scale(tab, conv->len - conv->i - conv->group_len, &conv->is_first))
                return (0);
        }
        conv->i += conv->group_len;
        conv->group_len = 3;
    }
    return (1);
}

int	ft_max_scale_valid(char *nbr)
{
	int len;
	int group_len;
	int zeros;

	len = ft_strlen(nbr);
	group_len = len % 3;
	if (group_len == 0)
		group_len = 3;
	zeros = len - group_len;
	if (zeros > 36)
		return (0);
	return (1);
}

int	ft_convert_number(t_dict *tab, char *nbr)
{
	t_conv	conv;

	while (*nbr == '0')
	{
		nbr++;
	}
	if (!ft_max_scale_valid(nbr))
		return (0);
    if (!ft_init_conv(&conv, nbr))
    {
        if (!ft_print_key(tab, "0", &conv.is_first))
            return (0);
        write(1, "\n", 1);
	    return (1);
    }
    if (!ft_convert_loop(tab, &conv))
        return (0);
    write(1, "\n", 1);
    return (1);
}
