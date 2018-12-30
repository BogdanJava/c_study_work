#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "bitwise_utils.h"
#include "pin_encrypt.h"

int main() {
	srand(time(NULL));
	printf("password: %s\n", "5890");
	ushort a = 5 << 12;
	ushort b = 8 << 8;
	ushort c = 9 << 4;
	ushort d = 0;
	print_bits(a + b + c + d, sizeof(unsigned short), 4);
	ushort encrypted = encrypt(5, 8, 9, 0);
	printf("encrypted password: %i%i%i%i\n",
		(encrypted >> 12) & 0b1111,
		(encrypted >> 8) & 0b1111,
		(encrypted >> 4) & 0b1111,
		encrypted & 0b1111);
	print_bits(encrypted, sizeof(unsigned short), 4);
	getchar();
	return 0;
}
