#include <stdio.h>

int main(__attribute__((unused))int argc, char *argv[])
{
	int i = 0;

	for (; argv[i] ; ++i)
		printf("Argumento [%d] : %s\n", i, argv[i]);
	return (0);
}
