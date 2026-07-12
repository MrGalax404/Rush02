/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathys <nmathys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:40:27 by shkrasni          #+#    #+#             */
/*   Updated: 2026/07/12 17:59:00 by nmathys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	parse_left_to_right(t_dict *tab, char *str, int len, int *is_first);
int		ft_strlen(char *str);
char	*find_in_dict(t_dict *tab, char *key);
int		ft_strcmp(char *s1, char *s2);

int	is_nbr_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, char **dict_file, char **nbr)
{
	if (argc == 2)
	{
		*dict_file = "numbers.dict";
		*nbr = argv[1];
	}
	else if (argc == 3)
	{
		*dict_file = argv[1];
		*nbr = argv[2];
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*content;
	char	*dict_file;
	t_dict	*dict;
	int		is_first;

	is_first = 1;
	if (!parse_args(argc, argv, &dict_file, &nbr))
		return (1);
	if (is_nbr_valid(nbr) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	content = ft_read_file(dict_file);
	if (content == 0)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	dict = parse_dict(content);
	parse_left_to_right(dict, nbr, ft_strlen(nbr), &is_first);
	if (ft_strcmp(nbr, "0\0") == 0)
		ft_putstr(find_in_dict(dict, "0"));
}
