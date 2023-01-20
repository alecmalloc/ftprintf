#include <stdarg.h>
#include <unistd.h>

// resources and links
// https://www.techtarget.com/whatis/definition/hexadecimal
// https://www.youtube.com/watch?v=4EJay-6Bioo -- Khan academy Hexadecimal video

int static writestr(char *str)
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

int static writechar(char c)
{
    return(write(1, &c, 1));
}

int static writelargeint(int num)
{
    int write_len;
    if (num >= 10)
    {
        write_len += writelargeint(num / 10);
        num = num % 10;
    }
    write_len += writechar(num + '0');
    return (write_len);
}

int static writeint(int num)
{
    int write_len;

    if (num < 0)
    {
        write_len += write(1, "-", 1);
        num *= -1;
    }
    if (num >= 10) 
        write_len += writelargeint(num);
    num += '0';
    write_len += write(1, &num, 1);
    return (write_len);
}

void static writepercent(void)
{
    write(1, "%", 1);
}

int static router(char letter, va_list args)
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
        writepercent();

    return (write_len);
}

int    ft_printf(const char *input, ...)
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