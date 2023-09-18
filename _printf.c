#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *_printf - Our custom printf function
 *@format: The format string
 *@...: The optional arguments
 *
 *Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					printed_chars += _puts(va_arg(args, char *));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
			}
		}
		else
		{
			printed_chars += _putchar(format[i]);
		}

		i++;
	}

	va_end(args);
	return (printed_chars);
}
