#include <stdarg.h>
#include <unistd.h>

// resources and links
// https://www.techtarget.com/whatis/definition/hexadecimal

int static lenint(int num)
{
    int i;

    i = 1;
    while (num > 0)
    {
        num = num / 10;
        i = i / 10; 
    }
    return (i);
}


void static writehex(int num)
{
    int i;
    int rem;
    int hex;
    
    i = 0;
    while (num > 0)
    {
        num = num / 16;
        rem = num % 16;
        lenint(rem);
    }
}


void static writestr(char *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        write(1, &str[i], 1);
        i++;
    }
}

void static writechar(char c)
{
    write(1, &c, 1);
}

void static writeint(int num)
{
    num = num + '0';
    write(1, &num, 1);
}

void static router(char letter, va_list args)
{
    if (letter == 'd')
        writeint(va_arg(args, int));
    if (letter == 'c')
        writechar(va_arg(args, int));
    if (letter == 's')
        writestr(va_arg(args, char *));
    if (letter == '%')
        write(1, "%", 1);
    if (letter == 'x')
        writehex(va_arg(args, int));
}

void    ft_printf(const char *input, ...)
{
    va_list args;
    va_start(args, input);

    while (*input != 0)
    {
        if (*input == '%')
        {
            input++;
            router(*input, args);
            input++;
        }
        writechar(*input);
        input++;
    }
    write(1, "\n", 1);
    va_end(args);
}