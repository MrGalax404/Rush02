#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "rush02.h"

int	is_nbr_valid(char *str)
{
	int i = 0;
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <='9'))
			return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	char 	*nbr;
	char	*content;
	t_dict	*dict;

	if(argc == 2)
		nbr = argv[1];
	else if(argc == 3)
	{
		nbr = argv[2];
	}
	else
	{
		write(2, "Dict Error\n", 11);
		return 1;
	}
	content = read_file("numbers.dict");
	if (content == 0)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	t_dict *dict = parse_dict(content);
	if (!convert_number(dict, nbr))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
}
