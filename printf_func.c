#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - Prints format
 * @format: format to be printed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	print types[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	int i, j, num = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			num++;
		}
		else
		{
			for (j = 0; types[j].type != NULL; j++)
			{
				if (format[i + 1] == *(types[j].type))
				{
					num += (types[j].func)(args);
					i++;
					break;
				}
				else if (format[i + 1] == '%')
				{
					write(1, &format[i + 1], 1);
					num++;
					i++;
					break;
				}
				else if (format[i + 1] != 'c' && format[i + 1] != 's')
				{
					write(1, &format[i], 1);
					num++;
					i++;
					break;
				}
			}
		}
	}
	va_end(args);
	return (num);
}
