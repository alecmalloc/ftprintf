#include "ft_printf.h"

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
        if (hex <= 9)
            writechar(hex + '0');
        else
        {
            if (hextype == 'x')
            {
                writechar((hex - 10) + 'a');
            }
            else if (hextype == 'X')
            {
                writechar((hex - 10) + 'A');
            }
        }
    }
    return (write_len);
}

int writehexrouter(int hex, char hextype)
{
    int write_len;

    write_len = 0;
    if (hextype == 'p')
    {
        write_len += write(1, "0x", 2);
        hextype = 'X';
    }
    if (hex == 0)
        write_len += write(1, "0", 1);
    else
        write_len += writehex(hex, hextype);
    return (write_len);
}