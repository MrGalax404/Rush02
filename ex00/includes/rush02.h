/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:43:00 by shkrasni          #+#    #+#             */
/*   Updated: 2026/07/12 18:04:06 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

typedef struct s_conv
{
	char	*nb;
	int		len;
	int		i;
	int		group_len;
	int		is_first;
}	t_conv;

t_dict	*parse_dict(char *content);
char	*find_in_dict(t_dict *tab, char *key);
char	*ft_read_file(char *filename);
void	parse_left_to_right(t_dict *tab, char *str, int len, int *is_first);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	print_space(int *is_first);

#endif