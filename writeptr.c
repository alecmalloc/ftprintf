/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:13:58 by aeastman          #+#    #+#             */
/*   Updated: 2023/01/29 12:14:22 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writeptr(unsigned long long ptr)
{
	int	write_len;

	write_len = 0;
	if (ptr >= 16)
	{
		write_len += writeptr(ptr / 16);
		write_len += writeptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			write_len += writechar(ptr + '0');
		else
			write_len += writechar(ptr - 10 + 'a');
	}
	return (write_len);
}

int	writeptrrouter(unsigned long long ptr)
{
	int	write_len;

	write_len = 0;
	write_len += write(1, "0x", 2);
	if (ptr == 0)
		write_len += write(1, "0", 1);
	else
		write_len += writeptr(ptr);
	return (write_len);
}
