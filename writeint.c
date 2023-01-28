#include "ft_printf.h"

int writelargeint(int num)
{
    int write_len;

    write_len = 0;
    if (num >= 10)
    {
        write_len += writelargeint(num / 10);
        write_len += writelargeint(num % 10);
    }
    else
        write_len += writechar(num + '0');
    return(write_len);
}

int writeint(int num)
{
    int write_len;

    write_len = 0;
    if (num < 0)
    {
        write_len += write(1, "-", 1);
        num *= -1;
    }
    if (num >= 10) 
        write_len += writelargeint(num);
    else
    {
        num += '0';
        write_len += write(1, &num, 1);
    }
    return (write_len);
}

int writeuint(int num)
{
    int write_len;

    write_len = 0;
    if (num < 0)
        num *= -1;

    return(writeint(num));
}