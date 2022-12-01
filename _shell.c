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
		if (!line)
			continue;
		command = divide_line(line);
		if (!command)
			continue;
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
	ssize_t characters = 0;

	characters = getline(&buffer, &size, stdin);
	if (characters == EOF || !_strcmp(buffer, "\n"))
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
char **divide_line(char *line)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;
	ssize_t len = 64;

	tokens = malloc(len * sizeof(char *));
	if (!tokens)
	{
		for (; i < len; i++)
			free(tokens[i]);
		free(tokens);
		perror("Error: allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n");
	while (token)
	{
		tokens[i] = token;
		i++;
		if (i >= len)
		{
			len += 64;
			tokens = realloc(tokens, len * sizeof(char *));
			if (!token)
			{
				for (i = 0; i < len; i++)
					free(tokens[i]);
				free(tokens);
				free(line);
				perror("Error: allocation error");
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
	int i = 0;
	int len = _strlen(*command);
	pid_t pid;
	int status;

	if (!command[0])
		return (-1);
	if (!_strcmp(command[0], "exit"))
	{
		return (0);
	}
	command = _path(command);
	pid = fork();
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
	return (status);
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
char **divide_path(void)
{
	char *path = _getenv("PATH");
	char *token_path = NULL, **new_path = NULL;
	int i = 0;

	token_path = strtok(path, ":");
	new_path = malloc(sizeof(char *) * _strlen(token_path) + 1);
	if (!new_path)
		return (NULL);
	while (token_path)
	{
		new_path[i] = token_path;
		token_path = strtok(NULL, ":");
	}
	new_path[i] = NULL;
	return (new_path);
}
char **_path(char **command)
{
	char **path = divide_path();
	char *command_cpy = NULL, *str_path = NULL;
	int i = 0;
	struct stat st;

	while (path[i])
	{
		command_cpy = command[0];
		str_path = malloc(_strlen(path[i]) + _strlen(command_cpy) + 2);
		if (!str_path)
		{
			perror("Error: allocation error");
			return (NULL);
		}
		_strcpy(str_path, path[i]);
		_strcat(str_path, "/");
		_strcat(str_path, command_cpy);
		if (!stat(str_path, &st))
		{
			command[0] = str_path;
			free(command_cpy);
			return (command);

		}
		i++;
	}
	return (command);
}
