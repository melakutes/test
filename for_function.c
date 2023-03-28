#include "main.h"

void format_checK()
{
  if (format[i] != '%'){
    
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
