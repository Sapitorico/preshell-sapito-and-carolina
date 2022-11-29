#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(void)
{
	pid_t padre = getppid();

	printf("El PID del proceso padre es %u\n", padre);
	return (0);
}
