#include "ft_printf.h"

int writepercent(void)
{
    int write_len;
    return(write(1, "%", 1));
}