#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "dict.h"

#define DICTIONARY "numbers.dict"

int	is_nbr_valid(char *str)
{
	int res = 0;
	int i = 0;
	
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
