/*#include <stdio.h>*/
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"


/**
 * main - function that prints shell prompt
 *
 * Return: 0
*/

int main(void)
{
	char *input = NULL;
	char **arg, *cmd_buff = NULL;
	int exitCondition = 0;
	int status = 0;
	size_t n = 0;
	ssize_t buff = 0;

	while (!exitCondition)
	{
		printf("FikkiSam$ ");
		buff = getline(&input, &n, stdin);
		if (buff == -1 || _strcmp("exit\n", input) == 0)
		
		{	free(input);
			free(cmd_buff);
			break; }
		cmd_buff = malloc(buff);
		if (cmd_buff == NULL)
		{
			perror("Memory allocation failed");
			free(input);
			exit(EXIT_FAILURE);
		}
		strcpy(cmd_buff, input);
		/*free(input);*/

		cmd_buff[buff -1] = '\0';
		arg = dividestring(cmd_buff, " ");
		arg[0] = _path(arg[0]);
		if (arg[0] != NULL)
		status = _fork(arg);
		else
	perror("Not found");
	/*free(arg);*/
/*	free(cmd_buff);*/
	}
	return (status);
}
