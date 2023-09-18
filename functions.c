#include "main.h"

/*************************PRINT CHAR *************************/

int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, 0, 0, 0, 0));
}

/*************************PRINT A STRING *************************/

int print_string(va_list types, char buffer[])
{
	char *str = va_arg(types, char *);
	if (str == NULL)
		str = "(null)";
	int length = 0;
	while (str[length] != '\0')
		length++;

	return write(1, str, length);
}

/*************************PRINT PERCENT SIGN *************************/

int print_percent(va_list types, char buffer[])
{
	UNUSED(types);
	return write(1, "%%", 1);
}

/*************************PRINT INT *************************/

int print_int(va_list types, char buffer[])
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, 0);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int) n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) *n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return write_number(is_negative, i, buffer, 0, 0, 0, 0);
}

/*************************PRINT BINARY *************************/

int print_binary(va_list types, char buffer[])
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);

	n = va_arg(types, unsigned int);
	m = 2147483648; /*(2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}

	return count;
}
