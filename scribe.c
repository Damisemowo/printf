#include <unistd.h>

/**
 * my_scribe - helper function to print to the stdout
 * @c: character to be printed
 *
 * Return: 1 on success, -1 on failure
 */

int my_scribe(char c)
{
		return (write(1, &c, 1));
}
