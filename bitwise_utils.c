#ifndef BITWISE_UTILS_CPP
#define BITWISE_UTILS_CPP
#include <stdio.h>
#include "bitwise_utils.h"

void print_char_array(char* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%c", array[i]);
	}
	printf("\n");
}

void print_bits(unsigned int n, unsigned char type_size, unsigned char space_bits) 
{
	unsigned char bits_number = type_size * 8;
	printf("%i: ", n);
	for (int i = bits_number - 1; i >= 0; i--) {
		if ((i + 1) % space_bits == 0) printf(" ");
		printf("%i", (n & (1 << i)) != 0);
	}
	printf("\n");
}

unsigned char set_bit(unsigned char ch, int n)
{
	return ch | (1 << (n - 1));
}

unsigned char clear_bit(unsigned char ch, int n)
{
	return ch & ~(1 << (n - 1));
}

unsigned char invert_bit(unsigned char ch, int n)
{
	return ch ^ (1 << (n - 1));
}

_Bool get_bit(unsigned char ch, int n)
{
	return (ch & (1 << (n - 1))) != 0;
}

#endif // !BITWISE_UTILS_CPP