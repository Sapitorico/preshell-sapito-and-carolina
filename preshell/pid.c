#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
	pid_t pid = getpid();

	printf("El PID del proceso actual es %u\n", pid);
	return (0);
}
