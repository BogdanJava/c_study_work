#ifndef PIN_ENCRYPT_C
#define PIN_ENCRYPT_C
#include "pin_encrypt.h"
#include "bitwise_utils.h"
#include <stdlib.h>
/*
	   A     B     C     D			order		   B     D     A     C    trash
	[1010][1011][1100][1101] -> [01][11][00][10][1011][1101][1010][1100][10100111]
*/
uint encrypt(uchar a, uchar b, uchar c, uchar d)
{
	uchar order = get_random_order();
	ushort shuffledPassword = shuffle_password(a, b, c, d, order);
	uchar salt = get_salt();
	return get_hash(order, shuffledPassword, salt);
}

uint get_hash(uchar order, ushort shuffledPassword, uchar salt) {
	_Bool orderFirst = rand() % 2 == 0;
	if (orderFirst) {
		return (order << 24) | (shuffledPassword << 8) | salt;
	}
	else {
		return (salt << 24) | (shuffledPassword << 8) | order;
	}
}

uchar get_salt() {
	return 229 + (rand() % 27);
}

uchar get_random_order()
{
	uchar arr[4];
	set_order_array_element(arr, 0, 4);
	set_order_array_element(arr, 1, 4);
	set_order_array_element(arr, 2, 4);
	set_order_array_element(arr, 3, 4);
	return
		((arr[0] << 6) & 0b11000000) |
		((arr[1] << 4) & 0b00110000) |
		((arr[2] << 2) & 0b00001100) |
		(arr[3] & 0b00000011);
}

void set_order_array_element(uchar* arr, uchar index, uchar array_size)
{
	while (1) {
		int el = rand() % array_size;
		if (exists_in_array(arr, array_size, el)) {
			continue;
		}
		else {
			arr[index] = el;
			break;
		}
	}
}

_Bool exists_in_array(uchar* arr, uchar array_size, uchar element)
{
	for (uchar i = 0; i < array_size; i++) {
		if (*(arr + i) == element) return 1;
	}
	return 0;
}

ushort shuffle_password(uchar a, uchar b, uchar c, uchar d, uchar order)
{
	uchar aPosition = (order & 0b11000000) >> 6;
	uchar bPosition = (order & 0b00110000) >> 4;
	uchar cPosition = (order & 0b00001100) >> 2;
	uchar dPosition = order & 0b00000011;
	return ((ushort)a) << (12 - aPosition * 4) |
		((ushort)b) << (12 - bPosition * 4) |
		((ushort)c) << (12 - cPosition * 4) |
		((ushort)d) << (12 - dPosition * 4);
}

#endif // !PIN_ENCRYPT_C
