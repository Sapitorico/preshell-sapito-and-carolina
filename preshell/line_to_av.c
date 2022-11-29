#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **split_string(char *str)
{
	int i = 0;
	char **tokens;

	tokens = malloc(strlen(str) * sizeof(char *));
	if (!tokens)
		return (NULL);
	tokens[0] = strtok(str, " ");
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = strtok(NULL, " ");
	}
	return (tokens);
}
int main(void)
{
	char str[] = "mi nombre es Sapito";
	char **tokens = split_string(str);
	int i = 0;

	while (tokens[i] != NULL)
	{
		printf("%s, ", tokens[i]);
		i++;
	}
	printf("\n");
	free(tokens);
	return (0);
}
