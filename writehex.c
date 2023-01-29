/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writehex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:13:58 by aeastman          #+#    #+#             */
/*   Updated: 2023/01/29 12:14:22 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writehex(int hex, char hextype)
{
	int	write_len;

	write_len = 0;
	if (hex >= 16)
	{
		write_len += writehex(hex / 16, hextype);
		write_len += writehex(hex % 16, hextype);
	}
	else
	{
		if (hex <= 9)
		write_len += writechar(hex + '0');
		else
		{
			if (hextype == 'x')
			{
				write_len += writechar((hex - 10) + 'a');
			}
			else if (hextype == 'X')
			{
				write_len += writechar((hex - 10) + 'A');
			}
		}
	}
	return (write_len);
}

int	writehexrouter(int hex, char hextype)
{
	int	write_len;

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
