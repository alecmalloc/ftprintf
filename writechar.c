#include "ft_printf.h"

int writechar(char c)
{
    return(write(1, &c, 1));
}