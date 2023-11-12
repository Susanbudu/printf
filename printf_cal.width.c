#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @itt: List of arguments to be printed.
 * @var_types: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *itt, va_list var_types)
{
	int current_itt;
	int f = 0;

	for (current_itt = *itt + 1; format[current_itt] != '\0'; current_itt++)
	{
		if (is_digit(format[current_itt]))
		{
			f *= 10;
			f += format[current_itt] - '0';
		}
		else if (format[current_itt] == '*')
		{
			current_itt++;
			f = va_arg(var_types, int);
			break;
		}
		else
			break;
	}

	*itt = current_itt - 1;

	return (f);
}
