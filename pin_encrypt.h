#ifndef PIN_ENCRYPT_H
#define PIN_ENCRYPT_H

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;

uint encrypt(uchar, uchar, uchar, uchar);
ushort shuffle_password(uchar a, uchar b, uchar c, uchar d, uchar order);
void set_order_array_element(uchar* arr, uchar index, uchar array_size);
uchar get_random_order();
_Bool exists_in_array(uchar* arr, uchar array_size, uchar element);

#endif // !PIN_ENCRYPT_H
