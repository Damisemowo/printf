#ifndef MY_PRINTF
#define MY_PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/*
 * struct ConvMap - represents a conversion function mapping
 * @sym: fomart specifier symbol
 * @f: corresponding conversion function
 */
struct ConvMap
{
		char *sym;
			int (*f)(va_list);
};
typedef struct ConvMap Conv_Map;


int my_scribe(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int handler(const char *format, Conv_Map funct_list[], va_list args);
int char_print(va_list);
int str_print(va_list args);
int prcnt_print(va_list);
int unsignd_num_print(unsigned int n);
int num_print(va_list);
int int_print(va_list);

#endif
