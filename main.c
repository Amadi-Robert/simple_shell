#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = ":) ";
	size_t n = 0;
	char *lineptr; char *lineptr_copy = NULL;
	ssize_t chars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	(void)ac;

	while(1)
	{
	printf("%s", prompt);
	chars_read = getline(&lineptr, &n, stdin);
	if (chars_read == -1)
	{
		printf("Exiting...\n");
		return (-1);
	}

	lineptr_copy = malloc(sizeof(char) * chars_read);
	if (lineptr_copy == NULL)
	{
		perror("memory allocating error");
		return (-1);
	}

	strcpy(lineptr_copy, lineptr);

	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}

	argv[i] = NULL;

	execmd(argv);

	}

	free(lineptr_copy);
	free(lineptr);

	return(0);

}

