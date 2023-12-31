#include "monty.h"

/**
 * _atoi - converting string to int
 * @s: pointer to a string
 * Return: converted value or 0 on error
 */
int _atoi(char *s)
{
	int num = 0, sign = 1;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (_isdigit(*s))
			num = (num * 10) + (*s - 48);
		else
		{
			errno = 1;
			return (0);
		}
		s++;
	}

	return (num * sign);
}
/**
 * _isdigit - check if the char is digit or not.
 * @c: char.
 * Return: 1 if yes, 0 of not.
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
