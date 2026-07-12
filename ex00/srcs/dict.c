/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:13:07 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/12 16:02:52 by nfurst           ###   ########.fr       */
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

char *find_in_dict(t_dict *tab, char *key)
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