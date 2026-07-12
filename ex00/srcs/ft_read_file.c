/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkrasni <shkrasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:56:58 by nfurst            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/12 17:53:51 by nfurst           ###   ########.fr       */
=======
/*   Updated: 2026/07/12 17:27:36 by shkrasni         ###   ########.fr       */
>>>>>>> fc46fc579cfaf84ec464459ef43d8e633895bed0
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_init_read(char *filename, char **dict)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	*dict = malloc(sizeof(char));
	if (*dict == 0)
	{
		close(file);
		return (-1);
	}
	(*dict)[0] = '\0';
	return (file);
}

int	ft_read_loop(int file, char **dict)
{
	char	buffer[1024];
	int		bytes;
	int		total;

	total = 0;
	bytes = read(file, buffer, 1024);
	while (bytes > 0)
	{
		dict = ft_append_dict(dict, total, buffer, bytes);
		if (dict == 0)
			return (0);
		total += bytes;
		bytes = read(file, buffer, 1024);
	}
	if (bytes == -1)
		return (0);
	return (1);
}

char	*ft_append_dict(char *old, int old_size, char *buffer, int buffer_size)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (old_size + buffer_size + 1));
	if (new == 0)
	{
		free(old);
		return (0);
	}
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	i = 0;
	while (i < buffer_size)
	{
		new[i + old_size] = buffer[i];
		i++;
	}
	new[old_size + buffer_size] = '\0';
	free(old);
	return (new);
}

char	*ft_read_file(char *filename)
{
	char	*dict;
	int		file;

	file = ft_init_read(filename, &dict);
	if (file == -1)
		return (0);
	if (!ft_read_loop(file, &dict))
	{
		close(file);
		free(dict);
		return (0);
	}
	close(file);
<<<<<<< HEAD
=======
	if (bytes == -1)
	{
		free(dict);
		return (0);
	}
>>>>>>> fc46fc579cfaf84ec464459ef43d8e633895bed0
	return (dict);
}
