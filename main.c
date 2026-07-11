#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_struct.h"

#define DICTIONARY "numbers.dict"

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
	// printf("%s \n",buffer);
}
