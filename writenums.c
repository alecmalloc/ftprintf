/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:13:55 by aeastman          #+#    #+#             */
/*   Updated: 2023/01/29 12:14:24 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while(num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int	num)
{
	char *str;
	int len;

	len = num_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int	num)
{
	char *str;
	int len;

	len = num_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	writeint(int num)
{
	int		write_len;
	char	*str;

	write_len = 0;
	if (num == 0)
		write_len += write(1, "0", 1);
	else if (num == -2147483648)
		write_len += write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			num *= -1;
			write_len = write(1, "-", 1);
		}
		str = ft_itoa(num);
		write_len += writestr(str);
		free(str);
	}
	return (write_len);
}


int	writeuint(unsigned	int num)
{	
	int write_len;
	char *str;

	write_len = 0;
	if (num == 0)
		write_len = write(1, "0", 1);
	else
	{
		str = ft_uitoa(num);
		write_len += writestr(str);
		free(str);
	}
	return (write_len);
}
