#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LEN 100

/**
 * main - function that prints shell prompt
 *
 * Return: 0
*/

int main(void)
{
	char command[MAX_COMMAND_LEN];
	int exitCondition = 0;

	while (!exitCondition)
	{
	printf("FikkiSam$ ");
			if (fgets(command, MAX_COMMAND_LEN, stdin) == NULL)
			break;

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid < 0)
			{
			perror("Fork failure");
			exit(EXIT_FAILURE);
			}
		else if (pid == 0)
			{
			int rtn = execl(command, command, (char *)NULL);

				if (rtn < 0)
				{
					perror("Not found");
					exit(EXIT_FAILURE);
				}
				exit(EXIT_SUCCESS);
			} else
			{
				int status;

				wait(&status);
			}
	}
			return (0);
}
