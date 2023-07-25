#include "shell.h"

/**
 * dividestring - A function that divides a string
 * @div_string: The string to be divided
 * @separator: Division point indicator
 * Return: array
*/

char **dividestring(char *div_string, char *separator)
{
	int p = 0, q = 0;
	char *c, **array;

	array = (char **)_calloc(100, sizeof(char *));
	while (div_string[p])
	{
		p++;
	}
	while ((c = strtok(div_string, separator)) != NULL)
	{
		array[q] = c;
		div_string = NULL;
		q++;
	}
	return (array);
}
