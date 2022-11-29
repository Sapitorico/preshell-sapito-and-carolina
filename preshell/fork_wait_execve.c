#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	pid_t pid = fork();
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	if (pid == 0)
	{
		execve("/bin/ls", argv, NULL);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
