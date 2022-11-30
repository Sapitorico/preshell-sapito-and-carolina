#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv [] = {"ls", "-l", NULL};
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		return (1);
	}
	else if (child_pid == 0)
	{
		
	execve("/bin/ls", argv, NULL);
	
	}
	else 
	{
		wait(NULL);
	}
	return(0);
}
