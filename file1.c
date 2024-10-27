#include <stdlib.h>
#include <string.h>
#include "functions.h"

int check(int argc, char **argv)
{
	if (argc != 2)
		return (1);        
	if (ft_strlen(argv[1]) != 31)
		return (1);
	return (0);
}

int *get_numbers(char *str)
{
	int i;
	int j;
	int *tab;

	if (!(tab = malloc(sizeof(int) * 16)))
		return (0);
	i = 0;
	j = 0;
	while (str[i] && tab[j])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tab[j] = ft_atoi(&str[i]);
		}
	}
	return (tab);
}
