/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkrasni <shkrasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:13:07 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/12 19:19:22 by shkrasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*find_in_dict(t_dict *tab, char *key)
{
	int	i;

	i = 0;
	while (tab[i].key != NULL)
	{
		if (ft_strcmp(tab[i].key, key) == 0)
			return (tab[i].value);
		i++;
	}
	return (NULL);
}

int	ft_check_for_max(char *nbr)
{
	int	len;
	int	group_len;
	int	zeros;

	len = ft_strlen(nbr);
	group_len = len % 3;
	if (group_len == 0)
		group_len = 3;
	zeros = len - group_len;
	if (zeros > 36)
		return (0);
	return (1);
}

int	ft_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
