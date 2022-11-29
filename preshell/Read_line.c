#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0, caracteres = 0;

	printf("$ ");
	caracteres = getline(&buffer, &bufsize, stdin);
	if (caracteres == -1)
	{
		perror("Bad arguments");
		free(buffer);
		exit(1);
	}
	printf("cadena de entrada: %scaracteres: %ld\ntamaño del buffer: %ld\n", buffer, caracteres, bufsize);
	free(buffer);
	return (0);
}
