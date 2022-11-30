#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t your_pid;

	my_pid = getpid();
	{
	printf("%u\n", my_pid);
	}

	your_pid = getppid();
	{
	printf("%u\n", your_pid);
	}

	return (0);
}
