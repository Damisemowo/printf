#include "main.h"

/**
 * _printf - Custom printf function that prints formatted output
 * @format: A format string containing conversion specifiers
 * @...: Variable number of arguments based on the format string
 *
 * Return: The total number of characters printed (excluding null byte)
 *         -1 if an error occurs or if the format string is NULL
 */
int _printf(const char *format, ...)
{
	int charsprintd;

	Conv_Map func_Map[] =	{
		{"c", char_print},
		{"s", str_print},
		{"%", prcnt_print},
		{"d", int_print},
		{"i", int_print},
		{NULL, NULL}
	};

	va_list args_list;


	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	charsprintd = handler(format, func_Map, args_list);
	va_end(args_list);

	return (charsprintd);
}
