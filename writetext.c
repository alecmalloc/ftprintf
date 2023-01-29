/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writetext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:13:14 by aeastman          #+#    #+#             */
/*   Updated: 2023/01/29 13:35:09 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writechar(int c)
{
	return (write(1, &c, 1));
}

int	writestr(char *str)
{
	int	i;
	int	write_len;

	i = 0;
	write_len = 0;
	while (str[i] != 0)
	{
		write_len += write(1, &str[i], 1);
		i++;
	}
	return (write_len);
}
