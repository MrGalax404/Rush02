#ifndef RUSH02_H
# define RUSH02_H

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

/* convert */
int		convert_number(t_dict *tab, char *nb);

/* utils */
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

#endif