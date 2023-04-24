#include "main.h"
/**
 * _loop_str - print string using loop and write
 * @str: pointer to string
 */

void _loop_str(char *str)
{
	int j = 0;

	while (str[j])
	{
		write(1, str + j, 1);
		j++;
	}
}
/**
 * _printf	- preduce output according to format
 * @format: string of charaters
 * Return: return length
 */
int _printf(char const *format, ...)
{
	va_list go;
	unsigned int i = 0, j;
	char *str;
	char a;

	if (format == NULL)
		return (-1);
	va_start(go, format);
	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				switch (format[i + 1])
				{	
					case 'c':
						a = va_arg(go, int);
						write(1, &a, 1);
						break;
					case 's':
						_loop_str(va_arg(ap, char *));
						break;
					default:
						write(1, &format[i], 1);
						break;
				}
				i += 2;
			}
			else
			{
				write(1, &format[i], 1);
				i++;
			}
		}
	}
	va_end(go);
	return (i);
}
