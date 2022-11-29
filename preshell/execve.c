#include <unistd.h>

int main(void)
{
	char *argv[] = { "/bin/ls", "-l", "-a", NULL };
	char *envp[] = { NULL };

	execve("/bin/ls", argv, envp);
	return (0);
}
