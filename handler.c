#include "main.h"

/**
 * handler - Parses through the format string and invokes conversion functions.
 * @format: Format string containing format specifiers.
 * @func_Map: Array of conversion functions.
 * @args_list: Variable argument list.
 * 
 * Return: Total number of characters printed.
 */
int handler(const char *format, Conv_Map func_Map[], va_list args_list)
{
	int x, y, ret_val, charsprintd = 0;

	for (x = 0; format[x] != '\0'; x++)

	{
		if (format[x] == '%')
		{
			for (y = 0; func_Map[y].sym != NULL; y++)

			{
				if (format[x + 1] == func_Map[y].sym[0])
				{
					ret_val = func_Map[y].f(args_list);
					if (ret_val == -1)
						return (-1);
					charsprintd += ret_val;
					break;
				}
			}
			if (func_Map[y].sym == NULL && format[x + 1] != ' ')
			{
				if (format[x + 1] != '\0')
				{
					my_scribe(format[x]);
					my_scribe(format[x + 1]);
					charsprintd += 2;
				}
				else
					return (-1);
			}
			x = x + 1;
		}
		else
		{
			my_scribe(format[x]);
			charsprintd++;
		}
	}

	return (charsprintd);
}
