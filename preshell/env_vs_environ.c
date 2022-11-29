#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv, char **env)
{
	printf("Address of env: %p\n", env);
	printf("Address of environ: %p\n", environ);

	if (env == environ)
		printf("Yes, they are the same.\n");
	else
		printf("No, they are not the same.\n");
	return (0);
}
