#include "main.h"

/**
 * num_print - Prints a signed integer to standard output
 * @args_list: Variable argument list containing the integer to print
 *
 * Return: The number of characters printed (excluding null byte)
 */
int num_print(va_list args_list)
{
	int a;
	int mag_num;
	int len_num;
	unsigned int num;

	a  = va_arg(args_list, int);
	mag_num = 1;
	len_num = 0;

	if (a < 0)
	{
		len_num += my_scribe('-');
		num = a * -1;
	}
	else
		num = a;

	for (; num / mag_num > 9; )
		mag_num *= 10;

	for (; mag_num != 0; )
	{
		len_num += my_scribe('0' + num / mag_num);
		num %= mag_num;
		mag_num /= 10;
	}

	return (len_num);
}

/**
 * unsignd_num_print - Prints an unsigned integer to standard output
 * @a: The unsigned integer to print
 *
 * Return: The number of characters printed (excluding null byte)
 */
int unsignd_num_print(unsigned int a)
{
	int mag_num;
	int len_num;
	unsigned int num;

	mag_num = 1;
	len_num = 0;

	num = a;

	for (; num / mag_num > 9; )
		mag_num *= 10;

	for (; mag_num != 0; )
	{
		len_num += my_scribe('0' + num / mag_num);
		num %= mag_num;
		mag_num /= 10;
	}

	return (len_num);
}
