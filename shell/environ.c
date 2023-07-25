#include "shell.h"

/**
 * _getenv - A function that gets the variable of an environment
 * @name: The variable of environment to get
 *
 * Return: The value of the variable requested
*/

char *_getenv(const char *name)
{
	int p, q, status;

	p = 0;
	while (environ[p] != NULL)
	{
		status = 1;
		for (q = 0; environ[p][q] != '='; q++)
		{
			if (name[q] != environ[p][q])
			{
				status = 0;
				break;
			}
		}
		if (status)
			return (&environ[p][q + 1]);
	p++;
	}
	return (NULL);
}

/**
 * _environ - A function that prints environment
 *
 * Return: No return
 */

	void _environ(void)
{
	int p = 0;

	while (environ[p])
	{
		printf("%s\n", environ[p]);
		p++;
	}
}
