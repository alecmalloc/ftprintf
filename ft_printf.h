#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int writepercent(void);
int writeuint(int num);
int writeint(int num);
int writelargeint(int num);
int writechar(char c);
// int writestr(char *str);
// int writehexrouter(int hex, char hextype);
// int writehex(int hex, char hextype);

#endif