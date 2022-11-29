#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void)
{
	char *path;
	DIR *dp;
	struct dirent *dirp;

	path = getenv("PATH");
	printf("PATH: %s\n", path);
	char *p = strtok(path, ":");
	while (p)
	{
		if ((dp = opendir(p)) == NULL)
		{
			fprintf(stderr, "cannot open directory: %s\n", p);
		}
		else
		{
			while ((dirp = readdir(dp)) != NULL)
			{
				printf("%s/%s\n", p, dirp->d_name);
			}
			closedir(dp);
		}
		p = strtok(NULL, ":");
	}
	return (0);
}
