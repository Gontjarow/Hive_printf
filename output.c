/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:31:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/19 19:17:29 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_str(const char *arg, t_flag flag)
{
	int		written = 0;
	char	padder = ' ';
	int		len = ft_strlen(arg);

	if (flag.width > 0)
	{
		if (len >= flag.width)
			flag.width = 0;
		else
			flag.width -= len;
		if (flag.pad & PAD_ZERO)
			padder = '0';
	}
	if (!(flag.pad & PAD_RIGHT))
	{
		while (flag.width > 0)
		{
			putchar(padder);
			++written;
		}
	}
	ft_putstr(arg);
	written += len;
	while (flag.width > 0)
	{
		putchar(padder);
		++written;
	}
	return (written);
}

int	output_int(int arg, t_flag flag);

int	output_uint(unsigned int arg, t_flag flag);
