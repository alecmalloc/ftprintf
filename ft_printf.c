#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

// resources and links
// https://www.techtarget.com/whatis/definition/hexadecimal
// https://www.youtube.com/watch?v=4EJay-6Bioo -- Khan academy Hexadecimal video


int writehex(int hex, char hextype)
{
    int write_len;
    if (hex >= 16)
    {
        writehex(hex / 16, hextype);
        writehex(hex % 16, hextype);
    }
    else
    {
        if (hextype == 'x')
        {
            
        }
        else if (hextype == 'X')
        {

        }
    }
    return (write_len);
}

int writehexrouter(int hex, char hextype)
{
    int write_len;

    if (hex == 0)
        write_len += write(1, "0", 1);
    else
        write_len += writehex(hex, hextype);
    return (write_len);
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

int router(char letter, va_list args)
{
    int write_len;

    write_len = 0;

    if (letter == 'd' || letter == 'i')
        write_len += writeint(va_arg(args, int));
    else if (letter == 'c')
        write_len += writechar(va_arg(args, int));
    else if (letter == 's')
        write_len += writestr(va_arg(args, char *));
    else if (letter == '%')
        write_len += writepercent();
    else if (letter == 'u')
        write_len += writeuint(va_arg(args, int));
    else if (letter == 'x' || letter == 'X')
        write_len += writehexrouter(va_arg(args, int), letter);
    return (write_len);
}

int ft_printf(const char *input, ...)
{
    int i;
    int write_len;
    va_list args;
    va_start(args, input);

    i = 0;
    write_len = 0;
    while (input[i])
    {
        if (input[i] == '%')
        {
            write_len += router(input[i + 1], args);
            i++;
        }
        else
            write_len += writechar(input[i]);
        i++;
    }
    va_end(args);
    write(1, "\n", 1);
    return (write_len);
}