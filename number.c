#include "main.h"

/**
* convert - converter function, a clone of "i"to"a"
* as i is an integer and a is a string
* @num: number
* @base: base
* @flags: arguments flags
* @params: parameters struct
*
* Return: string
*/

char *convert(long int num, int base, int flags, params_t *params)
{
        static char *array;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;
        (void)params;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                n = -num;
                sign = '-';
        }
        array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDE";
        ptr = &buffer[49];
        *ptr = '\0';

        do {
                *--ptr = array[n % base];
                n /= base;
        } while (n != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}

/**
* print_unsigned - prints unsigned integer numbers
* @ap: argument pointer
* @params: parameters struct
*
* Return: bytes pointed
*/

int print_unsigned(va_list ap, params_t *params)
{
        unsigned long l;

        if (params->l_modifier)
                l = (unsigned long)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                l = (unsigned short int)va_arg(ap, unsigned int);
        else
                l = (unsigned int)va_arg(ap, unsigned int);
        params->unsign = 1;
        return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
* print_address - prints address
* @ap: argument pointer
* @params: parameters struct
*
* Return: bytes pointed
*/

int print_address(va_list ap, params_t *params)
{
        unsigned longint n = va_arg(ap, unsigned long int)
        char *str;

        if (!n)
                return (_puts("nil"));

        str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
        *--str = 'x';
        *--str = '0';
}
