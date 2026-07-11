/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkrasni <shkrasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:13:15 by shkrasni          #+#    #+#             */
/*   Updated: 2026/07/11 16:47:34 by shkrasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "dict.h"

int	ft_strlen(char *str);

#define DICTIONARY "numbers.dict"

int	count_lines(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*ft_split(char *str, int turn)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	i = 0;
	if (turn == 1)
		while ((str[size] >= '0' && str[size] <= '9'))
			size++;
	else if (turn == 0)
		while ((str[size] >= 32 && str[size] < 126) && str[size] != '\n')
			size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return res;
}

t_dict	*parse_dict(char *str)
{
	int			i;
	int			index_turn;
	int			t_number_index;
	t_dict	*res;

	res = malloc(sizeof(t_dict) * (count_lines(str) + 1));
	if (!res)
		return (NULL);
	index_turn = 1;
	t_number_index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 126 && str[i] != ' ' && str[i] != ':')
		{
			if (index_turn == 1)
			{
				res[t_number_index].key = ft_split(&str[i], index_turn);
				i += ft_strlen(res[t_number_index].key);
			}
			else if (index_turn == 0)
			{
				res[t_number_index].value = ft_split(&str[i], index_turn);
				i += ft_strlen(res[t_number_index].value);
			}
		}
		if (str[i] == ':')
			index_turn = 0;
		if (str[i] == '\n')
		{
			t_number_index++;
			index_turn = 1;
		}
		i++;
	}
	return (res);
}

int main(int argc, char **argv)
{
	char *nbr;
	if(argc == 2)
		nbr = argv[1];
	else if(argc == 3)
		;
	else
	{
		write(2, "Dict Error\n", 11);
		return 1;
	}

	char buffer[1000];
	int file_descriptor = open(DICTIONARY, O_RDONLY);
	read(file_descriptor, buffer, sizeof(buffer));
	t_dict *a = parse_dict(buffer);
	int i = 0;
	printf("Key : %s\nValue : %s", a[i].key, a[i].value);
	free(a);
	// printf("%s \n",buffer);
}