#include "holberton.h"

/**
 * valid_digit - check if all values are digits
 * @first: pointer to the first array
 * @second: pointer to the second array
 * Return: nothing.
 */

void valid_digit(char *first, char *second)
{
	int a = 0;
	int b = 0;

	while (*(first + b))
	{
		if (!isdigit(*(first + b)))
			a++;
		b++;
	}
	b = 0;
	while (*(second + b))
	{
		if (!isdigit(*(second + b)))
			a++;
		b++;
	}
	if (a > 0)
	{
		printf("Error\n");
		exit(98);
	}
	if (*first == '0' || *second == '0')
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * partial_sum - adds partial sums to the result
 * @p: parcial product
 * @mg: result
 * @i: position of mg to stat to add
 * @tp: size of p.
 */
void partial_sum(char *p, char *mg, int i, int tp)
{
	int car = 0;
	int res = 0;
	int cont = tp;
	int aux = 0;

	for (; cont >=  0; cont--, i--)
	{
		res = (*(p + cont) - '0') + (*(mg + i) - '0') + car;
		car = res / 10;
		res = (res % 10) + '0';
		*(mg + i) = res;
	}
	res = 0;
	for (aux = i - 1; aux >= 0; aux--)
	{
		res = *(mg + aux) - '0';
		res = res + car;
		car = res / 10;
		res = (res % 10) + '0';
		*(mg + aux) = res;
	}
}
/**
 * filler - fill the array
 * @a: size of array
 * Return: pointer to the array
 */
char *filler(int a)
{
	int i;
	char *p;

	p = malloc(a);

	if (!p)
		return (NULL);

	for (i = 0; i < a; i++)
		*(p + i) = '0';

	return (p);
}
/**
 * get_size - counts the number of chars in array
 * @s: pointer to the array of char
 * Return: size of s
 */
int get_size(char *s)
{
	int i = 0;

	while (*(s + i))
		i++;

	return (i);
}

/**
 * mults - mults the inputs
 * @a: size.
 * @i: index
 * @b: size.
 * @g: size.
 * @s1: factor 1.
 * @s2: factor 2.
 * @mg: result
 * @p: partial product.
 */
void mults(int a, int i, int b, int g, char *p, char *s1, char *s2, char *mg)
{
	int car = 0;
	int aux = 0;
	int j = b + 1;
	int t3 = j + 1;
	int k = 0;

	for (; a >= 0; a--, i--)
	{
		car = 0;
		b = g;
		j = g + 1;

		for (k = 0; k < t3; k++)
			*(p + i) = '0';

		for (; b >= 0; b--, j--)
		{
			aux = ((s2[a] - '0') * (s1[b] - '0'));
			aux = aux + car;
			p[j] = ((aux % 10) + '0');
			car = aux / 10;
		}
		*(p + j) = car + '0';
		partial_sum(p, mg, (i - 1), (t3 - 1));
	}
}
/**
 * main - check the code for Holberton School students.
 * @argv: array of pointers store the arguments
 * @argc: quantity of arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int l1, l2, lt, i, a = 0, b = 0, g, ind;
	char *mg, *p, *m1, *m2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	valid_digit(*(argv + 1), *(argv + 2));

	l1 = get_size(*(argv + 1));
	l2 = get_size(*(argv + 2));
	ind = l1 + l2;
	mg = filler(l1 + l2);
	m1 = *(argv + 2);
	m2 = *(argv + 1);
	b = l2 - 1;
	a = l1 - 1;
	lt = l2 + 1;

	if (l1 >= l2)
	{
		m1 = *(argv + 1);
		m2 = *(argv + 2);
		b = l1 - 1;
		a = l2 - 1;
		lt = l1 + 1;
	}
	g = b;
	p = filler(lt);
	mults(a, ind, b, g, p, m1, m2, mg);

	for (i = 0; i < (l1 + l2); i++)
	{
		if (!(*mg == '0' && i == 0))
			printf("%c", *(mg + i));
	}
	printf("\n");

	return (0);
}
