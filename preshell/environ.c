#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
