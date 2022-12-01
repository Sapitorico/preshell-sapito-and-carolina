#include "main.h"
#include "functions.h"
extern char **environ;
/**
 */
int main(void)
{
	char *line = NULL, **tokens = NULL, **command = NULL;
	int status = 1;

	while (status)
	{
		printf(PID);
		line = read_line();
		tokens = divide_line(line);
		command = _path(tokens);
		status = run_command(command);
		free(line);
	}
	free(command);
	exit(EXIT_SUCCESS);
}
char *read_line(void)
{
	char *buffer = NULL;
	size_t size = 1024;

	if (getline(&buffer, &size, stdin) == -1)
		exit(EXIT_SUCCESS);
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
		for (; i < len; i++)
			free(tokens[i]);
		free(tokens);
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n");
	while (token)
	{
		tokens[i] = token;
		if (i >= len)
		{
			len += len;
			tokens = realloc(tokens, len * sizeof(char *));
			if (!token)
			{
				for (i = 0; i < len; i++)
					free(tokens[i]);
				free(tokens);
				free(line);
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		i++;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
	return (tokens);
}
int run_command(char **command)
{
	int i = 0;
	int len = _strlen(*command);
	pid_t pid = fork();
	int status;

	if (!_strcmp(command[0], "exit"))
	{
		return (0);
	}
	if (!pid)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			for (; i < len; i++)
				free(command[i]);
			free(command);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		waitpid(pid, &status, WUNTRACED);
	else
		perror("Error");
	free(command);
	return (1);
}
char *_getenv(const char *name)
{
	extern char **environ;
	char *env_var = NULL;
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		env_var = strtok(environ[i], "=");
		if (!strcmp(env_var, name))
			return (strtok(NULL, "="));
	}
	return (NULL);
}
char **_path(char **command)
{
	char *path = _getenv("PATH");
	char **dirs = NULL, *token = NULL;
	int i = 0, j = 0;
	ssize_t len = _strlen(path);
	struct stat sb;

	dirs = malloc(len * sizeof(char *));
	token = strtok(path, ":");
	while (token)
	{
		printf("%s\n", token);
		dirs[i] = token;
		token = strtok(NULL, " ");
	}
	dirs[i] = NULL;
	while (dirs[j])
	{
		chdir(dirs[j]);
		if (!stat(command[0], &sb))
		{
			command[0] = strcat(dirs[i], command[0]);
			break;
		}
		j++;
	}
	printf("%s\n", command[0]);
	return (command);
}
