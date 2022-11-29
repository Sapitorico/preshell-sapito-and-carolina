#include "getenv.c"

int main(void)
{
	char *path;
	char *ptr;

	path = _getenv("PATH");
	ptr = strtok(path, ":");
	while (ptr)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, ":");
	}
}
