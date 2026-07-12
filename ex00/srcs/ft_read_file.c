/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:56:58 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/11 14:30:35 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
	char	buffer[1024];
	int		file;
	int		bytes;
	int		total;

	file = open(filename, O_RDONLY, buffer);
	if (file == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	dict = malloc(sizeof(char));
	if (dict == 0)
		return (0);
	dict[0] = '\0';
	bytes = read(file, buffer, 1024);
	total = 0;
	while (bytes > 0)
	{
		dict = ft_append_dict(dict, total, buffer, bytes);
		if (dict == 0)
			return (0);
		total += bytes;
		bytes = read(file, buffer, 1024);
	}
	close(file);
	if (bytes == -1)
	{
		free(dict);
		return(0);
	}
	return (dict);
}
