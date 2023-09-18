#include "main.h"

/**
 *_printf - Printf function
 *@format: format.
 *Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list list;
	int printed_chars = 0;

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;	// Move past '%'
			switch (*format)
			{
				case 'c':
					putchar(va_arg(list, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += print_str(va_arg(list, char *));
					break;
				case '%':
					putchar('%');
					printed_chars++;
					break;
				default:
					putchar('%');
					putchar(*format);
					printed_chars += 2;
			}
		}

		format++;
	}

	va_end(list);

	return (printed_chars);
}

/**
 *putchar - Helper function to print a character to stdout
 *@c: The character to print
 *Return: Number of characters printed (always 1)
 */
int putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 *print_str - Helper function to print a string to stdout
 *@str: The string to print
 *Return: Number of characters printed
 */
int print_str(char *str)
{
	if (str == NULL)
	{
		str = "(null)";
	}

	int printed_chars = 0;
	while (*str)
	{
		putchar(*str);
		printed_chars++;
		str++;
	}

	return (printed_chars);
}
