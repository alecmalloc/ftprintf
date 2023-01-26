#include "ft_printf.h"

int writechar(char c)
{
    return(write(1, &c, 1));
}

int writestr(char *str)
{
    int i;
    int write_len;

    i = 0;
    write_len = 0;
    while (str[i] != 0)
    {
        write_len += write(1, &str[i], 1);
        i++;
    }
    return (write_len);
}