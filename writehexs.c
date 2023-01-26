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