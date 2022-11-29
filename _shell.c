#include "main.h"
#include "functions.h"
/**
 */
int main(void)
{
	char *line = NULL, **command = NULL;
	int status = 1;

	while (status)
	{
		printf(PID);
		line = read_line();
		if (!_strcmp(line, "exit\n"))
			break;
		command = divide_line(line);
		status = run_command(command);

		free(command);
		free(line);
	}
	free(command);
	free(line);
	exit(EXIT_SUCCESS);
}
char *read_line(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		perror("Bad arguments");
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
char **divide_line(char *line)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;
	ssize_t len = _strlen(line);

	tokens = malloc(len * sizeof(char *));
	if (!tokens)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n");
	while (token)
	{
		tokens[i] = token;
		i++;
		if (i >= len)
		{
			len += len;
			tokens = realloc(tokens, len * sizeof(char *));
			if (!token)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
	return (tokens);
}
int run_command(char **command)
{
	pid_t pid = fork();
	int status = 0;

	if (!pid)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
		perror("Error");
	return (1);
}
