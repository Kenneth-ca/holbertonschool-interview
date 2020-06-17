#include "palindrome.h"

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome
 *
 * @n: is the number to be checked
 *
 * Return: Your function must return 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long res = 0, rev = 0, num = 0;

	num = n;
	while (num != 0)
	{
		res = num % 10;
		rev = rev * 10 + res;
		num /= 10;
	}

	if (n == rev)
		return (1);

	return (0);
}
