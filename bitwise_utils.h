#ifndef BITWISE_UTILS_H
#define BITWISE_UTILS_H

void print_char_array(char*, int);
void print_bits(unsigned int n, unsigned char type_size, unsigned char space_bits);
unsigned char set_bit(unsigned char ch, int n);
unsigned char clear_bit(unsigned char ch, int n);
unsigned char invert_bit(unsigned char ch, int n);
_Bool get_bit(unsigned char ch, int n);

#endif // !BITWISE_UTILS_H
