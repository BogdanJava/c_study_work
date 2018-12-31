#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "bitwise_utils.h"
#include "pin_encrypt.h"

int main() {
	srand(time(NULL));
	printf("password: %s\n", "5890");
	ushort pass = (5 << 12) | (8 << 8) | (9 << 4) | 0;
	print_bits(pass, sizeof(unsigned short), 8);
	uint encrypted = encrypt(5, 8, 9, 0);
	print_bits(encrypted, sizeof(unsigned int), 8);
	getchar();
	return 0;
}
