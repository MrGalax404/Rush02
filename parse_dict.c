/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkrasni <shkrasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:13:15 by shkrasni          #+#    #+#             */
/*   Updated: 2026/07/11 15:54:26 by shkrasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_struct.h"

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_split(char *str)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	i = 0;
	while ((str[size] > 33 && str[size] < 126) && (str[size] != ':' && str[size] != ' '))
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	return res;
}

t_number	*parse_dict(char *str)
{
	int			i;
	int			index_turn;
	int			t_number_index;
	t_number	*res;

	res = malloc(sizeof(t_number) * (count_lines(str) + 1));
	if (!res)
		return (NULL);
	index_turn = 1;
	t_number_index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 33 && str[i] < 126 && str[i] != ' ')
		{	
			if (index_turn == 1)
			{
				res[t_number_index].index = ft_split(&str[i]);
				i += ft_strlen(res[t_number_index].index);
			}
			else if (index_turn == 0)
			{
				res[t_number_index].word = ft_split(&str[i]);
				i += ft_strlen(res[t_number_index].word);
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
	t_number *a = parse_dict(buffer);
	int i = 41;
	printf("Index : %s\nWord : %s", a[i].index, a[i].word);
	free(a);
	// printf("%s \n",buffer);
}