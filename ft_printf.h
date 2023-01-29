/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:14:07 by aeastman          #+#    #+#             */
/*   Updated: 2023/01/29 13:38:16 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	writepercent(void);
int	writeuint(unsigned int num);
int writeint(int num);
int	writelargeint(int num);
int	writechar(int c);
int	writestr(char *str);
int	writehexrouter(int hex, char hextype);
int	writehex(int hex, char hextype);
int	ft_printf(const char *input, ...);
int	writeptrrouter(unsigned long long ptr);

#endif
