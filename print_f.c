#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format.
 *
 * @format: The format string.
 * @...: The variable number of arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int nc_count = 0;
	int c;
	const char *s;
	va_list nc;

	va_start(nc, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			nc_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'c':
					c = va_arg(nc, int);

					putchar(c);
					nc_count++;
					break;
				case 's':
					s = va_arg(nc, const char *);

					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						putchar(*s);
						s++;
						nc_count++;
					}
					break;
				case '%':
					putchar('%');
					nc_count++;
					break;
				default:
					putchar('%');
					nc_count++;
					putchar(*format);
					nc_count++;
					break;
			}
		}
		format++;
	}

	va_end(nc);
	return (nc_count);
}