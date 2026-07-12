/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:13:15 by shkrasni          #+#    #+#             */
/*   Updated: 2026/07/12 13:06:09 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "rush02.h"

#define DICTIONARY "../numbers.dict"

int	count_lines(char *str)
{
	int	count;
	int	i;
	int	is_not_empty;

	count = 0;
	i = 0;
	is_not_empty = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			is_not_empty = 1;
		if (str[i] == '\n' && is_not_empty == 1)
		{
			count++;
			is_not_empty = 0;
		}
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
		while (str[size] >= '0' && str[size] <= '9')
			size++;
	else if (turn == 0)
		while ((str[size] >= 32 && str[size] < 126) && str[size] != '\n')
			size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res || (size == 0 && turn == 1))
		return (NULL);
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	trim_ending_spaces(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == ' ')
		len--;
	str[len] = '\0';
}

void	parse_entry(char *str, int *i, t_dict *entry)
{
	while (str[*i] && str[*i] != '\n')
	{
		if (str[*i] >= 32 && str[*i] <= 126
			&& str[*i] != ' ' && str[*i] != ':')
		{
			if (!entry->key)
				entry->key = ft_split(&str[*i], 1);
			else
			{
				entry->value = ft_split(&str[*i], 0);
				trim_ending_spaces(entry->value);
			}
			if (entry->value)
				*i += ft_strlen(entry->value);
			else
				*i += ft_strlen(entry->key);
		}
		else
			(*i)++;
	}
}

t_dict	*parse_dict(char *str)
{
	t_dict	*res;
	int		i;
	int		index;

	res = malloc(sizeof(t_dict) * (count_lines(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		else
		{
			res[index].key = NULL;
			res[index].value = NULL;
			parse_entry(str, &i, &res[index++]);
			if (res[index - 1].key == NULL || res[index - 1].value == NULL)
				return (NULL);
		}
	}
	res[index].key = NULL;
	res[index].value = NULL;
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
	if (a == NULL)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	int i = 0;
	while ((a[i].key != NULL && a[i].value != NULL) || i == 0)
	{
		printf("[%s] - [%s]\n", a[i].key, a[i].value);
		i++;
	}
	free(a);
	// printf("%s \n",buffer);
}