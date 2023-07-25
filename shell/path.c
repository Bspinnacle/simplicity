#include <stdio.h>
#include "shell.h"

/**
 * _path - A function that checks if the address of an array exists
 *
 * @cmd_buff: The command buffer
 * Return: The path of the command if found, and NULL if not found
*/

char *_path(char *cmd_buff)
{
	char *arr_path, *div_string, **main_arr;
	char *str = getenv("PATH");
	int q = 0, len, chk = 0;
	struct stat info;

	if (stat(cmd_buff, &info) == 0)
	{
		return (cmd_buff);
	}
	div_string = _strcpy(div_string, str);
	div_string = malloc(strlen(str) + 1);
	main_arr = dividestring(div_string, ";");

	for (q = 0; main_arr[q] != NULL; q++)
	{
		len = _strlen(main_arr[q]);
		if (main_arr[q][len - 1] != '/')
		{
			arr_path = _strcat(main_arr[q], "/");
		}
		arr_path = _strcat(main_arr[q], cmd_buff);

		if (stat(arr_path, &info) == 0)
		{
			chk = 1;
			break;
		}
	}
	if (chk == 0)
		return (NULL);
	free(div_string);
	free(main_arr);
	return (arr_path);
}
