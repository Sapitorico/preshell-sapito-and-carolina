#include <stdio.h>
#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	char *env_var = NULL;
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		env_var = strtok(environ[i], "=");
		if (strcmp(env_var, name) == 0)
		{
			return (strtok(NULL, "="));
		}
	}
	return (NULL);
}
