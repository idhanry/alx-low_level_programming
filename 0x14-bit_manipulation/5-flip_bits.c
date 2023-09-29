#include "main.h"

/**
 * flip_bits - counts the number of bits that need to be flipped to
 * change one unsigned long integer to another.
 *
 * This function calculates the Hamming distance between two unsigned long
 * integers, which represents the number of bits that differ between them.
 *
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 *
 * Return: The number of bits that need to be flipp to transform 'n' into 'm'.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, c = 0;
	unsigned long int current;
	unsigned long int xor = n ^ m;

	/* Iterate through each bit of the XOR result */
	for (i = 63; i >= 0; i--)
	{
		current = xor >> i;
		if (current & 1)
			c++;
	}

	return (c);
}

