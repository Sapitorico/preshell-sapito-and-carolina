#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[100] = "Me aburro, como la gran. hola - 20 ";
	char *token;

	token = strtok(str," ");

	while(token != NULL)
	{

	printf("%s\n", token);
	token = strtok(NULL, " ");
	}
	return (0);
}
