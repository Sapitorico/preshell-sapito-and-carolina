#include <stdio.h>

int main(__attribute__((unused)) int ac, char **av)
{
	int i;
	
	for (i = 0;  av [i] != NULL; i++)
	{
	printf("%s\n", av[i]);
	}
	return(0);
}
