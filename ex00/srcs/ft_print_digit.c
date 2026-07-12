/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:27:44 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/12 15:05:37 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void ft_print_space(int *is_first)
{
    if (*is_first == 0)
        ft_putstr(" ");
    *is_first = 0;
}

int ft_print_key(t_dict *tab, char *key, int *is_first)
{
    char *value;
    
    value = find_in_dict(tab, key);
    if (value == 0)
        return (0);
    ft_print_space(is_first);
    ft_putstr(value);
    return (1);
}

int ft_print_digit(t_dict *tab, char c, int *is_first)
{
    char key[2];

    key[0] = c;
    key[1] = '\0';
    return (ft_print_key(tab, key, is_first));
}

int ft_print_two(t_dict *tab, char a, char b, int *is_first)
{
    char key[3];

    key[0] = a;
    key[1] = b;
    key[2] = '\0';
    return (ft_print_key(tab, key, is_first));
}

int ft_print_scale(t_dict *tab, int zeros, int *is_first)
{
    char key[40];
    int i;

    if (zeros == 0)
        return (1);
    if (zeros % 3 != 0)
        return (0);
    key[0] = '1';
    i = 1;
    while (i < zeros)
    {
        key[i] = '0';
        i++;
    }
    key[i] = '\0';
    return (ft_print_key(tab, key, is_first));
}
