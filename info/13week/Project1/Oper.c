#include"Oper.h"
unsigned MultiplicationOfTheDigitsInANumber(unsigned n)
{
	int mult = 1;
	while (n != 0)
	{
		mult *= (n % 10);
		n /= 10;
	}
	return mult;
}
unsigned SumOfTheDigitsInANumber(unsigned n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
unsigned A(unsigned Number)
{
	int result = 0;
	int K = 1;
	while (Number - SumOfTheDigitsInANumber(result) > 10)
	{
		result += 9 * K;
		K *= 10;
	}
	result += (Number - SumOfTheDigitsInANumber(result)) * (K);
	return result;
}
unsigned B(unsigned Number)
{
	for (unsigned i = 1; i < UINT_MAX; i++)
	{
		if (MultiplicationOfTheDigitsInANumber(i) == Number)
		{
			return i;
		}
	}
}
unsigned C(unsigned Number)
{
	for (unsigned i = UINT_MAX; i > 0; i--)
	{
		if (SumOfTheDigitsInANumber(i) == Number)
		{
			return i;
		}
	}
}
unsigned D(unsigned number)
{
	for (unsigned i = UINT_MAX; i > 0; i--)
	{
		if (MultiplicationOfTheDigitsInANumber(i) == number)
		{
			return i;
		}
	}
	return 0;
}
