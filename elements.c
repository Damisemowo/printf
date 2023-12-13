#include "main.h"
/**
 * char_print - Prints a single character
 * @args_list: A va_list containing the character to be printed
 *
 * Return: Always returns 1 as the length of the printed character
 */
int char_print(va_list args_list)
{
	char value;

	value = va_arg(args_list, int);
	my_scribe(value);
	return (1);
}

/**
 * str_print - Prints a string
 * @args_list: A va_list containing the string to be printed
 *
 * Return: The length of the printed string
 */
int str_print(va_list args_list)
{
	int r;
	const char *y;

	y = va_arg(args_list, const char *);
	if (y == NULL)
		y = "(null)";
	for (r = 0; y[r] != '\0'; r++)
		my_scribe(y[r]);
	return (r);
}

/**
 * prcnt_print - Prints a percent symbol '%'
 * @args_list: Unused parameter (no argument required for '%')
 *
 * Return: Always returns 1 as the length of the printed percent symbol
 */
int prcnt_print(__attribute__((unused)) va_list args_list)
{
	my_scribe('%');
	return (1);
}

/**
 * int_print - Prints an integer using num_print function
 * @args_list: A va_list containing the integer to be printed
 *
 * Return: The length of the printed integer
 */
int int_print(va_list args_list)
{
	int a;

	a = num_print(args_list);
	return (a);

}
