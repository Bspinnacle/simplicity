#include "shell.h"
#include <stdlib.h>

/**
 * _calloc - a function that allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of memory
 *
 * Return: pointer to the allocated memory
 * if nmemb or size is 0, returns NULL
 * if malloc fails, _calloc returns NULL
 */
void *_calloc(size_t nmemb, size_t size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	s = malloc(nmemb * size);
	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < (nmemb * size); i++)
	s[i] = 0;
	return (s);
}
