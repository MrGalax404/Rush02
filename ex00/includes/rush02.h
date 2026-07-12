/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkrasni <shkrasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:43:00 by shkrasni          #+#    #+#             */
/*   Updated: 2026/07/12 17:43:15 by shkrasni         ###   ########.fr       */
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

/* dict */
t_dict	*parse_dict(char *content);
char	*find_in_dict(t_dict *tab, char *key);
void	free_dict(t_dict *dict);
char	*ft_read_file(char *filename);

/* convert */
int		ft_print_digit(t_dict *tab, char c, int *is_first);
int		ft_print_two(t_dict *tab, char a, char b, int *is_first);
int		ft_print_key(t_dict *tab, char *key, int *is_first);
int		ft_convert_number(t_dict *tab, char *nb);
int		ft_group_is_zero(char *group);
int		ft_print_group(t_dict *tab, char *group, int *is_first);
int		ft_print_scale(t_dict *tab, int zeros, int *is_first);
void	ft_fill_group(char *group, char *nb, int group_len);

/* utils */
int		ft_strlen(char *str);
void	ft_putstr(char *str);

#endif