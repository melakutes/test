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
	va_list args;
	int num;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	num = _print(format, args, types);
	
	va_end(args);
	return (num);
}
int _print(const char *format, va_list args, print types[])
{
	int i, j, num = 0;

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
	return (num);
}
